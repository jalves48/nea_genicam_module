#include "AcqModule.h"


struct ThreadParameter;

class CCapture 
{       // The class
public:             // Access specifier

	CCapture();
	~CCapture();

	ThreadParameter* p_threadParam;
	helper::RequestProvider* p_requestProvider;


	int Init(Device* pDev);

public:
	int RunLive(Device* pDev);
	

private:



};