// odDlg.cpp : implementation file
//

#include "stdafx.h"
#include "od.h"
#include "odDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
BOOL OnIniDialog();
// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CodDlg dialog




CodDlg::CodDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CodDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CodDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PRINT, &CodDlg::OnBnClickedPrint)
	ON_BN_CLICKED(IDC_INSERT, &CodDlg::OnBnClickedInsert)
	ON_BN_CLICKED(IDC_UPDATE, &CodDlg::OnBnClickedUpdate)
	ON_BN_CLICKED(IDC_DELETE, &CodDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &CodDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CodDlg message handlers

BOOL CodDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	ShowWindow(2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CodDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CodDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CodDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CodDlg::OnBnClickedPrint()
{
	//MessageBox("hhjhjh\0","jhj");
	//CAbouDlg di1(IDD_ABOUTBOX,this);
	//di1.Create(IDD_ABOUTBOX,this);
	CDialog di1(IDD_ABOUTBOX,this);
	di1.DoModal();
	// TODO: Add your control notification handler code here
}

void CodDlg::OnBnClickedInsert()
{

	// TODO: Add your control notification handler code here
	CInsertDlg di1(IDD_INSERT,this);
	di1.DoModal();

}

void CodDlg::OnBnClickedUpdate()
{
	CUpdateDlg di1(IDD_UPDATE,this);
	di1.DoModal();

	// TODO: Add your control notification handler code here
}

void CodDlg::OnBnClickedDelete()
{
	CDeleteDlg di1(IDD_DELETE,this);
	di1.DoModal();

	// TODO: Add your control notification handler code here
}

void CodDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	TCHAR str[200]={'\0'};
	int i=0;
	//wsprintf(_T(str),"haha:%d",i);
	//MessageBox(_T("haha"));
	/*userdata.Open(1,_T("SELECT * FROM routedata;"));
	
	DWORD n=userdata.GetRowsFetched();
	wsprintf(str,TEXT("%hu"),n);
	MessageBox(str);
	wsprintf(str,TEXT("%d %s %s"),userdata.m_ID,userdata.m_sourcename,userdata.m_destname);
	MessageBox(str);
	userdata.MoveNext();
	wsprintf(str,TEXT("%d %s %s"),userdata.m_ID,userdata.m_sourcename,userdata.m_destname);
	MessageBox(str);
	userdata.Close();*/
}