// IFLY_NG_GAUGE_PLUGIN.AddIns.c
// Copyright (c) 2011 Aragão.  All rights reserved.



//	Set up gauge header
char addins_gauge_name[]		= GAUGE_NAME;
extern PELEMENT_HEADER		addins_list;
extern MOUSERECT			addins_mouse_rect[];

GAUGE_HEADER_FS700(GAUGE_W, addins_gauge_name, &addins_list, \
						addins_mouse_rect, 0, 0, 0, 0);


/////////////////////////////////////////////////////////////////////////////
FAILURE_RECORD	addins_fail[] =
{
	{FAIL_GAUGE_ATTITUDE, FAIL_ACTION_NONE},
	{FAIL_NONE, FAIL_ACTION_NONE}
};


/////////////////////////////////////////////////////////////////////////////
MAKE_SPRITE
(
	addins_sprite_outer,
	NULL,
	NULL,
	addins_fail,
	IMAGE_USE_TRANSPARENCY|IMAGE_BILINEAR_COLOR,
	0,
	16, 13,
	137,134,
	1.05, 1.05,
	MODULE_VAR_NONE, NULL, 0,
	MODULE_VAR_NONE, NULL, 0,
	ATTITUDE_INDICATOR_BANK_DEGREES, NULL, -1
)

PELEMENT_HEADER		addins_sprite_outer_list[] =
{
	&addins_sprite_outer.header,
	NULL
};


////////////////////////////ProcessIFlyAddInsFunctions/////////////////////////////////////////////////
BOOL PauseTODwasUse = FALSE; // flag to define if the pause at top of descent was used once


void ProcessIFlyAddInsFunctions() 
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
			// Check if Top of Descent is Available
			if (pShareMemSDK->TopOfDescent_Avail)
			{
				if (pShareMemSDK->TopOfDescent_Coord_DTG <= 8 && !PauseTODwasUse)
				{
					PlaySound(".\\iFly\\737NG\\Sound\\sign.wav", NULL, SND_ASYNC);
					// pause FS 
					 PauseFS();
					 PauseTODwasUse = TRUE;
				}
			}
			else
			{
				PauseTODwasUse = FALSE;
			}
		}
	}	

	UnmapViewOfFile(pBufSDK);
	pBufSDK=NULL;
	CloseHandle(hMapFileSDK);
	hMapFileSDK=NULL;
}


#define	PITCH_LIMIT		43.0		// stop at 43 degrees

FLOAT64	FSAPI	addins_sprite_inner_cb( PELEMENT_SPRITE pelement )
{
	ProcessIFlyAddInsFunctions();
	return 0;
}


MAKE_SPRITE
(
	addins_sprite_inner,
	NULL,
	addins_sprite_outer_list,
	addins_fail,
	IMAGE_USE_TRANSPARENCY|IMAGE_BILINEAR_COLOR,
	0,
	55, 53,
	137, 134,
	0.55, 0.55,
	MODULE_VAR_NONE, NULL, 0,
	ATTITUDE_INDICATOR_PITCH_DEGREES, addins_sprite_inner_cb, 2.0,
	ATTITUDE_INDICATOR_BANK_DEGREES, NULL, -1
)

PELEMENT_HEADER		addins_sprite_inner_list[] =
{
	&addins_sprite_inner.header,
	NULL
};


/////////////////////////////////////////////////////////////////////////////
MAKE_STATIC
(
	addins_background,
	NULL,
	addins_sprite_inner_list,
	addins_fail,
	IMAGE_USE_TRANSPARENCY,
	0,
	0,0
)

PELEMENT_HEADER		addins_list	= &addins_background.header;

/////////////////////////////////////////////////////////////////////////////
MOUSE_BEGIN( addins_mouse_rect, HELPID_GAUGE_ATTITUDE_INDICATOR, 0, 0 )
	
MOUSE_END


/////////////////////////////////////////////////////////////////////////////
#undef GAUGE_NAME
#undef GAUGEHDR_VAR_NAME
#undef GAUGE_W

