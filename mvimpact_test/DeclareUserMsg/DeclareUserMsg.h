#if !defined( AFX_DECLARE_USER_MSG_H__DD4F48A0_F11D_4BE6_866A_B08B03A14A0A__INCLUDED_ )
#define AFX_DECLARE_USER_MSG_H__DD4F48A0_F11D_4BE6_866A_B08B03A14A0A__INCLUDED_

#define DECLARE_USER_MESSAGE( name ) \
     static const UINT name = ::RegisterWindowMessage( name##_MSG );

//Exemplo

//Definição das mensagens
/***************************************************************
*                           UWM_UPDATE_CAMERA_STATUS
* Inputs:
*       WPARAM: (WPARAM)(int)
				0
*       LPARAM: (LPARAM)(int)
				Endereço da estrutura FBCBINFO com informação da carta e
				do nodo
* Result: LRESULT
*	Logically void, 0, always
* Effect:
*	Faz o update da view após algun evento no barramento firewire
***************************************************************/
//#define UWM_UPDATE_CAMERA_STATUS_MSG _T("UWM_UPDATE_CAMERA_STATUS-{0E04E6A3-7C01-4961-81CE-46FC4CE51EFD}")
//DECLARE_USER_MESSAGE( UWM_UPDATE_CAMERA_STATUS )



// typedef struct tagNMTREEVIEWW {
// 	NMHDR       hdr;
// 	UINT        action;
// 	TVITEMW    itemOld;
// 	TVITEMW    itemNew;
// 	POINT       ptDrag;
// } NMTREEVIEWW, *LPNMTREEVIEWW;




#endif // !#define AFX_DECLARE_USER_MSG_H__DD4F48A0_F11D_4BE6_866A_B08B03A14A0A__INCLUDED_