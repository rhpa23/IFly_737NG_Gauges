
#include "..\inc\gauges.h"
#define SOUND_GAUGE_NAME L"DSD_Sound_Gauge.gau"

typedef	BOOL	(*TfGetCurrentMuting)();
typedef	int	(*TfGetFSPausedStatus)();
typedef	int	(*TfGetFSSoundStatus)();
typedef	long	(*TfGetInstanceSoundStatus)( unsigned long psound );
typedef	int	(*TfGetMutingFunctionOn)();
typedef	BOOL	(*TfGetPan)( unsigned long psound, long* pan );
typedef	long	(*TfGetPanVariable)( unsigned long psound );
typedef	int	(*TfGetSimConnectStatus)();
typedef	char*	(*TfGetSoundFileNameA)( unsigned long psound );
typedef	wchar_t*	(*TfGetSoundFileNameW)( unsigned long psound );
typedef	BOOL	(*TfGetVolume) ( unsigned long psound, long* volume );
typedef	long	(*TfGetVolumeVariable)( unsigned long psound );
typedef	int	(*TfIsSoundPlaying)( unsigned long psound );
typedef	unsigned long	(*TfLoadSoundFileA)( char* strFileName );
typedef	unsigned long	(*TfLoadSoundFileW)( wchar_t* strFileName );
typedef	void	(*TfMuteAllSounds)();
typedef	BOOL	(*TfPlaySound)( unsigned long psound, BOOL blooped );
typedef	BOOL	(*TfPlaySound2)( unsigned long psound, BOOL blooped, long volume, long pan );
typedef	BOOL	(*TfPlaySoundOnceA)( char* strFileName );
typedef	BOOL	(*TfPlaySoundOnceW)( wchar_t* strFileName );
typedef	BOOL	(*TfSetPan)( unsigned long psound, long pan );
typedef	BOOL	(*TfSetVolume)( unsigned long psound, long volume );
typedef	void	(*TfStopAllSounds)();
typedef	void	(*TfStopSound)( unsigned long psound, BOOL bResetPosition );
typedef	void	(*TfToggleMutingFunctionOn)();
typedef	void	(*TfUnloadSoundFile)( unsigned long psound );
typedef	void	(*TfUnMuteAllSounds)();

TfGetCurrentMuting GetCurrentMuting;
TfGetFSPausedStatus GetFSPausedStatus;
TfGetFSSoundStatus GetFSSoundStatus;
TfGetInstanceSoundStatus GetInstanceSoundStatus;
TfGetMutingFunctionOn GetMutingFunctionOn;
TfGetPan GetPan;
TfGetPanVariable GetPanVariable;
TfGetSimConnectStatus GetSimConnectStatus;
TfGetSoundFileNameA GetSoundFileNameA;
TfGetSoundFileNameW GetSoundFileNameW;
TfGetVolume GetVolume;
TfGetVolumeVariable GetVolumeVariable;
TfIsSoundPlaying IsSoundPlaying;
TfLoadSoundFileA LoadSoundFileA;
TfLoadSoundFileW LoadSoundFileW;
TfMuteAllSounds MuteAllSounds;
TfPlaySound GaugePlaySound;
TfPlaySound2 GaugePlaySound2;
TfPlaySoundOnceA PlaySoundOnceA;
TfPlaySoundOnceW PlaySoundOnceW;
TfSetPan SetPan;
TfSetVolume SetVolume;
TfStopAllSounds StopAllSounds;
TfStopSound StopSound;
TfToggleMutingFunctionOn ToggleMutingFunctionOn;
TfUnloadSoundFile UnloadSoundFile;
TfUnMuteAllSounds UnMuteAllSounds;

HMODULE MGaugeSound = NULL;

