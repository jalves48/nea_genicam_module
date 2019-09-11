// AcquisitionThread.h: 
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "..\stdafx.h"
#include <afxtempl.h>
#include <afxmt.h>

//////////////////////////////////////////////////////////////////////
// This thread does all of our work required to handle a single card.
//////////////////////////////////////////////////////////////////////


typedef struct fbcbinfo
{
	UINT8         CardNumber;
	UINT32        Reason;
	void*         pData;
	void*         pContext;
}FBCBINFO,*PFBCBINFO;


typedef void MYFBCALLBACK( PFBCBINFO );

class CCameraConfigArray;

class CMainThread : public CObject
{
public:
	typedef struct _sOPCData
	{
		int nID;
		CString strTagName;
		CString strTagValue;
	}SOPCDATA;

	typedef struct _sModBusData
	{
		int nAdress;
		int nValue;
	}SMODBUSDATA;


	enum eThreadIDOper
	{
		eTHREAD_SUSPENDED = 0,
		eTHREAD_INIT	  = 1,
		eTHREAD_INPLAY	  = 2,
		eTHREAD_STOP	  = -1,
		eTHREAD_KILL      = -4
// 		eSEQ_TERMINATED   =  1,
// 		ePROCESS_OK       =  0,
// 		ePROCESS_ERROR    = -1,
// 		
// 		eNO_DATA          = -3,
	};

	enum eThreadState
	{
		eSTATE_STOP     = 0x00,
		eSTATE_RUN      = 0x01,
		eSTATE_PAUSED   = 0x02,
		eSTATE_INIT     = 0x03,

	};

	typedef enum eThreadMachineState
	{
		eREAD_MACHINE_READY	= 0,
		eREAD_RESET			,
		eREAD_POS_OK		,
		eREAD_ID_POS		,
		eWRITE_SOFTWARE_RDY	,
		eWRITE_ADQ_OK		,
		eWRITE_RESET_PC		,
		eWRITE_ID_PECA		,

	}eMACHINESTATE;

	typedef enum eCycleState
	{
		eCS_INIT			  = 0,		
		eCS_WAIT_SENSOR       ,
		eCS_WAIT_BOTH_RESULTS ,   

	}eCYCLESTATE;

//	COPCManager m_man;

	typedef struct _sData
	{

		//vector < TOOLS_ARRAY > m_ToolsDB;
		//vector < VECPANELTOOLS > m_ToolsDB;
		float m_fProcTime;

	}sThreadData, *PTHREAD_DATA;

	sThreadData			m_ThreadData;

// 	UINT8			 m_CardNr;               // Actual card number
//	CWinApp*		 m_pDlg;
	HWND			 m_hViewHandle;
	MYFBCALLBACK*	 m_pCallback;          // Pointer to callback fucntion
// 	CFireBus		 m_FireBus;              // Our firebus object
// 	BOOL			 m_bIsDead;
// 	CTypedPtrArray< CPtrArray, CAvtCamera*> m_AvtCameraArray;

protected:

//	static void CardCallback( FBCBINFO *pInfo );

	CWinThread*		 m_pThread;              // Pointer to MFC thread
// 	BOOL			 m_LogEnabled;           // Log enabled or not
// 	DWORD            m_Offset;               // Window offset
 	BOOL		     m_bIsSuspended;
//	CCriticalSection m_CriticalSection;
	eCYCLESTATE		 m_eCycleState;
	
public:
	BOOL			 m_bFirstTime;
	BOOL		     m_bThreadInRunning;


 	BOOL IsSuspended();
 	void ResumeThread();
 	void SuspendThread();
	DWORD SyncStopThread();
	void Close();
	void SetCycleThreadState(eCYCLESTATE state);

	CMainThread( HWND hViewHandle );

 	virtual ~CMainThread();
	
	void Main( PVOID pParam );
	UINT8 Start( /*UINT8 CardNr*/ );
	UINT8 Stop();

	volatile BOOL m_bIsAlive;
	volatile BOOL m_bDoSomething;


	BOOL m_bEndCycle;
};

