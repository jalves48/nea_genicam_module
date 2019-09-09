
// mvimpact_testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mvimpact_test.h"
#include "mvimpact_testDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// Cmvimpact_testDlg dialog



Cmvimpact_testDlg::Cmvimpact_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmvimpact_testDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmvimpact_testDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAMERALIST, m_cameralist);

}

BEGIN_MESSAGE_MAP(Cmvimpact_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cmvimpact_testDlg::OnBnClickedRefreshCameras)


	ON_NOTIFY(LVN_ITEMCHANGED, IDC_CAMERALIST, &Cmvimpact_testDlg::OnLvnItemchangedCameralist)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmvimpact_testDlg::OnBnClickedClearCamList)
END_MESSAGE_MAP()


// Cmvimpact_testDlg message handlers

BOOL Cmvimpact_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	Init();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MAXIMIZE/*SW_MINIMIZE*/);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cmvimpact_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmvimpact_testDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cmvimpact_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool Cmvimpact_testDlg::Init()
{
	//Inicialization
	InitListCtrl();
	camera.Init();
	UpdateCameraInfoItems();

	return true;
}


bool Cmvimpact_testDlg::InitListCtrl()
{
//	if (!m_bIsInit || !UpdateData())
//		return FALSE;

	// TODO:  Add extra initialization here
	// inicializar lista de defeitos 3d
	/*m_ListCtrlRefPoints.SetExtendedStyle(
	LVS_EX_FULLROWSELECT | LVS_EX_FLATSB |
	LVS_EX_GRIDLINES	 | LVS_EX_HEADERDRAGDROP );*/
	ListView_SetExtendedListViewStyle(m_cameralist.m_hWnd,
		LVS_EX_FULLROWSELECT |
		LVS_EX_FLATSB |
		LVS_EX_GRIDLINES |
		LVS_EX_HEADERDRAGDROP);

	m_cameralist.InsertColumn(0, _T("Family"), LVCFMT_LEFT, 200);
	m_cameralist.InsertColumn(1, _T("Poduct"), LVCFMT_LEFT, 250);
	m_cameralist.InsertColumn(2, _T("Serial"), LVCFMT_LEFT, 200);
	m_cameralist.InsertColumn(3, _T("State"), LVCFMT_LEFT, 100);
	m_cameralist.InsertColumn(4, _T("Firmware Version"), LVCFMT_LEFT, 200);
	m_cameralist.InsertColumn(5, _T("Device ID"), LVCFMT_LEFT, 200);
	m_cameralist.InsertColumn(6, _T("Allocated DMA Buffer(KB)"), LVCFMT_LEFT, 200);
	m_cameralist.InsertColumn(7, _T("Registered For Direct Show"), LVCFMT_LEFT, 250);
	m_cameralist.InsertColumn(8, _T("DirectShow Friendly Name"), LVCFMT_LEFT, 200);

	return TRUE;
}

void Cmvimpact_testDlg::UpdateCameraInfoItems()
{
	m_cameralist.DeleteAllItems();

	int nRow = 0;
	CString strAux;


	for (std::vector< CCamera::SCAMERAINFO >::const_iterator iter = camera.STLvec_CameraInfo.begin();
		iter != camera.STLvec_CameraInfo.end(); ++iter)
	{
		//Insert
		strAux.Format(L"%d", nRow);
		m_cameralist.InsertItem(0, L"");

		//Ctr List Columns order
			//Family
			//Product
			//Serial
			//State
			//Firmware Version
			//Device ID

			//Allocated DMA Buffer(KB)
			//Registered For Direct Show
			//DirectShow Friendly Name

		strAux = iter->Family.c_str();
		m_cameralist.SetItemText(nRow, 0, strAux);
		strAux = iter->Product.c_str();
		m_cameralist.SetItemText(nRow, 1, strAux);
		strAux = iter->Serial.c_str();
		m_cameralist.SetItemText(nRow, 2, strAux);
		strAux = iter->State.c_str();
		m_cameralist.SetItemText(nRow, 3, strAux);
		strAux = iter->FirmwareVersion.c_str();
		m_cameralist.SetItemText(nRow, 4, strAux);		
		strAux = iter->DeviceID.c_str();
		m_cameralist.SetItemText(nRow, 5, strAux);


// 		strAux = iter->State.c_str();B
// 		m_cameralist.SetItemText(nRow, 6, strAux);
// 		strAux = iter->State.c_str();
// 		m_cameralist.SetItemText(nRow, 7, strAux);
// 		strAux = iter->State.c_str();
// 		m_cameralist.SetItemText(nRow, 8, strAux);
	}
	
}


void Cmvimpact_testDlg::OnBnClickedRefreshCameras()
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("TestDialog", MB_OK);
	camera.ListCameras();
	UpdateCameraInfoItems();
	

}






void Cmvimpact_testDlg::OnLvnItemchangedCameralist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void Cmvimpact_testDlg::OnBnClickedClearCamList()
{
	m_cameralist.DeleteAllItems();
}