void FSAPI InitializeSoundFunctions()
{
	if ( MGaugeSound == NULL ) MGaugeSound = GetModuleHandle(SOUND_GAUGE_NAME);
	if ( MGaugeSound && !UnMuteAllSounds )
		{
		if ( !GaugePlaySound ) GaugePlaySound = (TfPlaySound)GetProcAddress(MGaugeSound, "fPlaySound");
		if ( !GaugePlaySound2 ) GaugePlaySound2 = (TfPlaySound2)GetProcAddress(MGaugeSound, "fPlaySound2");
		if ( !GetCurrentMuting ) GetCurrentMuting = (TfGetCurrentMuting)GetProcAddress(MGaugeSound, "fGetCurrentMuting");
		if ( !GetFSPausedStatus ) GetFSPausedStatus = (TfGetFSPausedStatus)GetProcAddress(MGaugeSound, "fGetFSPausedStatus");
		if ( !GetFSSoundStatus ) GetFSSoundStatus = (TfGetFSSoundStatus)GetProcAddress(MGaugeSound, "fGetFSSoundStatus");
		if ( !GetInstanceSoundStatus ) GetInstanceSoundStatus = (TfGetInstanceSoundStatus)GetProcAddress(MGaugeSound, "fGetInstanceSoundStatus");
		if ( !GetMutingFunctionOn ) GetMutingFunctionOn = (TfGetMutingFunctionOn)GetProcAddress(MGaugeSound, "fGetMutingFunctionOn");
		if ( !GetPan ) GetPan = (TfGetPan)GetProcAddress(MGaugeSound, "fGetPan");
		if ( !GetPanVariable ) GetPanVariable = (TfGetPanVariable)GetProcAddress(MGaugeSound, "fGetPanVariable");
		if ( !GetSimConnectStatus ) GetSimConnectStatus = (TfGetSimConnectStatus)GetProcAddress(MGaugeSound, "fGetSimConnectStatus");
		if ( !GetSoundFileNameA ) GetSoundFileNameA = (TfGetSoundFileNameA)GetProcAddress(MGaugeSound, "fGetSoundFileNameA");
		if ( !GetSoundFileNameW ) GetSoundFileNameW = (TfGetSoundFileNameW)GetProcAddress(MGaugeSound, "fGetSoundFileNameW");
		if ( !GetVolume ) GetVolume = (TfGetVolume)GetProcAddress(MGaugeSound, "fGetVolume");
		if ( !GetVolumeVariable ) GetVolumeVariable = (TfGetVolumeVariable)GetProcAddress(MGaugeSound, "fGetVolumeVariable");
		if ( !IsSoundPlaying ) IsSoundPlaying = (TfIsSoundPlaying)GetProcAddress(MGaugeSound, "fIsSoundPlaying");
		if ( !LoadSoundFileA ) LoadSoundFileA = (TfLoadSoundFileA)GetProcAddress(MGaugeSound, "fLoadSoundFileA");
		if ( !LoadSoundFileW ) LoadSoundFileW = (TfLoadSoundFileW)GetProcAddress(MGaugeSound, "fLoadSoundFileW");
		if ( !MuteAllSounds ) MuteAllSounds = (TfMuteAllSounds)GetProcAddress(MGaugeSound, "fMuteAllSounds");
		if ( !PlaySoundOnceA ) PlaySoundOnceA = (TfPlaySoundOnceA)GetProcAddress(MGaugeSound, "fPlaySoundOnceA");
		if ( !PlaySoundOnceW ) PlaySoundOnceW = (TfPlaySoundOnceW)GetProcAddress(MGaugeSound, "fPlaySoundOnceW");
		if ( !SetPan ) SetPan = (TfSetPan)GetProcAddress(MGaugeSound, "fSetPan");
		if ( !SetVolume ) SetVolume = (TfSetVolume)GetProcAddress(MGaugeSound, "fSetVolume");
		if ( !StopAllSounds ) StopAllSounds = (TfStopAllSounds)GetProcAddress(MGaugeSound, "fStopAllSounds");
		if ( !StopSound ) StopSound = (TfStopSound)GetProcAddress(MGaugeSound, "fStopSound");
		if ( !ToggleMutingFunctionOn ) ToggleMutingFunctionOn = (TfToggleMutingFunctionOn)GetProcAddress(MGaugeSound, "fToggleMutingFunctionOn");
		if ( !UnloadSoundFile ) UnloadSoundFile = (TfUnloadSoundFile)GetProcAddress(MGaugeSound, "fUnloadSoundFile");
		if ( !UnMuteAllSounds ) UnMuteAllSounds = (TfUnMuteAllSounds)GetProcAddress(MGaugeSound, "fUnMuteAllSounds");
		}
}

BOOL FSAPI SafeIsSoundPlaying( unsigned long psound )
{
	if ( MGaugeSound && IsSoundPlaying )
		return IsSoundPlaying(psound);
	else return 0;
}

BOOL FSAPI SafeGaugePlaySound( unsigned long psound, BOOL blooped )
{
	if ( MGaugeSound && GaugePlaySound )
		return GaugePlaySound(psound, blooped);
	else return NULL;
}

BOOL FSAPI SafeGaugePlaySound2( unsigned long psound, BOOL blooped, long volume, long pan )
{
	if ( MGaugeSound && GaugePlaySound2 )
		return GaugePlaySound2(psound, blooped, volume, pan);
	else return NULL;
}

