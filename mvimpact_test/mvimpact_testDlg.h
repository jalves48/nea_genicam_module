
// mvimpact_testDlg.h : header file
//
#include "AcquireModule\DeviceMan.h"
#include "MainThread\MainThread.h"
#pragma once


#define BTN_PLAY 100
#define BTN_STOP 101


// Cmvimpact_testDlg dialog
class Cmvimpact_testDlg : public CDialogEx
{
// Construction
public:
	Cmvimpact_testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MVIMPACT_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	HWND  m_hView;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CMainThread* m_pMainThread;

	//Registered User defined messages handlers
	afx_msg LRESULT OnUWMSetInterfaceFunction(WPARAM, LPARAM);
	afx_msg LRESULT OnUWMMainThreadCallback(WPARAM wParam, LPARAM lParam);

	CDeviceMan DeviceMan;

private:

	//Functions
	bool Init();
	bool InitListCtrl();
	void UpdateCameraInfoItems();
	void UpdateLogInfo(std::string str);



	//Variables

	//Controls

public:
	//Functions

	//Variables
	CListCtrl m_cameralist;
	CListCtrl m_Loglist;

	//Controls

	afx_msg void OnBnClickedRefreshCameras();
	afx_msg void OnLvnItemchangedCameralist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedClearCamList();
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedStop();

	afx_msg void OnLvnItemchangedLog(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
};
