#pragma once
#include "routedata.h"
#include "ticketdata.h"
#include "userdata.h"
#include "afxwin.h"


// CDeleteDlg dialog

class CDeleteDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeleteDlg)

public:
	/*db record set vars*/
	Croutedata routedata;
	Cticketdata ticketdata;
	Cuserdata userdata;





	CDeleteDlg(UINT templateID,CWnd *parent);   // standard constructor
	virtual ~CDeleteDlg();
	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_ticket;
	CString m_name;
	CString m_source;
	CString m_dest;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
//	afx_msg void OnBnClickedButton2();
};
