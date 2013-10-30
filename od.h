// od.h : main header file for the PROJECT_NAME application
//

#pragma once

#include <afxdb.h>
#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CodApp:
// See od.cpp for the implementation of this class
//

class CodApp : public CWinApp
{
public:
	CodApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CodApp theApp;