// DeleteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "od.h"
#include "DeleteDlg.h"


// CDeleteDlg dialog

IMPLEMENT_DYNAMIC(CDeleteDlg, CDialog)

CDeleteDlg::CDeleteDlg(UINT templateID,CWnd *parent)
	: CDialog(templateID, parent)
	, m_ticket(_T(""))
	, m_name(_T(""))
	, m_source(_T(""))
	, m_dest(_T(""))
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ticket);
	DDV_MaxChars(pDX, m_ticket, 10);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDV_MaxChars(pDX, m_name, 40);
	DDX_Text(pDX, IDC_EDIT3, m_source);
	DDV_MaxChars(pDX, m_source, 20);
	DDX_Text(pDX, IDC_EDIT4, m_dest);
	DDV_MaxChars(pDX, m_dest, 20);
}


BEGIN_MESSAGE_MAP(CDeleteDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CDeleteDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CDeleteDlg::OnEnChangeEdit1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CDeleteDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL CDeleteDlg::OnInitDialog()
{
return TRUE;	
}

// CDeleteDlg message handlers

void CDeleteDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	TCHAR query[100],tmpStr[30];
	TCHAR ridtemp[10];
	wsprintf(query,TEXT("SELECT * FROM ticketdata WHERE [ID]=%s"),m_ticket);
	ticketdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	ticketdata.Close();

	
	wsprintf(query,TEXT("SELECT * FROM routedata WHERE ID=%s;"),ticketdata.m_rid);
	routedata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	routedata.Close();
	
	wsprintf(query,TEXT("SELECT * FROM userdata WHERE ID=%s;"),ticketdata.m_uid);
	userdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	userdata.Close();


	m_name=userdata.m_nm;
	m_source=routedata.m_sourcename;
	m_dest=routedata.m_destname;
	UpdateData(FALSE);
}

void CDeleteDlg::OnBnClickedOk()
{
	TCHAR str[50]={'\0'};
	wsprintf(str,TEXT("Are you sure..??!!"));
	int response=MessageBox(str,TEXT("You Sure..!!"),MB_YESNOCANCEL);
	if(response!=IDYES)
	{
		OnOK();
		return;
	}

	UpdateData(TRUE);
	TCHAR query[100],tmpStr[30];
	TCHAR ridtemp[10];
	wsprintf(query,TEXT("SELECT * FROM ticketdata WHERE [ID]=%s"),m_ticket);
	ticketdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	
	ticketdata.Delete();
	
	ticketdata.Close();
	OnOK();
}

void CDeleteDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
