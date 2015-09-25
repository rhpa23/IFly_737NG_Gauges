// IFLY_NG_GAUGE_PLUGIN.Sound.c
// Copyright (c) 2011 Aragão.  All rights reserved.
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "../Header/fmod.h"
#include "../Header/fmod_errors.h"

#include "../Header/IFLY_NG_GAUGE_PLUGIN.h"

 FMOD_CHANNEL     *channel = 0;
 FMOD_SYSTEM      *systemFMOD;

void FSAPI gaugecall(PGAUGEHDR pgauge, int service_id, UINT32 extra_data)
{
	// Added to call all lookups and the license check routine //
	switch(service_id)
	{
	case PANEL_SERVICE_CONNECT_TO_WINDOW:
	{ // Add here, all inicializations and conections.
		OpenLinkFsUIPC();
		InitializeIFlyVariables();
		break;
	}
	case PANEL_SERVICE_PRE_INSTALL:
		InitializeIFlyVariables();
		break;
	case PANEL_SERVICE_PRE_UPDATE:
		break;
	case PANEL_SERVICE_DISCONNECT:
	{ // free resouces and close conections.
		FSUIPC_Close();

		/*
        Shut down
		*/
		//FMOD_Sound_Release(sound);
		FMOD_System_Close(systemFMOD);
		FMOD_System_Release(systemFMOD);
		break;
	}
	case PANEL_SERVICE_PRE_KILL:
	break;
	}
}


//	Set up gauge header
char sound_gauge_name[]		= GAUGE_NAME;
extern PELEMENT_HEADER		sound_list;
extern MOUSERECT			sound_mouse_rect[];

GAUGE_HEADER_FS700(GAUGE_W, sound_gauge_name, &sound_list, \
						sound_mouse_rect, gaugecall, 0, 0, 0);


/////////////////////////////////////////////////////////////////////////////
FAILURE_RECORD	sound_fail[] =
{
	{FAIL_GAUGE_ATTITUDE, FAIL_ACTION_NONE},
	{FAIL_NONE, FAIL_ACTION_NONE}
};


/////////////////////////////////////////////////////////////////////////////
MAKE_SPRITE
(
	sound_sprite_outer,
	NULL,
	NULL,
	sound_fail,
	IMAGE_USE_TRANSPARENCY|IMAGE_BILINEAR_COLOR,
	0,
	16, 13,
	137,134,
	1.05, 1.05,
	MODULE_VAR_NONE, NULL, 0,
	MODULE_VAR_NONE, NULL, 0,
	ATTITUDE_INDICATOR_BANK_DEGREES, NULL, -1
)

PELEMENT_HEADER		sound_sprite_outer_list[] =
{
	&sound_sprite_outer.header,
	NULL
};


////////////////////////////ProcessIFlyFunctions/////////////////////////////////////////////////

void PlayLoopAudio(char* filename)
{
    FMOD_SOUND       *sound;
    FMOD_RESULT       result;
    int               key;
    unsigned int      version;

    // Create a System object and initialize.
	if (systemFMOD == NULL)
	{
		result = FMOD_System_Create(&systemFMOD);
		result = FMOD_System_Init(systemFMOD, 1, FMOD_INIT_NORMAL, NULL);
	}

	result = FMOD_System_CreateStream(systemFMOD, filename, FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, 0, &sound);

    //Play the sound.
    result = FMOD_System_PlaySound(systemFMOD, FMOD_CHANNEL_FREE, sound, 0, &channel);
}

void StopAudio() /* Stop the sound if is playing.*/
{
	if (systemFMOD != NULL)
	{
		BOOL isPlaying = FALSE;
		FMOD_Channel_IsPlaying(channel, &isPlaying);
		if (isPlaying)
			FMOD_Channel_Stop(channel);
	}
}


