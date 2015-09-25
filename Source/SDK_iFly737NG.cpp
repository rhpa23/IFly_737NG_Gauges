#include "windows.h"
#include <stdio.h>

#include "..\Header\SDK_iFly737NG.h"


void main()
{
	hMapFileSDK = OpenFileMapping(
           FILE_MAP_READ,   // read/write access
           FALSE,                 // do not inherit the name
           szNameSDK);               // name of mapping object 

	if (hMapFileSDK != NULL) 
	{ 
		pBufSDK = (LPTSTR)MapViewOfFile(hMapFileSDK,    // handle to mapping object
				   FILE_MAP_READ,  // read/write permission
				   0,
				   0,
				   BUF_SIZE_SDK);
	}

	if(pBufSDK)
	{
		CopyMemory((PVOID)pShareMemSDK, pBufSDK, sizeof(struct ShareMemorySDK));
		if(pShareMemSDK->IFLY737NG_STATE==IFLY737NG_RUNNING)
		{
			printf("\nConnected to iFly737NG!\n");
			while(pShareMemSDK->IFLY737NG_STATE==IFLY737NG_RUNNING)
			{
				CopyMemory((PVOID)pShareMemSDK, pBufSDK, sizeof(struct ShareMemorySDK));
				printf("Engine_1_CanNotStart:%d Engine_2_CanNotStart:%d \r", pShareMemSDK->Engine_1_CanNotStart, pShareMemSDK->Engine_2_CanNotStart);
				Sleep(100);
			}
			printf("\nCan't connect to iFly737NG!\n");
		}
	}
	else
		printf("\nCan't connect to iFly737NG!\n");

	UnmapViewOfFile(pBufSDK);
	pBufSDK=NULL;
	CloseHandle(hMapFileSDK);
	hMapFileSDK=NULL;
}