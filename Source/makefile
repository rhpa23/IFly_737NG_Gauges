# makefile
# Copyright (c) 2000 Microsoft Corporation.  All rights reserved.

INCDIR	= ..\inc
LIBDIR  = ..\lib
DESTDIR	= ..\Debug
INCS	= -I$(INCDIR)
LIBS	= user32.lib gdi32.lib kernel32.lib $(LIBDIR)\FSUIPC_User.lib $(LIBDIR)\fmodex_vc.lib

!IFDEF DEBUG

C_FLAGS	= /Z7
L_FLAGS	= /DEBUG

!ELSE

C_FLAGS	=
L_FLAGS	=

!ENDIF


goal:	IFLY_NG_GAUGE_PLUGIN.gau


IFLY_NG_GAUGE_PLUGIN.obj:	$(INCDIR)\gauges.h				\
		IFLY_NG_GAUGE_PLUGIN.c				\
		..\Header\SDK_FS.h					\
		..\Header\SDK_iFly737NG.h			\
		..\Header\FSUIPC_User.h				\
		..\Header\fmod_codec.h				\
		..\Header\fmod_dsp.h				\
		..\Header\fmod_memoryinfo.h			\
		..\Header\fmod.h					\
		..\Header\fmod_errors.h				\
		..\Header\IFLY_NG_GAUGE_PLUGIN.h    \
		IFLY_NG_GAUGE_PLUGIN.Sound.c		\
		IFLY_NG_GAUGE_PLUGIN.AddIns.c
        cl $(C_FLAGS) -c $(INCS) IFLY_NG_GAUGE_PLUGIN.c

SDK.res:	SDK.rc							\
		..\Header\SDK_FS.h					\
		..\Header\SDK_iFly737NG.h			\
		..\Header\FSUIPC_User.h				\
		..\Header\IFLY_NG_GAUGE_PLUGIN.h    \
		..\Header\fmod_codec.h				\
		..\Header\fmod_dsp.h				\
		..\Header\fmod_memoryinfo.h			\
		..\Header\fmod.h					\
		..\Header\fmod_errors.h
        rc -r $(INCS) SDK.rc

IFLY_NG_GAUGE_PLUGIN.gau:	IFLY_NG_GAUGE_PLUGIN.obj						\
		SDK.res
        link $(L_FLAGS) /dll /out:$(DESTDIR)\IFLY_NG_GAUGE_PLUGIN.gau IFLY_NG_GAUGE_PLUGIN.obj SDK.res $(LIBS)

clean:
	del $(DESTDIR)\*.exp
	del $(DESTDIR)\*.gau
	del $(DESTDIR)\*.lib
	del *.obj
	del *.res