void ProcessIFlyFunctions() // process the functions 
{
	if (CheckCockpitView() == 1)
	{
		hMapFileSDK = OpenFileMapping(
			   FILE_MAP_READ,				// read/write access
			   FALSE,						// do not inherit the name
			   szNameSDK);					// name of mapping object 

		if (hMapFileSDK != NULL) 
		{ 
			pBufSDK = (LPTSTR)MapViewOfFile(hMapFileSDK,    // handle to mapping object
					   FILE_MAP_READ,						// read/write permission
					   0,
					   0,
					   BUF_SIZE_SDK);
		}
	
		if(pBufSDK)
		{
			CopyMemory((PVOID)pShareMemSDK, pBufSDK, sizeof(struct ShareMemorySDK));
			if (pShareMemSDK->DC_AMPS_minus_Status == 10)  // if the batery has power
			{
				// Check if Wiper Left Status has change
				if (CurrentWiperLeftStatus != pShareMemSDK->Wiper_L_Switches_Status)
				{
					// Play the fuck wav sound
					if (pShareMemSDK->Wiper_L_Switches_Status == 1) // Int
					{
						StopAudio();
						PlayLoopAudio(".\\iFly\\737NG\\Sound\\Wiper1.wav");
					} else if (pShareMemSDK->Wiper_L_Switches_Status == 2) // Low
					{
						StopAudio();
						PlayLoopAudio(".\\iFly\\737NG\\Sound\\Wiper2.wav");
					} else if (pShareMemSDK->Wiper_L_Switches_Status == 3) // High
					{
						StopAudio();
						PlayLoopAudio(".\\iFly\\737NG\\Sound\\Wiper3.wav");
					} 
					else
					{
						StopAudio();
						/*PlaySound(NULL, NULL, SND_ASYNC);*/
					}
					CurrentWiperLeftStatus = pShareMemSDK->Wiper_L_Switches_Status;
				}

				// Check if Engine 1 Start Levers Status has change
				if (CurrentEngine1StartLeversStatus != pShareMemSDK->Engine_1_Start_Levers_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\StartLeversClick.wav", NULL, SND_ASYNC);
					/*PlaySound(".\\iFly\\737NG\\Sound\\StartLeversClick.wav", NULL, SND_ASYNC);*/
					CurrentEngine1StartLeversStatus = pShareMemSDK->Engine_1_Start_Levers_Status;
				}

				// Check if Engine 2 Start Levers Status has change
				if (CurrentEngine2StartLeversStatus != pShareMemSDK->Engine_2_Start_Levers_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\StartLeversClick.wav", NULL, SND_ASYNC);
					CurrentEngine2StartLeversStatus = pShareMemSDK->Engine_2_Start_Levers_Status;
				}

				// Check if Landing Light Status has change
				if (CurrentLandingLightStatus != pShareMemSDK->Landing_Light_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\LandingLightClick.wav", NULL, SND_ASYNC);
					CurrentLandingLightStatus = pShareMemSDK->Landing_Light_Status;
				}

				// Check if Taxi Light Status has change
				if (CurrentTaxiLightStatus != pShareMemSDK->Taxi_Light_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-click.wav", NULL, SND_ASYNC);
					CurrentTaxiLightStatus = pShareMemSDK->Taxi_Light_Status;
				}
				
				// Check if Panel Light Status has change
				if (CurrentPanelLightStatus != pShareMemSDK->Panel_Light_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-click.wav", NULL, SND_ASYNC);
					CurrentPanelLightStatus = pShareMemSDK->Panel_Light_Status;
				}

				// Check if Logo Light Status has change
				if (CurrentLogoLightStatus != pShareMemSDK->Logo_Light_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-click.wav", NULL, SND_ASYNC);
					CurrentLogoLightStatus = pShareMemSDK->Logo_Light_Status;
				}

				// Check if Anti Collision Light Status has change
				if (CurrentAntiCollisionLightStatus != pShareMemSDK->Anti_Collision_Light_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-click.wav", NULL, SND_ASYNC);
					CurrentAntiCollisionLightStatus = pShareMemSDK->Anti_Collision_Light_Status;
				}

				// Check if Wing Light Status has change
				if (CurrentWingLightStatus != pShareMemSDK->Wing_Light_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-click.wav", NULL, SND_ASYNC);
					CurrentWingLightStatus = pShareMemSDK->Wing_Light_Status;
				}

				// Check if MCP IAS/MACH Switches Status has change
				if (CurrentMCPIASMACHSwitchesStatus != pShareMemSDK->MCP_IASMACH_Switches_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentMCPIASMACHSwitchesStatus = pShareMemSDK->MCP_IASMACH_Switches_Status;
				}

				// Check if MCP HEADING Switches Status has change
				if (CurrentMCPHEADINGSwitchesStatus != pShareMemSDK->MCP_HEADING_Switches_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentMCPHEADINGSwitchesStatus = pShareMemSDK->MCP_HEADING_Switches_Status;
				}

				// Check if MCP ALTIDUTE Switches Status has change
				if (CurrentMCPALTIDUTESwitchesStatus != pShareMemSDK->MCP_ALTIDUTE_Switches_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentMCPALTIDUTESwitchesStatus = pShareMemSDK->MCP_ALTIDUTE_Switches_Status;
				}

				// Check if MCP VERT SPEED Switches Status has change
				if (CurrentMCPVERTSPEEDSwitchesStatus != pShareMemSDK->MCP_VERTSPEED_Switches_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentMCPVERTSPEEDSwitchesStatus = pShareMemSDK->MCP_VERTSPEED_Switches_Status;
				}

				// Check if Course 1 Switches Status has change
				if (CurrentCourse1SwitchesStatus != pShareMemSDK->Course_1_Switches_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentCourse1SwitchesStatus = pShareMemSDK->Course_1_Switches_Status;
				}

				// Check if Course 2 Switches Status has change
				if (CurrentCourse2SwitchesStatus != pShareMemSDK->Course_2_Switches_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentCourse2SwitchesStatus = pShareMemSDK->Course_2_Switches_Status;
				}

				// Check if Parking Brake Lever Status has change
				if (CurrentParkingBrakeLeverStatus != pShareMemSDK->Parking_Brake_Lever_Status)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\ParkingBrakes.wav", NULL, SND_ASYNC);
					CurrentParkingBrakeLeverStatus = pShareMemSDK->Parking_Brake_Lever_Status;
				}

				// Check if BANK LIMIT Selector has change
				if (CurrentBANKLIMITSelector != pShareMemSDK->BANK_LIMIT_Selector)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-click.wav", NULL, SND_ASYNC);
					CurrentBANKLIMITSelector = pShareMemSDK->BANK_LIMIT_Selector;
				}

				// Check if Toga Push has change
				if (CurrentTogaPushSelector != pShareMemSDK->Autopilot_PitchMode)  
				{
					if (pShareMemSDK->Autopilot_PitchMode == 1)     //0:NULL;1:TO/GA;2:V/S;3:ALT ACQ;4:ALT HOLD;5:VNAV SPD;6:VNAV PTH;7:MCP SPD;8:G/S;9:FLARE;10:VNAV ALT
						PlaySound(".\\iFly\\737NG\\Sound\\TogaPush.wav", NULL, SND_ASYNC);

					CurrentTogaPushSelector = pShareMemSDK->Autopilot_PitchMode;
				}

				// Check if Pack 1 Switches has change
				if (CurrentPack1SwitchesStatus != pShareMemSDK->Pack_1_Switches_Status)  
				{
					if (pShareMemSDK->Pack_1_Switches_Status == 1 && (pShareMemSDK->Duct_Pressure_L_neddle_Status > 5 || pShareMemSDK->Duct_Pressure_R_neddle_Status > 5))  //1:auto
						PlaySound(".\\iFly\\737NG\\Sound\\PacksAuto.wav", NULL, SND_ASYNC);

					if (pShareMemSDK->Pack_1_Switches_Status == 0 && (pShareMemSDK->Duct_Pressure_L_neddle_Status > 5 || pShareMemSDK->Duct_Pressure_R_neddle_Status > 5))  //1:auto
						PlaySound(".\\iFly\\737NG\\Sound\\PacksOff.wav", NULL, SND_ASYNC);

					CurrentPack1SwitchesStatus = pShareMemSDK->Pack_1_Switches_Status;
				}

				// Check if Pack 2 Switches has change
				if (CurrentPack2SwitchesStatus != pShareMemSDK->Pack_2_Switches_Status)  
				{
					if (pShareMemSDK->Pack_2_Switches_Status == 1 && (pShareMemSDK->Duct_Pressure_L_neddle_Status > 5 || pShareMemSDK->Duct_Pressure_R_neddle_Status > 5)) //1:auto
						PlaySound(".\\iFly\\737NG\\Sound\\PacksAuto.wav", NULL, SND_ASYNC);

					if (pShareMemSDK->Pack_2_Switches_Status == 0 && (pShareMemSDK->Duct_Pressure_L_neddle_Status > 5 || pShareMemSDK->Duct_Pressure_R_neddle_Status > 5))  //1:auto
						PlaySound(".\\iFly\\737NG\\Sound\\PacksOff.wav", NULL, SND_ASYNC);

					CurrentPack2SwitchesStatus = pShareMemSDK->Pack_2_Switches_Status;
				}

				// Check if NAV1 Switches Status has change
				if (Current1NAV1SwitchesStatus != pShareMemSDK->NAV_1_Right_num_point2_status + pShareMemSDK->NAV_1_Right_num_1_status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);

					Current1NAV1SwitchesStatus = pShareMemSDK->NAV_1_Right_num_point2_status + pShareMemSDK->NAV_1_Right_num_1_status;
				}

				// Check if NAV2 Switches Status has change
				if (Current1NAV2SwitchesStatus != pShareMemSDK->NAV_2_Right_num_point2_status + pShareMemSDK->NAV_2_Right_num_1_status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);

					Current1NAV2SwitchesStatus = pShareMemSDK->NAV_2_Right_num_point2_status + pShareMemSDK->NAV_2_Right_num_1_status;
				}

				// Check if Transponder Status has change
				if (CurrentTransponderStatus != pShareMemSDK->Transponder_1000_Status + pShareMemSDK->Transponder_100_Status  + pShareMemSDK->Transponder_10_Status + pShareMemSDK->Transponder_1_Status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);

					CurrentTransponderStatus = pShareMemSDK->Transponder_1000_Status + pShareMemSDK->Transponder_100_Status  + pShareMemSDK->Transponder_10_Status + pShareMemSDK->Transponder_1_Status;
				}

				// Check if VHF1 Left Switches Status has change
				if (CurrentVHF1LeftStatus != pShareMemSDK->VHF_1_Left_num_1_status + pShareMemSDK->VHF_1_Left_num_point2_status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentVHF1LeftStatus = pShareMemSDK->VHF_1_Left_num_1_status + pShareMemSDK->VHF_1_Left_num_point2_status;
				}

				// Check if VHF1 Right Switches Status has change
				if (CurrentVHF1RightStatus != pShareMemSDK->VHF_1_Right_num_1_status + pShareMemSDK->VHF_1_Right_num_point2_status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentVHF1RightStatus = pShareMemSDK->VHF_1_Right_num_1_status + pShareMemSDK->VHF_1_Right_num_point2_status;
				}

				// Check if VHF2 Left Switches Status has change
				if (CurrentVHF2LeftStatus != pShareMemSDK->VHF_2_Left_num_1_status + pShareMemSDK->VHF_2_Left_num_point2_status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentVHF2LeftStatus = pShareMemSDK->VHF_2_Left_num_1_status + pShareMemSDK->VHF_2_Left_num_point2_status;
				}

				// Check if VHF2 Right Switches Status has change
				if (CurrentVHF2RightStatus != pShareMemSDK->VHF_2_Right_num_1_status + pShareMemSDK->VHF_2_Right_num_point2_status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentVHF2RightStatus = pShareMemSDK->VHF_2_Right_num_1_status + pShareMemSDK->VHF_2_Right_num_point2_status;
				}

				// Check if ADF1 Left Switches Status has change
				if (CurrentADF1LeftStatus != pShareMemSDK->ADF_1_Left_num_point1_Status + pShareMemSDK->ADF_1_Left_num_1_Status + pShareMemSDK->ADF_1_Left_num_10_Status + pShareMemSDK->ADF_1_Left_num_100_Status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentADF1LeftStatus = pShareMemSDK->ADF_1_Left_num_point1_Status + pShareMemSDK->ADF_1_Left_num_1_Status + pShareMemSDK->ADF_1_Left_num_10_Status + pShareMemSDK->ADF_1_Left_num_100_Status;
				}

				// Check if ADF1 Right Switches Status has change
				if (CurrentADF1RightStatus != pShareMemSDK->ADF_1_Right_num_point1_Status + pShareMemSDK->ADF_1_Right_num_1_Status + pShareMemSDK->ADF_1_Right_num_10_Status + pShareMemSDK->ADF_1_Right_num_100_Status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentADF1RightStatus = pShareMemSDK->ADF_1_Right_num_point1_Status + pShareMemSDK->ADF_1_Right_num_1_Status + pShareMemSDK->ADF_1_Right_num_10_Status + pShareMemSDK->ADF_1_Right_num_100_Status;
				}

				// Check if ADF2 Left Switches Status has change
				if (CurrentADF2LeftStatus != pShareMemSDK->ADF_2_Left_num_point1_Status + pShareMemSDK->ADF_2_Left_num_1_Status + pShareMemSDK->ADF_2_Left_num_10_Status + pShareMemSDK->ADF_2_Left_num_100_Status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentADF2LeftStatus = pShareMemSDK->ADF_2_Left_num_point1_Status + pShareMemSDK->ADF_2_Left_num_1_Status + pShareMemSDK->ADF_2_Left_num_10_Status + pShareMemSDK->ADF_2_Left_num_100_Status;
				}

				// Check if ADF2 Right Switches Status has change
				if (CurrentADF2RightStatus != pShareMemSDK->ADF_2_Right_num_point1_Status + pShareMemSDK->ADF_2_Right_num_1_Status + pShareMemSDK->ADF_2_Right_num_10_Status + pShareMemSDK->ADF_2_Right_num_100_Status)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentADF2RightStatus = pShareMemSDK->ADF_2_Right_num_point1_Status + pShareMemSDK->ADF_2_Right_num_1_Status + pShareMemSDK->ADF_2_Right_num_10_Status + pShareMemSDK->ADF_2_Right_num_100_Status;
				}

				// Check if Autothrottle Light Status has change
				if (CurrentAutothrottleLightStatus != pShareMemSDK->AT_Switches_Status) 
				{
					if (pShareMemSDK->AT_Switches_Status == 0)
						PlaySound(".\\iFly\\737NG\\Sound\\iFly737NG-switch.wav", NULL, SND_ASYNC);

					CurrentAutothrottleLightStatus = pShareMemSDK->AT_Switches_Status;
				}

				// Check if Speed brake Mode Status has change
				if (CurrentSPEEDBRAKEARMEDStatus != pShareMemSDK->SPEED_BRAKE_ARMED_Light_Status)
				{
					if (pShareMemSDK->Spoiler_Lever_Status <= 25)
						PlaySound(".\\iFly\\737NG\\Sound\\SpeedBrakeArmed.wav", NULL, SND_ASYNC);
					CurrentSPEEDBRAKEARMEDStatus = pShareMemSDK->SPEED_BRAKE_ARMED_Light_Status;
				}

				// Check if BARO Status has change
				if (CurrentBAROStatus  !=  pShareMemSDK->BARO_DH)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentBAROStatus = pShareMemSDK->BARO_DH;
				}
				
				// Check if RADIO Status has change
				if (CurrentRADIOStatus  !=  pShareMemSDK->RADIO_DH)  
				{
					PlaySound(".\\iFly\\737NG\\Sound\\MCP_knob1.wav", NULL, SND_ASYNC);
					CurrentRADIOStatus  =  pShareMemSDK->RADIO_DH;
				}

			}
			else
			{
				// Stop any wav sound
				StopAudio();
				PlaySound(NULL, NULL, SND_ASYNC);
			}
		}	

		UnmapViewOfFile(pBufSDK);
		pBufSDK=NULL;
		CloseHandle(hMapFileSDK);
		hMapFileSDK=NULL;
	}
	else
	{ // the view is not from cockpit
		PlaySound(NULL, NULL, SND_ASYNC);
		StopAudio();
		CurrentWiperLeftStatus = 0;
	}
}


