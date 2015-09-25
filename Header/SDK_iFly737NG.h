#ifndef _SDK_H_
#define _SDK_H_

#define IFLY737NG_NOT_RUNNING		0
#define IFLY737NG_RUNNING	     	1

//建立SDK的内存共享
TCHAR szNameSDK[]=TEXT("iFly737NG_SDK_FileMappingObject");
HANDLE hMapFileSDK=NULL;
LPCTSTR pBufSDK=NULL;
typedef struct ShareMemorySDK
{
	//
	// This structure gives access to relevant iFly737NG status variables.
	// DO NOT WRITE! THERE ARE READ ONLY!
	//

	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------ Air Systems variables -----------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        AIR_Temperature_Source_Selector_Status;
	double     AIR_MIX_VALVE_Indicator_1_neddle_Status;
	double     AIR_MIX_VALVE_Indicator_2_neddle_Status;
	int        DUCT_OVERHEAT_1_Light_Status;
	int        Air_Temperature_Background;
	int        Air_Temperature_neddle_Status;
	int        DUCT_OVERHEAT_2_Light_Status;
	int        CABIN_Temperature_Selector_1_Selector_Status;
	int        CABIN_Temperature_Selector_2_Selector_Status;
	int        DUAL_BLEED_Light_Status;
	int        RAM_DOOR_FUEL_DOOR_1_Light_Status;
	int        RAM_DOOR_FUEL_DOOR_2_Light_Status;
	int        RecircFan_R_Switch_Status;
	int        Duct_Pressure_R_neddle_Status;
	int        Duct_Pressure_L_neddle_Status;
	int        WingBody_Overheat_Test_Switches_Status;
	int        Pack_1_Switches_Status;
	int        Pack_2_Switches_Status;
	int        Isolation_Valve_Switches_Status;
	int        PACK_TRIP_OFF_1_Light_Status;
	int        PACK_TRIP_OFF_2_Light_Status;
	int        WING_BODY_OVERHEAT_1_Light_Status;
	int        WING_BODY_OVERHEAT_2_Light_Status;
	int        BLEED_TRIP_OFF_1_Light_Status;
	int        BLEED_TRIP_OFF_2_Light_Status;
	int        Engine_1_Bleed_Air_Switches_Status;
	int        APU_Bleed_Air_Switches_Status;
	int        Engine_2_Bleed_Air_Switches_Status;
	int        AUTO_FAIL_Light_Status;
	int        OFF_SCHED_DESCENT_Light_Status;
	int        ALTN_Light_Status;
	int        MANUAL_Light_Status;
	int        Flight_Altitude_Indicator_10000_Status;
	int        Flight_Altitude_Indicator_1000_Status;
	int        Flight_Altitude_Indicator_100_Status;
	int        Flight_Altitude_Indicator_10_Status;
	int        Flight_Altitude_Indicator_1_Status;
	int        Flight_Altitude_Switches_Status;
	int        Landing_Altitude_Indicator_10000_Status;
	int        Landing_Altitude_Indicator_1000_Status;
	int        Landing_Altitude_Indicator_100_Status;
	int        Landing_Altitude_Indicator_10_Status;
	int        Landing_Altitude_Indicator_1_Status;
	int        Landing_Altitude_Switches_Status;
	int        Outflow_VALVE_Position_Indicator_neddle_Status;
	int        Outflow_Valve_Switch_Status;
	int        Pressurization_Mode_Selector_Status;
	int        TRIM_AIR_Switch_Status;
	int        ZONE_TEMP_Light_1_Status;
	int        ZONE_TEMP_Light_2_Status;
	int        ZONE_TEMP_Light_3_Status;
	int        Temperature_Selector_1_Status;
	int        Temperature_Selector_2_Status;
	int        Temperature_Selector_3_Status;
	int        RecircFan_L_Switch_Status;
	int        Equipment_COOLING_SUPPLY_Switch_Status;
	int        Equipment_COOLING_EXHAUST_Switch_Status;
	int        Equip_Cooling_OFF_Light_1_Status;
	int        Equip_Cooling_OFF_Light_2_Status;
	double     CabinAltitude;
	double     CabinDeltaPres;
	int        Altitude_HORN_Cutout_Switches_Status;
	double     CabinAltitudeRate;
	int        High_Altitude_Landing_Switches_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------------- Anti-Ice, Rain variables ----------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        Window_OVERHEAT_Lights_1_Status;
	int        Window_OVERHEAT_Lights_2_Status;
	int        Window_OVERHEAT_Lights_3_Status;
	int        Window_OVERHEAT_Lights_4_Status;
	int        Window_Heat_ON_Lights_1_Status;
	int        Window_Heat_ON_Lights_2_Status;
	int        Window_Heat_ON_Lights_3_Status;
	int        Window_Heat_ON_Lights_4_Status;
	int        Window_Heat_Test_Switch_Status;
	int        Window_Heat_Switch_1_Status;
	int        Window_Heat_Switch_2_Status;
	int        Window_Heat_Switch_3_Status;
	int        Window_Heat_Switch_4_Status;
	int        CAPT_PITOT_Lights_Status;
	int        L_ELEV_PITOT_Lights_Status;
	int        L_ALPHA_VANE_Lights_Status;
	int        TEMP_PROBE_Lights_Status;
	int        FO_PITOT_Lights_Status;
	int        R_ELEV_PITOT_Lights_Status;
	int        R_ALPHA_VANE_Lights_Status;
	int        AUX_PITOT_Lights_Status;
	int        Probe_Heat_Switch_1_Status;
	int        Probe_Heat_Switch_2_Status;
	int        L_VALVE_OPEN_Lights_Status;
	int        ICE_DETECTOR_Lights_Status;
	int        R_VALVE_OPEN_Lights_Status;
	int        COWL_ANTI_ICE_Lights_1_Status;
	int        COWL_VALVE_OPEN_Lights_1_Status;
	int        COWL_ANTI_ICE_Lights_2_Status;
	int        COWL_VALVE_OPEN_Lights_2_Status;
	int        Wing_AntiIce_Switch_Status;
	int        Eng_1_AntiIce_Switch_Status;
	int        Eng_2_AntiIce_Switch_Status;
	int        Wiper_L_Switches_Status;
	int        Wiper_R_Switches_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------------- Automatic Flight variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        Course_1_100_Status;
	int        Course_1_10_Status;
	int        Course_1_1_Status;
	int        AT_Light_Status;
	int        AT_Switches_Status;
	int        SPD_flag_Status;
	int        SPD_100_Status;
	int        SPD_10_Status;
	int        SPD_1_Status;
	int        VNAV_Status;
	int        HDG_100_Status;
	int        HDG_10_Status;
	int        HDG_1_Status;
	int        LNAV_Status;
	int        ALT_10000_Status;
	int        ALT_1000_Status;
	int        ALT_100_Status;
	int        ALT_10_Status;
	int        ALT_1_Status;
	int        VS_flag_Status;
	int        VS_1000_Status;
	int        VS_100_Status;
	int        VS_10_Status;
	int        VS_1_Status;
	int        CMD_A_Status;
	int        CMD_B_Status;
	int        Course_2_100_Status;
	int        Course_2_10_Status;
	int        Course_2_1_Status;
	int        Course_1_Switches_Status;
	int        MA_1_Light_Status;
	int        Changeover_Switches_Status;
	int        MCP_IASMACH_Switches_Status;
	int        SPD_INTV_Switches_Status;
	int        BANK_LIMIT_Selector;
	int        MCP_HEADING_Switches_Status;
	int        VOR_LOC_Status;
	int        MCP_ALTIDUTE_Switches_Status;
	int        ALT_INTV_Switches_Status;
	int        MCP_VERTSPEED_Switches_Status;
	int        CWS_A_Status;
	int        CWS_B_Status;
	int        MA_2_Light_Status;
	int        Course_2_Switches_Status;
	int        FD_left_Switches_Status;
	int        N1_Status;
	int        SPEED_Status;
	int        LVL_CHG_Status;
	int        HDG_SEL_Status;
	int        APP_Status;
	int        ALT_HLD_Status;
	int        VS_Status;
	int        DISENGAGE_Bar_Switches_Status;
	int        FD_right_Switches_Status;
	int        AP_Indicators_Light_Status;
	int        AT_Indicators_Light_Status;
	int        FMC1_Indicators_Light_Status;
	int        FMC2_Indicators_Light_Status;
	int        AP_AT_Test_Switches_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------ Communications variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        VHF_1_Left_Light_status;
	int        VHF_1_Right_Light_status;
	int        VHF_1_Left_num_100_status;
	int        VHF_1_Left_num_10_status;
	int        VHF_1_Left_num_1_status;
	int        VHF_1_Left_num_point1_status;
	int        VHF_1_Left_num_point2_status;
	int        VHF_1_Left_num_point_status;
	int        VHF_1_Switch_status;
	int        VHF_1_Right_num_100_status;
	int        VHF_1_Right_num_10_status;
	int        VHF_1_Right_num_1_status;
	int        VHF_1_Right_num_point1_status;
	int        VHF_1_Right_num_point2_status;
	int        VHF_1_Right_num_point_status;
	int        VHF_1_Test_Switches_status;
	int        VHF_2_Left_Light_status;
	int        VHF_2_Right_Light_status;
	int        VHF_2_Left_num_100_status;
	int        VHF_2_Left_num_10_status;
	int        VHF_2_Left_num_1_status;
	int        VHF_2_Left_num_point1_status;
	int        VHF_2_Left_num_point2_status;
	int        VHF_2_Left_num_point_status;
	int        VHF_2_Switch_status;
	int        VHF_2_Right_num_100_status;
	int        VHF_2_Right_num_10_status;
	int        VHF_2_Right_num_1_status;
	int        VHF_2_Right_num_point1_status;
	int        VHF_2_Right_num_point2_status;
	int        VHF_2_Right_num_point_status;
	int        VHF_2_Test_Switches_status;
	int        ATR_1_Offside_Tuning_Light_status;
	int        VHF_1_Left_num_point__status;
	int        VHF_1_Right_num_point__status;
	int        Radio_Tuning_Panel_1_OFF_status;
	int        ATR_1_NAV1_Switches_Status;
	int        ATR_1_NAV2_Switches_Status;
	int        ATR_1_ADF1_Switches_Status;
	int        ATR_1_ADF2_Switches_Status;
	int        ATR_1_COMM1_Switches_Status;
	int        ATR_1_COMM2_Switches_Status;
	int        ATR_2_Offside_Tuning_Light_status;
	int        VHF_2_Left_num_point__status;
	int        VHF_2_Right_num_point__status;
	int        Radio_Tuning_Panel_2_OFF_status;
	int        ATR_2_NAV1_Switches_Status;
	int        ATR_2_NAV2_Switches_Status;
	int        ATR_2_ADF1_Switches_Status;
	int        ATR_2_ADF2_Switches_Status;
	int        ATR_2_COMM1_Switches_Status;
	int        ATR_2_COMM2_Switches_Status;
	int        ATR_3_Offside_Tuning_Light_status;
	int        VHF_3_Left_num_point__status;
	int        VHF_3_Right_num_point__status;
	int        Radio_Tuning_Panel_3_OFF_status;
	int        ATR_3_NAV1_Switches_Status;
	int        ATR_3_NAV2_Switches_Status;
	int        ATR_3_ADF1_Switches_Status;
	int        ATR_3_ADF2_Switches_Status;
	int        ATR_3_COMM1_Switches_Status;
	int        ATR_3_COMM2_Switches_Status;
	int        VHF_3_Test_Switches_status;
	int        ACP_1_Transmitter_01_Switches_Status;
	int        ACP_1_Transmitter_02_Switches_Status;
	int        ACP_1_Transmitter_03_Switches_Status;
	int        ACP_1_Transmitter_04_Switches_Status;
	int        ACP_1_Transmitter_05_Switches_Status;
	int        ACP_1_Transmitter_06_Switches_Status;
	int        ACP_1_Transmitter_07_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_01_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_02_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_03_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_04_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_05_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_06_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_07_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_08_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_09_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_10_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_11_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_12_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_13_Switches_Status;
	int        ACP_1_Push_to_Talk_Switches_Status;
	int        ACP_1_MASK_Switches_Status;
	int        ACP_1_Filter_Switches_Status;
	int        ACP_1_AltNorm_Switches_Status;
	int        ACP_2_Transmitter_01_Switches_Status;
	int        ACP_2_Transmitter_02_Switches_Status;
	int        ACP_2_Transmitter_03_Switches_Status;
	int        ACP_2_Transmitter_04_Switches_Status;
	int        ACP_2_Transmitter_05_Switches_Status;
	int        ACP_2_Transmitter_06_Switches_Status;
	int        ACP_2_Transmitter_07_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_01_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_02_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_03_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_04_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_05_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_06_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_07_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_08_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_13_Switches_Status;
	int        ACP_2_Push_to_Talk_Switches_Status;
	int        ACP_2_MASK_Switches_Status;
	int        ACP_2_Filter_Switches_Status;
	int        ACP_2_AltNorm_Switches_Status;
	int        ACP_3_Transmitter_01_Switches_Status;
	int        ACP_3_Transmitter_02_Switches_Status;
	int        ACP_3_Transmitter_03_Switches_Status;
	int        ACP_3_Transmitter_04_Switches_Status;
	int        ACP_3_Transmitter_05_Switches_Status;
	int        ACP_3_Transmitter_06_Switches_Status;
	int        ACP_3_Transmitter_07_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_01_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_02_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_03_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_04_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_05_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_06_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_07_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_08_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_13_Switches_Status;
	int        ACP_3_Push_to_Talk_Switches_Status;
	int        ACP_3_MASK_Switches_Status;
	int        ACP_3_Filter_Switches_Status;
	int        ACP_3_AltNorm_Switches_Status;
	int        ACP_1_Transmitter_08_Switches_Status;
	int        ACP_1_Transmitter_09_Switches_Status;
	int        ACP_1_Transmitter_10_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_14_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_15_Switches_Status;
	int        ACP_1_Receiver_Volume_Controls_16_Switches_Status;
	int        ACP_2_Transmitter_08_Switches_Status;
	int        ACP_2_Transmitter_09_Switches_Status;
	int        ACP_2_Transmitter_10_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_14_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_15_Switches_Status;
	int        ACP_2_Receiver_Volume_Controls_16_Switches_Status;
	int        ACP_3_Transmitter_08_Switches_Status;
	int        ACP_3_Transmitter_09_Switches_Status;
	int        ACP_3_Transmitter_10_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_14_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_15_Switches_Status;
	int        ACP_3_Receiver_Volume_Controls_16_Switches_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Electrical variables ----------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        DC_AMPS_minus_Status;
	int        DC_AMPS_10_Status;
	int        DC_AMPS_1_Status;
	int        CPS_FREQ_100_Status;
	int        CPS_FREQ_10_Status;
	int        CPS_FREQ_1_Status;
	int        DC_VOLTS_10_Status;
	int        DC_VOLTS_1_Status;
	int        AC_AMPS_100_Status;
	int        AC_AMPS_10_Status;
	int        AC_AMPS_1_Status;
	int        AC_VOLTS_100_Status;
	int        AC_VOLTS_10_Status;
	int        AC_VOLTS_1_Status;
	int        BAT_DISCHARGE_Light_Status;
	int        TR_UNIT_Light_Status;
	int        ELEC_Light_Status;
	int        DC_Meters_Selector_Status;
	int        AC_Meters_Selector_Status;
	int        Battery_Switch_Status;
	int        CAB_UTIL_Switch_Status;
	int        STANDBY_PWR_OFF_Light_Status;
	int        ENG_1_DRIVE_Light_Status;
	int        ENG_2_DRIVE_Light_Status;
	int        STANDBY_POWER_Switch_Status;
	int        Generator_1_Drive_Disconnect_Switch_Status;
	int        Generator_2_Drive_Disconnect_Switch_Status;
	int        GRD_POWER_AVAILABLE_Light_Status;
	int        Ground_Power_Switches_Status;
	int        Bus_Transfer_Switches_Status;
	int        ENG_1_TRANSFER_BUS_OFF_Light_Status;
	int        ENG_2_TRANSFER_BUS_OFF_Light_Status;
	int        ENG_1_SOURCE_OFF_Light_Status;
	int        ENG_2_SOURCE_OFF_Light_Status;
	int        ENG_1_GEN_OFF_BUS_Light_Status;
	int        ENG_2_GEN_OFF_BUS_Light_Status;
	int        APU_GEN_OFF_BUS_Light_Status;
	int        ENG_1_Generator_Switches_Status;
	int        APU_Generator_1_Switches_Status;
	int        APU_Generator_2_Switches_Status;
	int        ENG_2_Generator_Switches_Status;
	int        IFE_PASS_SEAT_Switches_Status;
	int        Battery_mode;
	int        STANDBY_POWER_mode;
	int        Bus_Transfer_mode;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Engines, APU variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        N1_Set_Status;
	double     ENG1_N1_set;
	double     ENG2_N1_set;
	int        SPD_Ref_Status;
	int        Fuel_Flow_Status;
	int        MFD_ENG_Status;
	int        MFD_SYS_Status;
	int        Ignition_Select_Switches_Status;
	int        Engine_1_Start_Switch_Status;
	int        Engine_2_Start_Switch_Status;
	int        REVERSER_1_Light_Status;
	int        REVERSER_2_Light_Status;
	int        ENGINE_CONTROL_1_Light_Status;
	int        ENGINE_CONTROL_2_Light_Status;
	int        EEC_1_Switch_Status;
	int        EEC_2_Switch_Status;
	int        Engine_1_Start_Levers_Status;
	int        Engine_2_Start_Levers_Status;
	int        APU_Switches_Status;
	int        MAINT_Light_Status;
	int        LOW_OIL_PRESSURE_Light_Status;
	int        FAULT_Light_Status;
	int        OVER_SPEED_Light_Status;
	double     APU_EGT;
	int        APU_Status;
	int        EEC_1_Mode;
	int        EEC_2_Mode;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------- Fire Protection variables ------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        OVHT_DET_1_Switches_Status;
	int        ENG1_OVERHEAT_Light_Status;
	int        Fire_Test_Switches_Status;
	int        Engine_1_Fire_Switches_Status;
	int        WHEEL_WELL_Light_Status;
	int        OverheatDetector_FAULT_Light_Status;
	int        APU_DET_INOP_Light_Status;
	int        APU_BOTTLE_DISCHARGE_Light_Status;
	int        APU_Fire_Switches_Status;
	int        OVHT_DET_2_Switches_Status;
	int        ENG2_OVERHEAT_Light_Status;
	int        L_BOTTLE_DISCHARGE_Light_Status;
	int        R_BOTTLE_DISCHARGE_Light_Status;
	int        Engine_2_Fire_Switches_Status;
	int        EXT_Test_Switches_Status;
	int        Extinguisher_Test_Light_Status;
	int        Cargo_Fire_Test_Light_Status;
	int        DET_Select_1_Switch_Status;
	int        DET_Select_2_Switch_Status;
	int        DETECTOR_FAULT_Light_Status;
	int        Cargo_Fire_Test_Switch_Status;
	int        FWD_Cargo_FIRE_Switch_Status;
	int        AFT_Cargo_FIRE_Switch_Status;
	int        CARGO_FIRE_Discharge_Switch_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------ Flight Controls variables -------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        Flight_Control_A_Switches_Status;
	int        Flight_Control_B_Switches_Status;
	int        LOW_QUANTITY_Light_Status;
	int        LOW_PRESSURE_BACKUP_Light_Status;
	int        LOW_PRESSURE_A_Light_Status;
	int        LOW_PRESSURE_B_Light_Status;
	int        Altn_Flap_Master_Switches_Status;
	int        Altn_Flap_Switches_Status;
	int        Spoiler_A_Switches_Status;
	int        Spoiler_B_Switches_Status;
	int        YAW_DAMPER_Light_Status;
	int        Yaw_Damper_Switches_Status;
	int        FEEL_DIFF_PRESS_Light_Status;
	int        SPEED_TRIM_FAIL_Light_Status;
	int        MACH_TRIM_FAIL_Light_Status;
	int        AUTO_SLAT_FAIL_Light_Status;
	int        STBY_RUD_ON_Light_Status;
	double     Stabilizer_Trim_Indicator_pos;
	int        Stabilizer_Trim_Switch_Status;
	int        Stab_Trim_Main_Elect_Switch_Status;
	int        Stab_Trim_Auto_Pilot_Switch_Status;
	double     Yaw_Damper_Indicator_pos;
	int        AILERON_Trim_Switches_status;
	int        RUDDER_Trim_Switches_status;
	int        Spoiler_Lever_Status;
	int        SPEED_BRAKE_ARMED_Light_Status;
	int        SPEED_BRAKE_DO_NOT_ARM_Light_Status;
	int        SPEEDBRAKES_EXTENDED_Light_Status;
	int        FLAP_status;
	int        FLAP_LOAD_RELIEF_Light_Status;
	double     TE_FLAPS_Status;
	int        LE_FLAPS_TRANSIT_Light_Status;
	int        LE_FLAPS_EXT_Light_Status;
	int        Slat_Left_Light_Status;
	int        Flap_Left_Light_Status;
	int        LE_Devices_TEST_Switch_Status;
	int        Flap_Right_Light_Status;
	int        Slat_Right_Light_Status;
	int        Flight_Control_A_mode;
	int        Flight_Control_B_mode;
	int        Spoiler_A_mode;
	int        Spoiler_B_mode;
	int        Stab_Trim_Auto_Pilot_mode;
	int        Stab_Trim_Main_Elect_mode;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ----------------------- Flight Instruments, Displays variables -------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        HUD_RWY_Light_Status;
	int        HUD_GS_Light_Status;
	int        HUD_FAULT_Light_Status;
	int        HUD_CLR_Light_Status;
	int        HUD_ACT_Mode_Status;
	int        HUD_STBY_Mode_Status;
	int        HUD_ACT_Mode;
	int        HUD_STBY_Mode;
	int        HUD_Runway_Length_Flag_Status;
	int        HUD_Runway_Length_10000_Status;
	int        HUD_Runway_Length_1000_Status;
	int        HUD_Runway_Length_100_Status;
	int        HUD_Runway_Length_10_Status;
	int        HUD_Runway_Length_1_Status;
	int        HUD_Runway_Length_Unit_Status;
	int        HUD_Runway_GS_Flag_Status;
	int        HUD_Runway_GS_0_Status;
	int        HUD_Runway_GS_point_Status;
	int        HUD_Runway_GS_point1_Status;
	int        HUD_Runway_GS_point2_Status;
	int        HUD_Runway_GS_Unit_Status;
	int        HUD_TEST_Light_Status;
	int        HUD_Annunciator_AIII_Light_Status;
	int        HUD_Annunciator_RO_Light_Status;
	int        HUD_Annunciator_TO_Light_Status;
	int        HUD_Annunciator_NOAIII_Light_Status;
	int        HUD_Annunciator_ROCTN_Light_Status;
	int        HUD_Annunciator_TOCTN_Light_Status;
	int        HUD_Annunciator_FLARE_Light_Status;
	int        HUD_Annunciator_ROARM_Light_Status;
	int        HUD_Annunciator_APCH_Light_Status;
	int        HUD_Annunciator_TOWARN_Light_Status;
	int        HUD_Annunciator_FAIL_Light_Status;
	int        Baro_Select_status;
	int        CAPT_BARO_RADIO_status;
	int        CAPT_VORADF_L_status;
	int        CAPT_ND_Mode_status;
	int        CAPT_ND_Range_status;
	int        CAPT_VORADF_R_status;
	int        FO_BARO_RADIO_status;
	int        FO_VORADF_L_status;
	int        FO_ND_Mode_status;
	int        FO_ND_Range_status;
	int        FO_VORADF_R_status;
	int        CAPT_MTRS;
	int        CAPT_FPV;
	int        CAPT_TFC;
	int        CAPT_ND_WXR;
	int        CAPT_ND_STA;
	int        CAPT_ND_WPT;
	int        CAPT_ND_ARPT;
	int        CAPT_ND_DATA;
	int        CAPT_ND_POS;
	int        CAPT_full_compass_rose;
	int        FO_MTRS;
	int        FO_FPV;
	int        FO_TFC;
	int        FO_ND_WXR;
	int        FO_ND_STA;
	int        FO_ND_WPT;
	int        FO_ND_ARPT;
	int        FO_ND_DATA;
	int        FO_ND_POS;
	int        FO_full_compass_rose;
	int        BARO_DH;
	int        RADIO_DH;
	int        Barometric_Standard_Switch;
	int        Source_Switches_Status;
	int        Control_Panel_Switches_Status;
	int        Display_Select_Background;
	int        Main_Panel_DU_CAPT_Switches_Status;
	int        Lower_DU_Switches_Status;
	int        Main_Panel_DU_FO_Switches_Status;
	int        CAPT_PFD_BrightValue;
	int        CAPT_ND_BrightValue;
	int        LOWER_DU_BrightValue;
	int        UPPER_DU_BrightValue;
	int        FO_ND_BrightValue;
	int        FO_PFD_BrightValue;
	int        Baro_switch_Status;
	int        RMI_Selector_Left_Status;
	int        RMI_Selector_Right_Status;
	double     RMI_Compass_Status;
	double     RMI_Pointer_Right_Status;
	double     RMI_Pointer_Left_Status;
	int        CAPT_Chronograph_Switch_Status;
	int        CAPT_Date_Switch_Status;
	int        CAPT_Chronograph_needle;
	int        CAPT_GMT_Colon_Status;
	int        CAPT_GMT_1000_Status;
	int        CAPT_GMT_100_Status;
	int        CAPT_GMT_10_Status;
	int        CAPT_GMT_1_Status;
	int        CAPT_ET_CHR_Colon_Status;
	int        CAPT_ET_CHR_1000_Status;
	int        CAPT_ET_CHR_100_Status;
	int        CAPT_ET_CHR_10_Status;
	int        CAPT_ET_CHR_1_Status;
	int        CAPT_ET_Status;
	int        CAPT_Clock_Set_Status;
	int        FO_Chronograph_Switch_Status;
	int        FO_Date_Switch_Status;
	int        FO_Chronograph_needle;
	int        FO_GMT_Colon_Status;
	int        FO_GMT_1000_Status;
	int        FO_GMT_100_Status;
	int        FO_GMT_10_Status;
	int        FO_GMT_1_Status;
	int        FO_ET_CHR_Colon_Status;
	int        FO_ET_CHR_1000_Status;
	int        FO_ET_CHR_100_Status;
	int        FO_ET_CHR_10_Status;
	int        FO_ET_CHR_1_Status;
	int        FO_ET_Status;
	int        FO_Clock_Set_Status;
	int        Approach_Selector_Status;
	int        Caging_Control_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------- Flight Management, Navigation variables -------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        VHF_NAV_Switches_Status;
	int        IRS_Switches_Status;
	int        FMC_Switches_Status;
	int        IRS_Window_L_1_status;
	int        IRS_Window_L_2_status;
	int        IRS_Window_L_3_status;
	int        IRS_Window_L_4_status;
	int        IRS_Window_L_5_status;
	int        IRS_Window_L_6_status;
	int        IRS_Window_R_1_status;
	int        IRS_Window_R_2_status;
	int        IRS_Window_R_3_status;
	int        IRS_Window_R_4_status;
	int        IRS_Window_R_5_status;
	int        IRS_Window_R_6_status;
	int        IRS_Window_R_7_status;
	int        IRS_Window_L_point_1_status;
	int        IRS_Window_L_point_2_status;
	int        IRS_Window_L_point_3_status;
	int        IRS_Window_R_point_1_status;
	int        IRS_Window_R_point_2_status;
	int        IRS_Window_R_point_3_status;
	int        DSPL_SEL_Switches_Status;
	int        SYS_DSPL_Switches_Status;
	int        IRS_KB_ENT_Light_status;
	int        IRS_KB_CLR_Light_status;
	int        GPS_Light_Status;
	int        ALIGN_1_Light_Status;
	int        ON_DC_1_Light_Status;
	int        ALIGN_2_Light_Status;
	int        ON_DC_2_Light_Status;
	int        FAULT_1_Light_Status;
	int        DC_FAIL_1_Light_Status;
	int        FAULT_2_Light_Status;
	int        DC_FAIL_2_Light_Status;
	int        IRS_1_Switches_Status;
	int        IRS_2_Switches_Status;
	int        ADF_1_Left_num_point_Status;
	int        ADF_1_Left_num_point1_Status;
	int        ADF_1_Left_num_1_Status;
	int        ADF_1_Left_num_10_Status;
	int        ADF_1_Left_num_100_Status;
	int        ADF_1_Left_num_1000_Status;
	int        ADF_1_Switches_Status;
	int        ADF_1_Right_num_point_Status;
	int        ADF_1_Right_num_point1_Status;
	int        ADF_1_Right_num_1_Status;
	int        ADF_1_Right_num_10_Status;
	int        ADF_1_Right_num_100_Status;
	int        ADF_1_Right_num_1000_Status;
	int        ADF_1_Mode_Switches_Status;
	int        ADF_1_Tone_Switches_Status;
	int        ADF_2_Left_num_point_Status;
	int        ADF_2_Left_num_point1_Status;
	int        ADF_2_Left_num_1_Status;
	int        ADF_2_Left_num_10_Status;
	int        ADF_2_Left_num_100_Status;
	int        ADF_2_Left_num_1000_Status;
	int        ADF_2_Switches_Status;
	int        ADF_2_Right_num_point_Status;
	int        ADF_2_Right_num_point1_Status;
	int        ADF_2_Right_num_1_Status;
	int        ADF_2_Right_num_10_Status;
	int        ADF_2_Right_num_100_Status;
	int        ADF_2_Right_num_1000_Status;
	int        ADF_2_Mode_Switches_Status;
	int        ADF_2_Tone_Switches_Status;
	int        NAV_1_Test_Switches_Status;
	int        NAV_1_Left_num_100_status;
	int        NAV_1_Left_num_10_status;
	int        NAV_1_Left_num_1_status;
	int        NAV_1_Left_num_point1_status;
	int        NAV_1_Left_num_point2_status;
	int        NAV_1_Left_num_point_status;
	int        NAV_1_Right_num_100_status;
	int        NAV_1_Right_num_10_status;
	int        NAV_1_Right_num_1_status;
	int        NAV_1_Right_num_point1_status;
	int        NAV_1_Right_num_point2_status;
	int        NAV_1_Right_num_point_status;
	int        NAV_2_Test_Switches_Status;
	int        NAV_2_Left_num_100_status;
	int        NAV_2_Left_num_10_status;
	int        NAV_2_Left_num_1_status;
	int        NAV_2_Left_num_point1_status;
	int        NAV_2_Left_num_point2_status;
	int        NAV_2_Left_num_point_status;
	int        NAV_2_Right_num_100_status;
	int        NAV_2_Right_num_10_status;
	int        NAV_2_Right_num_1_status;
	int        NAV_2_Right_num_point1_status;
	int        NAV_2_Right_num_point2_status;
	int        NAV_2_Right_num_point_status;
	int        Transponder_Mode_Switches_Status;
	int        Transponder_1000_Status;
	int        Transponder_100_Status;
	int        Transponder_10_Status;
	int        Transponder_1_Status;
	int        Transponder_Fail_Light_Status;
	int        Transponder_ATC_Switches_Status;
	int        Transponder_IDENT_Switches_Status;
	int        Transponder_ALT_Switches_Status;

	double     Plane_Heading;
	double     Plane_Track;
	double     Plane_Location_Lat;
	double     Plane_Location_Lon;
	double     GPS_coordinate_Lat;
	double     GPS_coordinate_Lon;
	double     IRU_1_coordinate_Lat;
	double     IRU_1_coordinate_Lon;
	double     IRU_2_coordinate_Lat;
	double     IRU_2_coordinate_Lon;
	double     RADIO_coordinate_Lat;
	double     RADIO_coordinate_Lon;
	double     IRU_1_Alignment_Timer;
	double     IRU_2_Alignment_Timer;
	int        Plane_Coord_Source;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------------ Fuel variables ------------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        ENG_VALVE_CLOSED_Light_1_Status;
	int        SPAR_VALVE_CLOSED_Light_1_Status;
	double     FUEL_TEMP;
	int        ENG_VALVE_CLOSED_Light_2_Status;
	int        SPAR_VALVE_CLOSED_Light_2_Status;
	int        FILTER_BYPASS_Light_1_Status;
	int        VALVE_OPEN_Light_Status;
	int        FILTER_BYPASS_Light_2_Status;
	int        Fuel_Crossfeed_Selector_Status;
	int        LOW_PRESSURE_Light_CENTER_L_Status;
	int        LOW_PRESSURE_Light_CENTER_R_Status;
	int        Fuel_CENTER_L_Switch_Status;
	int        Fuel_CENTER_R_Switch_Status;
	int        LOW_PRESSURE_Light_L_AFT_Status;
	int        LOW_PRESSURE_Light_L_FWD_Status;
	int        LOW_PRESSURE_Light_R_FWD_Status;
	int        LOW_PRESSURE_Light_R_AFT_Status;
	int        Fuel_L_AFT_Switch_Status;
	int        Fuel_L_FWD_Switch_Status;
	int        Fuel_R_FWD_Switch_Status;
	int        Fuel_R_AFT_Switch_Status;
	int        Auxiliary_Fuel_FWD_10000_Status;
	int        Auxiliary_Fuel_FWD_1000_Status;
	int        Auxiliary_Fuel_FWD_100_Status;
	int        Auxiliary_Fuel_FWD_10_Status;
	int        Auxiliary_Fuel_FWD_1_Status;
	int        Auxiliary_Fuel_AFT_10000_Status;
	int        Auxiliary_Fuel_AFT_1000_Status;
	int        Auxiliary_Fuel_AFT_100_Status;
	int        Auxiliary_Fuel_AFT_10_Status;
	int        Auxiliary_Fuel_AFT_1_Status;
	int        Auxiliary_Fuel_background;
	int        Auxiliary_Fuel_Transfer_1_Switches_Status;
	int        Auxiliary_Fuel_Transfer_2_Switches_Status;
	int        Auxiliary_Fuel_Transfer_3_Switches_Status;
	int        Auxiliary_Fuel_Transfer_4_Switches_Status;
	int        Auxiliary_Fuel_Bleed_Air_1_Switches_Status;
	int        Auxiliary_Fuel_Bleed_Air_2_Switches_Status;
	int        Auxiliary_Fuel_Ground_Tranfer_Switches_Status;
	int        Auxiliary_Fuel_Ground_Tranfer_mode;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// --------------------------------- Hydraulics variables ---------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        ELEC_2_HYD_OVERHEAT_Light_Status;
	int        ELEC_1_HYD_OVERHEAT_Light_Status;
	int        ENG_1_HYD_LOW_PRESSURE_Light_Status;
	int        ELEC_2_HYD_LOW_PRESSURE_Light_Status;
	int        ELEC_1_HYD_LOW_PRESSURE_Light_Status;
	int        ENG_2_HYD_LOW_PRESSURE_Light_Status;
	int        ENG_1_HYD_Switches_Status;
	int        ELEC_2_HYD_Switches_Status;
	int        ELEC_1_HYD_Switches_Status;
	int        ENG_2_HYD_Switches_Status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Landing Gear variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        NOSE_GEAR_RedLight_Status;
	int        NOSE_GEAR_GreenLight_Status;
	int        LEFT_GEAR_RedLight_Status;
	int        LEFT_GEAR_GreenLight_Status;
	int        RIGHT_GEAR_RedLight_Status;
	int        RIGHT_GEAR_GreenLight_Status;
	int        Gear_Lever_Status;
	int        AUTO_BRAKE_DISARM_Light_Status;
	int        Autobrake_Switches_Status;
	int        ANTISKID_INOP_Light_Status;
	int        Parking_Brake_Lever_Status;
	int        Parking_Brake_Light_Status;
	double     Hydraulic_Brake_Pressure_status;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------- Warning Systems variables ------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        Fire_Warning_Light_Status;
	int        Master_Caution_Light_Status;
	int        Warning_FLT_CONT_Light_Status;
	int        Warning_IRS_Light_Status;
	int        Warning_FUEL_Light_Status;
	int        Warning_ELEC_Light_Status;
	int        Warning_APU_Light_Status;
	int        Warning_OVHT_Light_Status;
	int        Warning_ANTIICE_Light_Status;
	int        Warning_HYD_Light_Status;
	int        Warning_DOORS_Light_Status;
	int        Warning_ENG_Light_Status;
	int        Warning_OVERHEAD_Light_Status;
	int        Warning_AIR_COND_Light_Status;
	int        PSEU_Light_Status;
	int        TAKEOFF_CONFIG_Light_Status;
	int        CABIN_ALTITUDE_Light_Status;
	int        Landing_Gear_Warning_Cutout_Switches_Status;
	int        GPWS_INOP_Light_Status;
	int        GPWS_Test_Switches_Status;
	int        Flap_Inhibit_Switches_Status;
	int        Gear_Inhibit_Switches_Status;
	int        Terr_Inhibit_Switches_Status;
	int        GS_Inhibit_Switch_Status;
	int        Flap_Inhibit_mode;
	int        Gear_Inhibit_mode;
	int        Terr_Inhibit_mode;


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Miscellaneous variables -------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int        NOT_ARMED_Light_Status;
	int        Emergency_Light_Status;
	double     Oxygen_Pressure;
	int        PASS_OXY_ON_Light_Status;
	int        Oxygen_Switch_Status;
	int        Runway_Turnoff_Light_Status;
	int        Landing_Light_Status;
	int        Taxi_Light_Status;
	int        Logo_Light_Status;
	int        Position_Light_Status;
	int        Anti_Collision_Light_Status;
	int        Wing_Light_Status;
	int        Panel_Light_Status;
	int        Yoke_100_Status;
	int        Yoke_10_Status;
	int        Yoke_1_Status;
	int        EQUIP_Light_Status;
	int        FWD_ENTRY_Light_Status;
	int        LEFT_OVERWING_Light_Status;
	int        AFT_ENTRY_Light_Status;
	int        FWD_SERVICE_Light_Status;
	int        RIGHT_OVERWING_Light_Status;
	int        AFT_SERVICE_Light_Status;
	int        FWD_CARGO_Light_Status;
	int        AFT_CARGO_Light_Status;
	int        LEFT_FWD_OVERWING_Light_Status;
	int        LEFT_AFT_OVERWING_Light_Status;
	int        RIGHT_FWD_OVERWING_Light_Status;
	int        RIGHT_AFT_OVERWING_Light_Status;
	int        LEFT_MID_EXIT_Light_Status;
	int        RIGHT_MID_EXIT_Light_Status;
	int        AIRSTAIR_Light_Status;
	int        No_Smoking_Switches_Status;
	int        Fasten_Belts_Switches_Status;

//--------------------New for FS2Crew--------------------
	int        TO_FLAP;//-1: invalid
	int        Verf_flap;//-1: invalid
	int        Verf_speed;//-1: invalid
	double     V1;//-1: invalid
	double     Vr;//-1: invalid
	int        Landing_Altitude_Status_OverheadPanel;//-10000: invalid
	int        Landing_Altitude_Status_FMC;//-10000: invalid
	int        Altitude_Window;
	BOOL       Engine_1_CanNotStart;//1: insufficient duct pressure to start engine
	BOOL       Engine_2_CanNotStart;//1: insufficient duct pressure to start engine
	int        transition_altitude;
	BOOL       Engine_1_Start_Valve_Pos;//0:OFF;1:ON
	BOOL       Engine_2_Start_Valve_Pos;//0:OFF;1:ON
	BOOL       IS_FMC_PREFLIGHT_COMPLETED;
	int        UNITstyle;//0：Metric；1：US style
	double     FUEL_TANK_CENTER_val;
	double     FUEL_TANK_1_val;
	double     FUEL_TANK_2_val;
	int	       IRU_1_STATUE;//0:not align; 1:during align; 2: have aligned; 3: ATT mode
	int        IRU_2_STATUE;//0:not align; 1:during align; 2: have aligned; 3: ATT mode
	BOOL       TopOfClimb_Avail;
	double     TopOfClimb_Coord_Lat;//latitude of T/C
	double     TopOfClimb_Coord_Lon;//longitude of T/C
	double     TopOfClimb_Coord_DTG;//DTG from present position to the T/C
	double     TopOfClimb_Coord_ETA;//ETA to the T/C
	double     TopOfClimb_Coord_Fuel;//predicted fuel remaining at the T/C
	BOOL       TopOfDescent_Avail;
	double     TopOfDescent_Coord_Lat;//latitude of T/D
	double     TopOfDescent_Coord_Lon;//longitude of T/D
	double     TopOfDescent_Coord_DTG;//DTG from present position to the T/D
	double     TopOfDescent_Coord_ETA;//ETA to the T/D
	double     TopOfDescent_Coord_Fuel;//predicted fuel remaining at the T/D
	BOOL       EndOfDescent_Avail;
	double     EndOfDescent_Coord_Lat;//latitude of E/D
	double     EndOfDescent_Coord_Lon;//longitude of E/D
	double     EndOfDescent_Coord_DTG;//DTG from present position to the E/D
	double     EndOfDescent_Coord_ETA;//ETA to the E/D
	double     EndOfDescent_Coord_Fuel;//predicted fuel remaining at the E/D
	BOOL       StepClimb_Avail;
	double     StepClimb_Coord_Lat;//latitude of S/C
	double     StepClimb_Coord_Lon;//longitude of S/C
	double     StepClimb_Coord_DTG;//DTG from present position to the S/C
	double     StepClimb_Coord_ETA;//ETA to the S/C
	double     StepClimb_Coord_Fuel;//predicted fuel remaining at the S/C
	BOOL       DestinationAirport_Avail;
	double     DestinationAirport_Coord_Lat;//latitude of Destination Airport
	double     DestinationAirport_Coord_Lon;//longitude of Destination Airport
	double     DestinationAirport_Coord_DTG;//DTG from present position to the Destination Airport
	double     DestinationAirport_Coord_ETA;//ETA to the Destination Airport
	double     DestinationAirport_Coord_Fuel;//predicted fuel remaining at the Destination Airport
	int        Lower_DU_Status;//0:blank；1:ENG；2:SYS
	TCHAR      FLT_NO[15];//the same as display at CDU page
	int        FlightNumber;//only the number of FLT_NO string
	int        Autothrottle_Mode;//0:NULL;1:N1;2:GA;3:RETARD;4:FMC SPD;5:MCP SPD;6:THR HLD;7:ARM
	int        Autopilot_Mode;//0:NULL;1:CMD;2:FD;3:SINGLE CH
	int        Autopilot_PitchMode;//0:NULL;1:TO/GA;2:V/S;3:ALT ACQ;4:ALT HOLD;5:VNAV SPD;6:VNAV PTH;7:MCP SPD;8:G/S;9:FLARE;10:VNAV ALT
	int        Autopilot_PitchModeArmed;//0:NULL;1:G/S;2:V/S;3:G/S V/S;4:FLARE
	int        Autopilot_BankMode;//0:NULL;1:HDG SEL;2:VOR/LOC;3:LNAV
	int        Autopilot_BankModeArmed;//0:NULL;1:VOR/LOC
	int        Autopilot_CWSR;//0:NULL;1:CWS R
	int        Autopilot_CWSP;//0:NULL;1:CWS P
	int        AircraftVariant;//1:737-600; 2:737-700; 3:737-700C; 4:737-700ER; 5:737-800; 6:737-900; 7:737-900ER; 8:737-BBJ1; 9:737-BBJ2; 10:737-BBJ3; 
	int        EngineVariant;//1:18K; 2:20K; 3:22K; 4:24K; 5:26K; 6:27K
	int        GPWS_Callout_2500_Enable;//0:disable;1:able
	int        GPWS_Callout_1000_Enable;//0:disable;1:able
	int        GPWS_Callout_500_Enable;//0:disable;1:able
	int        GPWS_Callout_400_Enable;//0:disable;1:able
	int        GPWS_Callout_300_Enable;//0:disable;1:able
	int        GPWS_Callout_200_Enable;//0:disable;1:able
	int        GPWS_Callout_100_Enable;//0:disable;1:able
	int        GPWS_Callout_50_Enable;//0:disable;1:able
	int        GPWS_Callout_40_Enable;//0:disable;1:able
	int        GPWS_Callout_30_Enable;//0:disable;1:able
	int        GPWS_Callout_20_Enable;//0:disable;1:able
	int        GPWS_Callout_10_Enable;//0:disable;1:able
	int        GPWS_Callout_V1_Enable;//0:disable;1:able
	int        Attendant_Call_Clicked;
	int        Ground_Call_Clicked;


	int IFLY737NG_STATE;
}
ShareMemorySDK, *pShareMemorySDK;
#define BUF_SIZE_SDK (sizeof(struct ShareMemorySDK)+1)
ShareMemorySDK ShareMemSDK;
pShareMemorySDK pShareMemSDK=&ShareMemSDK;




//建立SDK的内存共享
TCHAR szNameSDK1[]=TEXT("iFly737NG_SDK1_FileMappingObject");
HANDLE hMapFileSDK1=NULL;
LPCTSTR pBufSDK1=NULL;
typedef struct ShareMemorySDK1
{
	//
	// This structure gives access to relevant iFly737NG status variables.
	//
	int IFLY737NG_KEY_COMMAND;
}
ShareMemorySDK1, *pShareMemorySDK1;
#define BUF_SIZE_SDK1 (sizeof(struct ShareMemorySDK1)+1)
ShareMemorySDK1 ShareMemSDK1;
pShareMemorySDK1 pShareMemSDK1=&ShareMemSDK1;




#endif