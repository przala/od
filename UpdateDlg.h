#pragma once
#include "routedata.h"
#include "ticketdata.h"
#include "userdata.h"
#include "afxwin.h"

// CUpdateDlg dialog

class CUpdateDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpdateDlg)

public:
	/*db record set vars*/
	Croutedata routedata;
	Cticketdata ticketdata;
	Cuserdata userdata;


	CUpdateDlg(UINT dlgID,CWnd *owner);   // standard constructor
	virtual ~CUpdateDlg();
	BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_UPDATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_ticket;
	CString m_name;
	CString m_contact;
	CString m_email;
	UINT routeId[100];
	UINT priceArray[100];
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo3();
	CString m_route;
	int m_seat;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