#define	PITCH_LIMIT		43.0		// stop at 43 degrees
FLOAT64	FSAPI	sound_sprite_inner_cb( PELEMENT_SPRITE pelement )
{
	ProcessIFlyFunctions();
	return 0;
}

MAKE_SPRITE
(
	sound_sprite_inner,
	NULL,
	sound_sprite_outer_list,
	sound_fail,
	IMAGE_USE_TRANSPARENCY|IMAGE_BILINEAR_COLOR,
	0,
	55, 53,
	137, 134,
	0.55, 0.55,
	MODULE_VAR_NONE, NULL, 0,
	ATTITUDE_INDICATOR_PITCH_DEGREES, sound_sprite_inner_cb, 2.0,
	ATTITUDE_INDICATOR_BANK_DEGREES, NULL, -1
)

PELEMENT_HEADER		sound_sprite_inner_list[] =
{
	&sound_sprite_inner.header,
	NULL
};


/////////////////////////////////////////////////////////////////////////////
MAKE_STATIC
(
	sound_background,
	NULL,
	sound_sprite_inner_list,
	sound_fail,
	IMAGE_USE_TRANSPARENCY,
	0,
	0,0
)

PELEMENT_HEADER		sound_list	= &sound_background.header;

/////////////////////////////////////////////////////////////////////////////
MOUSE_BEGIN( sound_mouse_rect, HELPID_GAUGE_ATTITUDE_INDICATOR, 0, 0 )
	
MOUSE_END


/////////////////////////////////////////////////////////////////////////////
#undef GAUGE_NAME
#undef GAUGEHDR_VAR_NAME
#undef GAUGE_W

