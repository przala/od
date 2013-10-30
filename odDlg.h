// odDlg.h : header file
//

#pragma once
#include "routedata.h"
#include "ticketdata.h"
#include "userdata.h"
#include "InsertDlg.h"
#include "UpdateDlg.h"
#include "DeleteDlg.h"
// CodDlg dialog
class CodDlg : public CDialog
{
// Construction
public:
	/*Database Recordset objects here  */
	Croutedata routedata;
	Cticketdata ticketdata;
	Cuserdata userdata;

	CodDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_OD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedPrint();
	afx_msg void OnBnClickedInsert();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedButton1();
};
