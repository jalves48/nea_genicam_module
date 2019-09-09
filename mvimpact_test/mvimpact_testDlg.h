
// mvimpact_testDlg.h : header file
//
#include "AcquireModule\camera.h"
#pragma once


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

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CCamera camera;

private:

	//Functions
	bool Init();
	bool InitListCtrl();
	void UpdateCameraInfoItems();

	//Variables

	//Controls

public:
	//Functions

	//Variables
	CListCtrl m_cameralist;

	//Controls

	afx_msg void OnBnClickedRefreshCameras();
	afx_msg void OnLvnItemchangedCameralist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedClearCamList();
};
