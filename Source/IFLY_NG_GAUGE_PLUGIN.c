// SDK.c
// Copyright (c) 2000 Microsoft Corp.  All Rights Reserved

#include "..\inc\gauges.h"

#include "..\Header\SDK_FS.h"


#include "windows.h"
#include <stdio.h>



#include "..\Header\SDK_iFly737NG.h"
//#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include "..\Header\FSUIPC_User.h"

//#include "..\Header\bass.h"
//#include "..\Header\audiere.h"
//using namespace audiere;
// 


DWORD dwResult;  // to use in FSUIPC fuctions

void OpenLinkFsUIPC()  // link with FSUIPC_Open has had an initial
{
	if (FSUIPC_Open(SIM_ANY, &dwResult))
	{
		// Okay, we're linked, and already the FSUIPC_Open has had an initial
		// exchange with FSUIPC to get its version number and to differentiate
		// between FS's.

		// Now to auto-Register with FSUIPC, to save the user of an Unregistered FSUIPC
		// having to Register UIPCHello for us:
		static char chOurKey[] = "IKB3BI67TCHE"; // As obtained from Pete Dowson

		if (FSUIPC_Write(0x8001, 12, chOurKey, &dwResult))
			FSUIPC_Process(&dwResult); // Process the request(s)
	}
}

int CheckCockpitView() // Check if the view is from cockpit or VC
{	
	char chViewType[1];
	BOOL fViewType = TRUE;

//	OpenLinkFsUIPC();

	// I've not checked the reslut of the above -- if it didn't register us,
	// and FSUIPC isn't fully user-Registered, the next request will not
	// return the FS lock time
		
	if (!FSUIPC_Read(0x8320, 1, chViewType, &dwResult) ||
			// If we wanted other reads/writes at the same time, we could put them here
			!FSUIPC_Process(&dwResult)) // Process the request(s)
		fViewType = FALSE;

	// Now check if the view is from cockpit
	if (fViewType)
	{
		if (chViewType[0] == 1 | chViewType[0] == 2)  // 1=cockpit, 2=virtual cockpit, 3=tower, 4=spot, 5=top down
		{
			return 1 ;
		}
	}		

//	FSUIPC_Close(); // Closing when it wasn't open is okay, so this is safe here
   return 0 ;
}


void PauseFS() // Pause fs
{	
	int chViewType[1];
	chViewType[0] = 1;

//	OpenLinkFsUIPC();

	if (FSUIPC_Write(0x0262, 2, chViewType, &dwResult))
		FSUIPC_Process(&dwResult); // Process the request(s)
}

void PlayAudio(DWORD filename, BOOL repeat)
{
	//BASS_ChannelPlay(filename,repeat);
}

//AudioDevicePtr device(audiere::OpenDevice());
//			  
//int PlayAudio(char* filename, BOOL repeat)
//{
//	if (device) 
//	{
//		OutputStreamPtr stream(OpenSound(device, filename, true));
//		if (stream) {
//			stream->setRepeat(repeat);
//			stream->setVolume(0.5f); // 50% volume
//			stream->play();
//		}
//		else return 0;
//	}
//	else return 0;
//		
//	return 1;
//}

/////////////////////////////////////////////////////////////////////////////
// IFLY_NG_GAUGE_PLUGIN.Sound
/////////////////////////////////////////////////////////////////////////////
#define		GAUGE_NAME			"Sound"
#define		GAUGEHDR_VAR_NAME	gaugehdr_sound
#define		GAUGE_W				100

#include "IFLY_NG_GAUGE_PLUGIN.Sound.c"



/////////////////////////////////////////////////////////////////////////////
// IFLY_NG_GAUGE_PLUGIN.AddIns
/////////////////////////////////////////////////////////////////////////////
#define		GAUGE_NAME			"AddIns"
#define		GAUGEHDR_VAR_NAME	gaugehdr_addins
#define		GAUGE_W				100

#include "IFLY_NG_GAUGE_PLUGIN.AddIns.c"


/////////////////////////////////////////////////////////////////////////////
// Gauge table entries
/////////////////////////////////////////////////////////////////////////////
GAUGE_TABLE_BEGIN()
	GAUGE_TABLE_ENTRY(&gaugehdr_sound)
	GAUGE_TABLE_ENTRY(&gaugehdr_addins)
GAUGE_TABLE_END()


