// UpdateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "od.h"
#include "UpdateDlg.h"


// CUpdateDlg dialog

IMPLEMENT_DYNAMIC(CUpdateDlg, CDialog)

CUpdateDlg::CUpdateDlg(UINT dlgID,CWnd *owner)
	: CDialog(dlgID,owner)
	, m_ticket(_T(""))
	, m_name(_T(""))
	, m_contact(_T(""))
	, m_email(_T(""))
	, m_route(_T(""))
	, m_seat(0)
{

}

CUpdateDlg::~CUpdateDlg()
{
}

void CUpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ticket);
	DDV_MaxChars(pDX, m_ticket, 10);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDV_MaxChars(pDX, m_name, 40);
	DDX_Text(pDX, IDC_EDIT3, m_contact);
	DDV_MaxChars(pDX, m_contact, 11);
	DDX_Text(pDX, IDC_EDIT4, m_email);
	DDV_MaxChars(pDX, m_email, 40);
	DDX_CBString(pDX, IDC_COMBO1, m_route);
	DDV_MaxChars(pDX, m_route, 70);
	DDX_CBIndex(pDX, IDC_COMBO3, m_seat);
	DDV_MinMaxInt(pDX, m_seat, 0, 10);
}


BEGIN_MESSAGE_MAP(CUpdateDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CUpdateDlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON2, &CUpdateDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CUpdateDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CUpdateDlg message handlers

BOOL CUpdateDlg::OnInitDialog()
{
	TCHAR str[100];
	int i=0;
	CComboBox *lbptr=(CComboBox *)GetDlgItem(IDC_COMBO1);
	routedata.Open(AFX_DB_USE_DEFAULT_TYPE,_T("SELECT * FROM routedata;"));
	while(!routedata.IsEOF())
	{
		wsprintf(str,TEXT("from:%s to: %s time: %s"),routedata.m_sourcename,routedata.m_destname,routedata.m_time);
		routeId[i]=routedata.m_ID;
		priceArray[i++]=routedata.m_price;
		lbptr->AddString(str);
		routedata.MoveNext();
	}
	routedata.Close();

	lbptr=(CComboBox *)GetDlgItem(IDC_COMBO3);
	for(int i=1;i<11;i++)
	{
		wsprintf(str,TEXT("%d"),i);
		lbptr->AddString(str);
	}

return TRUE;	
}

void CUpdateDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	TCHAR str[100];
	TCHAR query[100];
	//fetching the values from db according to the ticket number entered by user
	wsprintf(query,TEXT("SELECT * FROM ticketdata WHERE [ID]=%s;"),m_ticket);
	ticketdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	ticketdata.Close();
	

	wsprintf(query,TEXT("SELECT * FROM routedata WHERE ID=%s;"),ticketdata.m_rid);
	routedata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	routedata.Close();
	
	wsprintf(query,TEXT("SELECT * FROM userdata WHERE ID=%s;"),ticketdata.m_uid);
	userdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	userdata.Close();

	m_name=userdata.m_nm;
	m_email=userdata.m_email;
	m_contact=userdata.m_mobile;

	UpdateData(0);
	//setting route combobox
	CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_COMBO1);
	ptr->SetCurSel(int(routedata.m_ID-1));
	
	//setting number of seats combo box
	ptr=(CComboBox *)GetDlgItem(IDC_COMBO3);
	int seatIndex=_wtoi(ticketdata.m_noofseat);
	ptr->SetCurSel(seatIndex-1);

}

void CUpdateDlg::OnCbnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
}

void CUpdateDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_COMBO1);
	ptr->SetCurSel(1);
}

void CUpdateDlg::OnBnClickedOk()
{
	//Updating data to database
	UpdateData(TRUE);
	
	TCHAR str[100];
	TCHAR query[100];
	//fetching the values from db according to the ticket number entered by user
	wsprintf(query,TEXT("SELECT * FROM ticketdata WHERE [ID]=%s;"),m_ticket);
	ticketdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	
	

	wsprintf(query,TEXT("SELECT * FROM routedata WHERE ID=%s;"),ticketdata.m_rid);
	routedata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	
	wsprintf(query,TEXT("SELECT * FROM userdata WHERE ID=%s;"),ticketdata.m_uid);
	userdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);

	userdata.Edit();
	ticketdata.Edit();
	
	userdata.m_nm=m_name;
	userdata.m_mobile=m_contact;
	userdata.m_email=m_email;
	//getting the current route selection
	CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_COMBO1);
	int index=ptr->GetCurSel();
	wsprintf(str,TEXT("%d"),routeId[index]);
	ticketdata.m_rid=str;
	ptr=(CComboBox *)GetDlgItem(IDC_COMBO3);
	index=ptr->GetCurSel();
	wsprintf(str,TEXT("%d"),index+1);
	ticketdata.m_noofseat=str;

	//int seatIndex=_wtoi(ticketdata.m_noofseat);
	wsprintf(str,TEXT("The new total amount is %d..\n Do you wish to proceed..??"),(routedata.m_price*(index+1)));
	int response=MessageBox(str,TEXT("You Sure..!!"),MB_YESNOCANCEL);
	if(response!=IDYES)
	{
		//user doesn't approve of changes return..DO NOT reflect changes to db
		userdata.Close();
		routedata.Close();
		ticketdata.Close();
		return;
	}

	userdata.Update();
	ticketdata.Update();
	userdata.Close();
	routedata.Close();
	ticketdata.Close();
	OnOK();
}
