#pragma once
#include "routedata.h"
#include "ticketdata.h"
#include "userdata.h"
#include "afxwin.h"

// CInsertDlg dialog

class CInsertDlg : public CDialog
{
	DECLARE_DYNAMIC(CInsertDlg)

public:
	/*db record set vars*/
	Croutedata routedata;
	Cticketdata ticketdata;
	Cuserdata userdata;


	CInsertDlg(UINT dlgID,CWnd *owner);   // standard constructor
	virtual ~CInsertDlg();
	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo6();
	afx_msg void OnBnClickedOk();
	CString m_name;
	CString m_contact;
	CString m_email;
	CString m_route;
	int m_seat;
	UINT routeId[100];
	UINT priceArray[100];
	CListBox m_amountCtrl;
	CString m_amount;
	afx_msg void OnCbnSelchangeCombo4();
};
