#include "pay_dll.h"

extern "C" int GetInfo(TInfo *info)
{
	if (ControlPay == NULL)
	{
		info->Version = 8;
		//ControlPay=new CControlPay();
		return 1;
	}
	return ControlPay->GetInfo(info);
}

extern "C" int Init(char *path, TErrorStruct *err)
{
	if (ControlPay == NULL)
	{
		ControlPay = new CControlPay();
	}
	return ControlPay->Init(path, err);
}

extern "C" int Done()
{
	if (ControlPay == NULL)
	{
		return 1;
	}
	int ret = ControlPay->Done();
	delete ControlPay;
	ControlPay = NULL;
	return ret;
}

extern "C" int Pay(TPayStructure *payinfo)
{
	if (ControlPay == NULL)
	{
		payinfo->Error = 14;
		return 0;
	}
	int ret = ControlPay->Pay(payinfo);
	return ret;
}

extern "C" int CancelLastTransaction(TPayStructure *payinfo)
{
	if (ControlPay == NULL)
	{
		payinfo->Error = 14;
		return 0;
	}
	int ret = ControlPay->CancelLastTransaction(payinfo);

	return ret;
}

extern "C" int CloseDay(TPayStructure *payinfo)
{
	if (ControlPay == NULL)
	{
		payinfo->Error = 14;
		return 0;
	}

	int ret = ControlPay->CloseDay(payinfo);

	return ret;
}

extern "C" int ShowProperties()
{
	if (ControlPay == NULL)
	{
		return 0;
	}
	return ControlPay->ShowProperties();
}


extern "C" int PrintCheckCopy(TPayStructure *info)
{
	if (ControlPay == NULL)
	{
		info->Error = 14;
		return 0;
	}
	return ControlPay->PrintCheckCopy(info);

}

extern "C" int PrintReport(TPayStructure *info)
{
	if (ControlPay == NULL)
	{
		info->Error = 14;
		return 0;
	}
	return ControlPay->PrintReport(info);

}
extern "C" int CheckConnection(SimpleOutStruct *info)
{
	if (ControlPay == NULL)
	{
		info->ErrorCode = 14;
		return 0;
	}
	return ControlPay->CheckConnection(info);

}

extern "C" int GetGiftCardBalance(TGiftCardStructure *info)
{
	if (ControlPay == NULL)
	{
		info->ErrorCode = 14;
		return 0;
	}
	return ControlPay->GetGiftCardBalance(info);
}

extern "C" int GiftCardPreActivationSlip(TPayStructure *info)
{
	if (ControlPay == NULL)
	{
		info->Error = 14;
		return 0;
	}
	return ControlPay->GiftCardPreActivationSlip(info);
}

extern "C" int ActivateGiftCard(TPayStructure *info)
{
	if (ControlPay == NULL)
	{
		info->Error = 14;
		return 0;
	}
	return ControlPay->ActivateGiftCard(info);
}

extern "C" int ActivateGiftCardArbitraryNominal(TPayStructure *info)
{
	if (ControlPay == NULL)
	{
		info->Error = 14;
		return 0;
	}
	return ControlPay->ActivateGiftCard(info, false);
}


extern "C" int CorrectDiscountCard(TPayStructure *info)
{
	if (ControlPay == NULL)
	{
		info->Error = 14;
		return 0;
	}
	return ControlPay->CorrectDiscountCard(info);
}

extern "C" int GetGiftCardNominal(TGiftCardStructure *info)
{

	if (ControlPay == NULL)
	{
		info->ErrorCode = 14;
		return 0;
	}
	return ControlPay->GetGiftCardNominal(info);

}


CControlPay::CControlPay()
{
	IsInitControl = false;
}

CControlPay::~CControlPay()
{

}
int CControlPay::CheckConnection(SimpleOutStruct *payinfo)
{



	return 0;
}
int CControlPay::PrintReport(TPayStructure *payinfo)
{
	return 0;
}
int CControlPay::GetInfo(TInfo *info)
{
	info->Version = 5;
	//
	strcpy_s(InfoName, 9, "SoftCase");
	info->Name = &InfoName[0];
	info->TerminalID = NULL;

	strcpy_s(InfoNumberOfPoint, 2, "");
	info->NumberOfPoint = &InfoNumberOfPoint[0];
	AddInfo.ReadCardOnCash = 0;
	AddInfo.MultiAuth = 0;
	info->AddInfo = &AddInfo;
	return 1;
}

int CControlPay::Init(char *path, TErrorStruct *err)
{
	return 1;
}

int CControlPay::Done()
{
	return 1;
}

int CControlPay::Pay(TPayStructure *info)
{
	if (info->Amount >= 0)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}

int CControlPay::CancelLastTransaction(TPayStructure *info)
{
	return 0;
}

int CControlPay::CloseDay(TPayStructure *info)
{
	return 0;
}

int CControlPay::ShowProperties()
{
	return 0;
}


int CControlPay::PrintCheckCopy(TPayStructure *payinfo)
{
	return 0;
}



int CControlPay::GetGiftCardBalance(TGiftCardStructure *info)
{
	return 0;
}
int CControlPay::GiftCardPreActivationSlip(TPayStructure *info)
{
	return 0;
}

int CControlPay::ActivateGiftCard(TPayStructure *info, bool ispreapaid)
{
	return 0;
}



int CControlPay::CorrectDiscountCard(TPayStructure *info)
{
	return 0;
}


int CControlPay::GetGiftCardNominal(TGiftCardStructure *info)
{
	return 0;
}