// SDK.Attitude.h
// Copyright (c) 2000 Microsoft Corporation.  All rights reserved.
//

#define         VERSION_MAJOR           1
#define         VERSION_MINOR           0
#define         VERSION_BUILD           0

// magic to get the preprocessor to do what we want
#define		lita(arg) #arg
#define		xlita(arg) lita(arg)
#define		cat3(w,x,z) w##.##x##.##z##\000
#define		xcat3(w,x,z) cat3(w,x,z)
#define		VERSION_STRING xlita(xcat3(VERSION_MAJOR,VERSION_MINOR,VERSION_BUILD))

#ifndef		VS_VERSION_INFO
#define		VS_VERSION_INFO		0x0001
#endif


/////////////////////////////////////////////////////////////////////////////
//
// Bitmaps
//
