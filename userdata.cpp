// userdata.h : Implementation of the Cuserdata class



// Cuserdata implementation

// code generated on Friday, November 02, 2012, 5:34 PM

#include "stdafx.h"
#include "userdata.h"
IMPLEMENT_DYNAMIC(Cuserdata, CRecordset)

Cuserdata::Cuserdata(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_nm = L"";
	m_mobile = L"";
	m_email = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString Cuserdata::GetDefaultConnect()
{
	return _T("DSN=ticketdb;DBQ=E:\\data\\ticketdb.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cuserdata::GetDefaultSQL()
{
	return _T("[userdata]");
}

void Cuserdata::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[nm]"), m_nm);
	RFX_Text(pFX, _T("[mobile]"), m_mobile);
	RFX_Text(pFX, _T("[email]"), m_email);

}
/////////////////////////////////////////////////////////////////////////////
// Cuserdata diagnostics

#ifdef _DEBUG
void Cuserdata::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cuserdata::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


