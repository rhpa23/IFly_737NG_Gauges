short CurrentLandingLightStatus = -1;
short CurrentPanelLightStatus = -1;
short CurrentLogoLightStatus = -1;
short CurrentAntiCollisionLightStatus = -1;
short CurrentWingLightStatus = -1;
short CurrentTaxiLightStatus = -1;

short CurrentEngine1StartLeversStatus = -1;
short CurrentEngine2StartLeversStatus = -1;
short CurrentMCPIASMACHSwitchesStatus = -1;
short CurrentMCPHEADINGSwitchesStatus = -1;
short CurrentMCPALTIDUTESwitchesStatus = -1;
short CurrentMCPVERTSPEEDSwitchesStatus = -1;
short CurrentCourse1SwitchesStatus = -1;
short CurrentCourse2SwitchesStatus = -1;
short CurrentBANKLIMITSelector = -1;
short CurrentParkingBrakeLeverStatus = -1;
short CurrentTogaPushSelector = -1;
short CurrentPack1SwitchesStatus = -1;
short CurrentPack2SwitchesStatus = -1;

int CurrentVHF1LeftStatus = -1;
int CurrentVHF1RightStatus = -1;
int CurrentVHF2LeftStatus = -1;
int CurrentVHF2RightStatus = -1;

int CurrentADF1LeftStatus = -1;
int CurrentADF1RightStatus = -1;
int CurrentADF2LeftStatus = -1;
int CurrentADF2RightStatus = -1;

int Current1NAV1SwitchesStatus = -1;
int Current1NAV2SwitchesStatus = -1;
int CurrentTransponderStatus = -1;
short CurrentBAROStatus  = -1;
short CurrentRADIOStatus  = -1;

short CurrentAutothrottleLightStatus = -1;
short CurrentSPEEDBRAKEARMEDStatus = -1;

short CurrentWiperLeftStatus = 0;


void InitializeIFlyVariables() // Initialize the Variables 
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

		CurrentEngine1StartLeversStatus = pShareMemSDK->Engine_1_Start_Levers_Status;
		CurrentEngine2StartLeversStatus = pShareMemSDK->Engine_2_Start_Levers_Status;
		CurrentLandingLightStatus = pShareMemSDK->Landing_Light_Status;
		CurrentTaxiLightStatus = pShareMemSDK->Taxi_Light_Status;
		CurrentPanelLightStatus = pShareMemSDK->Panel_Light_Status;
		CurrentLogoLightStatus = pShareMemSDK->Logo_Light_Status;
		CurrentAntiCollisionLightStatus = pShareMemSDK->Anti_Collision_Light_Status;
		CurrentWingLightStatus = pShareMemSDK->Wing_Light_Status;
		CurrentMCPIASMACHSwitchesStatus = pShareMemSDK->MCP_IASMACH_Switches_Status;
		CurrentMCPHEADINGSwitchesStatus = pShareMemSDK->MCP_HEADING_Switches_Status;
		CurrentMCPALTIDUTESwitchesStatus = pShareMemSDK->MCP_ALTIDUTE_Switches_Status;
		CurrentMCPVERTSPEEDSwitchesStatus = pShareMemSDK->MCP_VERTSPEED_Switches_Status;
		CurrentCourse1SwitchesStatus = pShareMemSDK->Course_1_Switches_Status;
		CurrentCourse2SwitchesStatus = pShareMemSDK->Course_2_Switches_Status;
		CurrentParkingBrakeLeverStatus = pShareMemSDK->Parking_Brake_Lever_Status;
		CurrentBANKLIMITSelector = pShareMemSDK->BANK_LIMIT_Selector;
		CurrentTogaPushSelector = pShareMemSDK->Autopilot_PitchMode;
		CurrentPack1SwitchesStatus = pShareMemSDK->Pack_1_Switches_Status;
		CurrentPack2SwitchesStatus = pShareMemSDK->Pack_2_Switches_Status;

		Current1NAV1SwitchesStatus = pShareMemSDK->NAV_1_Right_num_point2_status + pShareMemSDK->NAV_1_Right_num_1_status;
		Current1NAV2SwitchesStatus = pShareMemSDK->NAV_2_Right_num_point2_status + pShareMemSDK->NAV_2_Right_num_1_status;

		CurrentTransponderStatus = pShareMemSDK->Transponder_1000_Status + pShareMemSDK->Transponder_100_Status  + pShareMemSDK->Transponder_10_Status + pShareMemSDK->Transponder_1_Status;

		CurrentVHF1RightStatus = pShareMemSDK->VHF_1_Right_num_1_status + pShareMemSDK->VHF_1_Right_num_point2_status;
		CurrentVHF1LeftStatus = pShareMemSDK->VHF_1_Left_num_1_status + pShareMemSDK->VHF_1_Left_num_point2_status;
		CurrentVHF2LeftStatus = pShareMemSDK->VHF_2_Left_num_1_status + pShareMemSDK->VHF_2_Left_num_point2_status;
		CurrentVHF2RightStatus = pShareMemSDK->VHF_2_Right_num_1_status + pShareMemSDK->VHF_2_Right_num_point2_status;

		CurrentADF1LeftStatus = pShareMemSDK->ADF_1_Left_num_point1_Status + pShareMemSDK->ADF_1_Left_num_1_Status + pShareMemSDK->ADF_1_Left_num_10_Status + pShareMemSDK->ADF_1_Left_num_100_Status;
		CurrentADF1RightStatus = pShareMemSDK->ADF_1_Right_num_point1_Status + pShareMemSDK->ADF_1_Right_num_1_Status + pShareMemSDK->ADF_1_Right_num_10_Status + pShareMemSDK->ADF_1_Right_num_100_Status;
		CurrentADF2LeftStatus = pShareMemSDK->ADF_2_Left_num_point1_Status + pShareMemSDK->ADF_2_Left_num_1_Status + pShareMemSDK->ADF_2_Left_num_10_Status + pShareMemSDK->ADF_2_Left_num_100_Status;
		CurrentADF2RightStatus = pShareMemSDK->ADF_2_Right_num_point1_Status + pShareMemSDK->ADF_2_Right_num_1_Status + pShareMemSDK->ADF_2_Right_num_10_Status + pShareMemSDK->ADF_2_Right_num_100_Status;

		CurrentBAROStatus  =  pShareMemSDK->BARO_DH;

		CurrentRADIOStatus  =  pShareMemSDK->RADIO_DH;

		CurrentAutothrottleLightStatus = pShareMemSDK->AT_Switches_Status;

		CurrentSPEEDBRAKEARMEDStatus = pShareMemSDK->SPEED_BRAKE_ARMED_Light_Status;

		CurrentWiperLeftStatus = pShareMemSDK->Wiper_L_Switches_Status;
	}	
	UnmapViewOfFile(pBufSDK);
	pBufSDK=NULL;
	CloseHandle(hMapFileSDK);
	hMapFileSDK=NULL;
}