BOOL FSAPI SafeGetCurrentMuting()
{
	if ( MGaugeSound && GetCurrentMuting ) return GetCurrentMuting();
	else return NULL;
}

BOOL FSAPI SafeGetFSPausedStatus()
	{
	if ( MGaugeSound && GetFSPausedStatus ) return GetFSPausedStatus();
	else return 0;
	}

BOOL FSAPI SafeGetFSSoundStatus()
	{
	if ( MGaugeSound && GetFSSoundStatus ) return GetFSSoundStatus();
	else return 0;
	}

int FSAPI SafeGetInstanceSoundStatus( unsigned long psound)
{
	if ( MGaugeSound && GetInstanceSoundStatus )
		return GetInstanceSoundStatus(psound);
	else return 0;
}

BOOL FSAPI SafeGetMutingFunctionOn()
	{
	if ( MGaugeSound && GetMutingFunctionOn ) return GetMutingFunctionOn();
	else return 0;
	}

BOOL FSAPI SafeGetPan( unsigned long psound, long* pan )
{
	if ( MGaugeSound && GetPan )
		return GetPan(psound, pan );
	else return FALSE;
}

long FSAPI SafeGetPanVariable( unsigned long psound )
{
	if ( MGaugeSound && GetPanVariable )
		return GetPanVariable( psound );
	else return E_FAIL;
}

BOOL FSAPI SafeGetSimConnectStatus()
	{
	if ( MGaugeSound && GetSimConnectStatus ) return GetSimConnectStatus();
	else return 0;
	}

char* FSAPI SafeGetSoundFileNameA( unsigned long psound )
{
	if ( MGaugeSound && GetSoundFileNameA )
		return GetSoundFileNameA(psound);
	else return NULL;
}

wchar_t* FSAPI SafeGetSoundFileNameW( unsigned long psound )
{
	if ( MGaugeSound && GetSoundFileNameW )
		return GetSoundFileNameW(psound);
	else return NULL;
}

BOOL FSAPI SafeGetVolume ( unsigned long psound, long* volume )
{
	if ( MGaugeSound && GetVolume )
		return GetVolume(psound, volume);
	else return FALSE;
}

long FSAPI SafeGetVolumeVariable( unsigned long psound )
{
	if ( MGaugeSound && GetVolumeVariable )
		return GetVolumeVariable( psound );
	else return E_FAIL;
}

unsigned long FSAPI SafeLoadSoundFileA(char* strFileName)
{
	if ( MGaugeSound && LoadSoundFileA )
		return LoadSoundFileA( strFileName );
	else return NULL;
}

unsigned long FSAPI SafeLoadSoundFileW(wchar_t* strFileName)
{
	if ( MGaugeSound && LoadSoundFileW )
		return LoadSoundFileW( strFileName );
	else return NULL;
}

void FSAPI SafeMuteAllSounds()
{
	if ( MGaugeSound && MuteAllSounds ) MuteAllSounds();
}

BOOL FSAPI SafePlaySoundOnceA(char* strFileName)
{
	if ( MGaugeSound && PlaySoundOnceA ) return PlaySoundOnceA(strFileName);
	else return NULL;
}

BOOL FSAPI SafePlaySoundOnceW(wchar_t* strFileName)
{
	if ( MGaugeSound && PlaySoundOnceW ) return PlaySoundOnceW(strFileName);
	else return NULL;
}

BOOL FSAPI SafeSetPan( unsigned long psound, long pan )
{
	if ( MGaugeSound && SetPan )
		return SetPan(psound, pan);
	else return NULL;
}

BOOL FSAPI SafeSetVolume( unsigned long psound, long volume )
{
	if ( MGaugeSound && SetVolume )
		return SetVolume(psound, volume);
	else return NULL;
}

void FSAPI SafeStopAllSounds()
{
	if ( MGaugeSound && StopAllSounds ) StopAllSounds();
}

void FSAPI SafeStopSound( unsigned long psound, BOOL bResetPosition )
{
	if ( MGaugeSound && StopSound )
		StopSound(psound, bResetPosition);
}

void FSAPI SafeToggleMutingFunctionOn()
	{
	if ( MGaugeSound && ToggleMutingFunctionOn ) ToggleMutingFunctionOn();
	}

void FSAPI SafeUnloadSoundFile( unsigned long psound )
{
	if ( MGaugeSound && UnloadSoundFile ) UnloadSoundFile(psound);
}

void FSAPI SafeUnMuteAllSounds()
{
	if ( MGaugeSound && UnMuteAllSounds ) UnMuteAllSounds();
}


