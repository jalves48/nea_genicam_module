// AcquisitionThread.cpp: 
// intek, c. kuehnel, 1.6.2003
// Handles all stuff coming from FireBus object.
//////////////////////////////////////////////////////////////////////
#pragma once
#include "..\stdafx.h"
#include "MainThread.h"



#define KILL_THREAD_TIMEOUT 10000  //Tempo de espera para que o thread morra: 5000 ms

CMainThread::CMainThread( HWND hViewHandle )
{
	m_pThread      = NULL;
	//	m_pDlg         = pDlg;
	m_hViewHandle  = hViewHandle;
	m_bIsSuspended = TRUE;
	m_bFirstTime   = TRUE;

	m_bIsAlive			= TRUE;
	m_bDoSomething		= FALSE;
	m_bThreadInRunning  = TRUE;
	m_eCycleState		= eCS_INIT;
		
}


//////////////////////////////////////////////////////////////////////
// Destructor

CMainThread::~CMainThread()
{

}




/////////////////////////////////////////////////////////////////////////////
// Thread main function.

void CMainThread::Main( PVOID pParam )
{
	 
	int nIsReady = 0;
	

// 	while(m_bIsAlive)
// 	{
// 		::SendMessage(m_hViewHandle, WM_MAIN_THREAD_CALLBACK, 0, 0);
// 	}


}



UINT ExeThread( LPVOID pParam )
{
	// 	CAcquisitionThread* pThread = (CAcquisitionThread*)pParam;
	// 
	// 	if ( pThread == NULL )
	// 	{
	// 		AfxEndThread( 0 );
	// 		return 0;   
	// 	}
	// 
	// 	// Call our main loop
	// 	if( pThread )
	// 		pThread->ThreadMain( pParam );
	// 
	// 	AfxEndThread( 0 );

	CMainThread* pThread = (CMainThread*)pParam;

	if ( pThread == NULL )
	{
		AfxEndThread( 0 );
		return 0;   
	}

	if( pThread )
		pThread->Main( pParam );


	int d = 0;
	// 	while(1)
	// 	{
	//Envio a mensagem para a view
	//::PostMessage( m_hViewHandle, UWM_PROCESSTHREAD_PROCCAM, (WPARAM)Result, (LPARAM)0 );

	// 		if ( m_hViewHandle )
	// 			::SendMessage( m_hViewHandle, UWM_PROCESSTHREAD_PROCCAM, 0, 0 );


	//	}





	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Start our FireBus thread.

UINT8 CMainThread::Start( /*UINT8 CardNr*/ ) 
{
	if( !m_pThread )
	{ 
		//card number
		//m_CardNr   = CardNr;

		// Create MFC thread
		m_pThread = AfxBeginThread( ExeThread, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED );

		if( m_pThread )
			return TRUE;

	}

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Stop our thread.

UINT8 CMainThread::Stop()
{
	// 	CSingleLock singleLock( &m_CritSection );	
	// 	singleLock.Lock();  // Attempt to lock the shared resource
	// 
	// 	if ( singleLock.IsLocked() )  // Resource has been locked
	// 	{
	// 		//...use the shared resource...
	// 		m_eState = eSTATE_STOP;
	// 
	// 		// Now that we are finished, 
	// 		// unlock the resource for others.
	// 		singleLock.Unlock();
	// 	}


	m_bIsAlive = FALSE;

	return 0x00;
}


void CMainThread::SuspendThread()
{
	if ( !m_pThread )
		return;

	if ( !m_bIsSuspended )
	{
		m_bIsSuspended = TRUE;
		::SuspendThread( m_pThread->m_hThread );

	}
}

void CMainThread::ResumeThread()
{
	if ( !m_pThread )
		return;

	if ( m_bIsSuspended )
	{
		m_bIsSuspended = FALSE;

		//Se for a 1ª vez Carrego a estrutura
		if(m_bFirstTime)
		{
			m_bFirstTime = FALSE;
			//((CENER_3D_Gocator_ContiDlg*)m_pView)->ThreadCallback( eTHREAD_INIT ); //Vou buscar a estrutura de Ferramentas para inspecção

		}
		::ResumeThread( m_pThread->m_hThread );

	}
}

BOOL CMainThread::IsSuspended()
{
	return m_bIsSuspended;
}


DWORD CMainThread::SyncStopThread()
{

	// Stop thread
	DWORD dwStatus= NULL;

	if ( !m_pThread )
		return dwStatus;

	::GetExitCodeThread( m_pThread->m_hThread, &dwStatus );
	if ( dwStatus == STILL_ACTIVE )
	{
		// 		CSingleLock singleLock( &m_CritSection );	
		// 		singleLock.Lock();  // Attempt to lock the shared resource
		// 		if ( singleLock.IsLocked() )  // Resource has been locked
		// 		{
		// 			// Stop thread
		// 			m_bRun   = FALSE;
		// 
		// 			singleLock.Unlock();
		// 		}

		Stop();
		ResumeThread();

		// Wait until our thread really has stopped
		if ( WaitForSingleObject( m_pThread->m_hThread, KILL_THREAD_TIMEOUT ) == WAIT_TIMEOUT )
		{
			//O thread não morreu.
			//Vou mata-lo à força
			dwStatus = 0xFFFF;
			TerminateThread( m_pThread->m_hThread, dwStatus );
		}
	}

	return dwStatus;
}

void CMainThread::Close()
{
	DWORD exit_code= NULL;
	GetExitCodeThread(m_pThread->m_hThread, &exit_code);
	if(exit_code == STILL_ACTIVE)
	{
		::TerminateThread(m_pThread->m_hThread, 0);
		CloseHandle(m_pThread->m_hThread);
	}
	m_pThread->m_hThread = NULL;
	m_pThread = NULL;
}



void CMainThread::SetCycleThreadState(eCYCLESTATE state)
{
	m_eCycleState = state;
}


