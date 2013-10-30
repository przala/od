// routedata.h : Implementation of the Croutedata class



// Croutedata implementation

// code generated on Friday, November 02, 2012, 8:14 PM

#include "stdafx.h"
#include "routedata.h"
IMPLEMENT_DYNAMIC(Croutedata, CRecordset)

Croutedata::Croutedata(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_sourcename = L"";
	m_destname = L"";
	m_time = L"";
	m_maxseat = L"";
	m_busno = L"";
	m_price = 0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString Croutedata::GetDefaultConnect()
{
	return _T("DSN=ticketdb;DBQ=E:\\data\\ticketdb.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Croutedata::GetDefaultSQL()
{
	return _T("[routedata]");
}

void Croutedata::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[sourcename]"), m_sourcename);
	RFX_Text(pFX, _T("[destname]"), m_destname);
	RFX_Text(pFX, _T("[time]"), m_time);
	RFX_Text(pFX, _T("[maxseat]"), m_maxseat);
	RFX_Text(pFX, _T("[busno]"), m_busno);
	RFX_Long(pFX, _T("[price]"), m_price);

}
/////////////////////////////////////////////////////////////////////////////
// Croutedata diagnostics

#ifdef _DEBUG
void Croutedata::AssertValid() const
{
	CRecordset::AssertValid();
}

void Croutedata::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


