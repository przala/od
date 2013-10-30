// ticketdata.h : Implementation of the Cticketdata class



// Cticketdata implementation

// code generated on Friday, November 02, 2012, 5:28 PM

#include "stdafx.h"
#include "ticketdata.h"
IMPLEMENT_DYNAMIC(Cticketdata, CRecordset)

Cticketdata::Cticketdata(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_rid = L"";
	m_uid = L"";
	m_noofseat = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString Cticketdata::GetDefaultConnect()
{
	return _T("DSN=ticketdb;DBQ=E:\\data\\ticketdb.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cticketdata::GetDefaultSQL()
{
	return _T("[ticketdata]");
}

void Cticketdata::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[rid]"), m_rid);
	RFX_Text(pFX, _T("[uid]"), m_uid);
	RFX_Text(pFX, _T("[noofseat]"), m_noofseat);

}
/////////////////////////////////////////////////////////////////////////////
// Cticketdata diagnostics

#ifdef _DEBUG
void Cticketdata::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cticketdata::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


