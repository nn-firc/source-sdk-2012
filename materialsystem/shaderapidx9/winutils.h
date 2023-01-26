//================ Copyright (c) 1996-2009 Valve Corporation. All Rights Reserved. =================
//
//
//
//==================================================================================================
#ifndef WINUTILS_H
#define WINUTILS_H

#ifdef TOGLES
#include "togles/rendermechanism.h"
#else
#include "togl/rendermechanism.h"
#endif

#if !defined(_WIN32)

	void Sleep( unsigned int ms );
	bool IsIconic( VD3DHWND hWnd );
	BOOL ClientToScreen( VD3DHWND hWnd, LPPOINT pPoint );
	void* GetCurrentThread();
	void SetThreadAffinityMask( void *hThread, int nMask );
	void GlobalMemoryStatus( MEMORYSTATUS *pOut );
#endif

#endif // WINUTILS_H
