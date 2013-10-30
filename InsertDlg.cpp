// InsertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "od.h"
#include "InsertDlg.h"


// CInsertDlg dialog

IMPLEMENT_DYNAMIC(CInsertDlg, CDialog)

CInsertDlg::CInsertDlg(UINT dlgID,CWnd *owner)
	: CDialog(dlgID,owner)
	, m_name(_T(""))
	, m_contact(_T(""))
	, m_email(_T(""))
	, m_route(_T(""))
	, m_seat(0)
	, m_amount(_T(""))
{

}

CInsertDlg::~CInsertDlg()
{
}

void CInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDV_MaxChars(pDX, m_name, 30);
	DDX_Text(pDX, IDC_EDIT2, m_contact);
	DDV_MaxChars(pDX, m_contact, 11);
	DDX_Text(pDX, IDC_EDIT3, m_email);
	DDV_MaxChars(pDX, m_email, 40);
	DDX_CBString(pDX, IDC_COMBO4, m_route);
	DDV_MaxChars(pDX, m_route, 80);
	DDX_CBIndex(pDX, IDC_COMBO6, m_seat);
	DDV_MinMaxInt(pDX, m_seat, 0, 10);
	DDX_Text(pDX, IDC_EDIT7, m_amount);
}

BEGIN_MESSAGE_MAP(CInsertDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CInsertDlg::OnCbnSelchangeCombo6)
	ON_BN_CLICKED(IDOK, &CInsertDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CInsertDlg::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()



BOOL CInsertDlg::OnInitDialog()
{
	TCHAR str[100];
	int i=0;
	CComboBox *lbptr=(CComboBox *)GetDlgItem(IDC_COMBO4);
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

	lbptr=(CComboBox *)GetDlgItem(IDC_COMBO6);
	for(int i=1;i<11;i++)
	{
		wsprintf(str,TEXT("%d"),i);
		lbptr->AddString(str);
	}

	return(1);
}

// CInsertDlg message handlers

void CInsertDlg::OnCbnSelchangeCombo6()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	TCHAR str[20];
	CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_COMBO4);
	int index=ptr->GetCurSel();
	wsprintf(str,TEXT("%d"),priceArray[index]);
	//MessageBox(str);

	wsprintf(str,TEXT("%d"),(m_seat+1)*priceArray[index]);
	m_amount=str;//(m_seat*priceArray[index]);
	//CEditBox *edptr=(CEditBox *)GetDlgItem(IDC_EDIT7);
	//edptr->(str);
	UpdateData(0);
}

void CInsertDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	/*fetch the valuse from controls and */
	UpdateData(1);
	//data validation
	if(m_name.IsEmpty())
	{
		MessageBox(TEXT("Name can not be empty..!!"));
		return;
	}
	if(m_contact.IsEmpty())
	{
		MessageBox(TEXT("Contact can not be empty..!!"));
		return;
	}
	if(m_route.IsEmpty())
	{
		MessageBox(TEXT("Please select a route..!!"));
		return;
	}
	
	//all is well now add one entry to user and ticket databases
	userdata.Open(AFX_DB_USE_DEFAULT_TYPE);
	userdata.AddNew();
	userdata.m_nm=m_name;
	userdata.m_email=m_email;
	userdata.m_mobile=m_contact;
	userdata.Update();
	userdata.Close();

	TCHAR query[100],tmpStr[30];
	wsprintf(query,TEXT("SELECT ID FROM userdata WHERE nm='%s' AND mobile='%s'"),m_name,m_contact);
	userdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	int uid=userdata.m_ID;
	userdata.Close();

	//fetch uid

	CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_COMBO1);
	int index=ptr->GetCurSel();

	ticketdata.Open(AFX_DB_USE_DEFAULT_TYPE);
	ticketdata.AddNew();
	m_seat=m_seat+1;
	wsprintf(tmpStr,TEXT("%d"),m_seat);
	ticketdata.m_noofseat=tmpStr;
	wsprintf(tmpStr,TEXT("%d"),routeId[index]);
	ticketdata.m_rid=tmpStr;
	wsprintf(tmpStr,TEXT("%d"),uid);
	ticketdata.m_uid=tmpStr;
	ticketdata.Update();
	ticketdata.Close();
	wsprintf(query,TEXT("SELECT ID FROM ticketdata WHERE uid='%d' AND rid='%d'"),uid,routeId[index]);
	ticketdata.Open(AFX_DB_USE_DEFAULT_TYPE,query);
	int tid=ticketdata.m_ID;
	ticketdata.Close();

	TCHAR msg[30]={'\0'};
	wsprintf(msg,TEXT("Success..!!\nTicket Id is :%d"),tid);
	MessageBox(msg);
	OnOK();
}

void CInsertDlg::OnCbnSelchangeCombo4()
{
	UpdateData(TRUE);
	TCHAR str[20];
	CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_COMBO4);
	int index=ptr->GetCurSel();
	
	wsprintf(str,TEXT("%d"),priceArray[index]);
	//MessageBox(str);

	wsprintf(str,TEXT("%d"),(m_seat+1)*priceArray[index]);
	m_amount=str;//(m_seat*priceArray[index]);
	//CEditBox *edptr=(CEditBox *)GetDlgItem(IDC_EDIT7);
	//edptr->(str);
	UpdateData(0);
}
