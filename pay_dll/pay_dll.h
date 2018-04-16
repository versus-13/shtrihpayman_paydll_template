#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//struct
struct TInfo
{
	int Version;
	const char* Name;
	const char* TerminalID;
	const char* NumberOfPoint;
	const void* AddInfo;
};

struct TPayStructure
{
	int  Amount;
	char *CardNumber;
	int  KKMNumber;
	int CheckNumber;
	char *AuthCode;
	char *RRN;
	int  Error;
	char *ErrorMsg;
	char *StringForPrint;
	char *DisplayMessage;
	int DiscountAmount;
	int MustCommit;
	char *StringForBuy;
	int ComissionAmount;
	int BonusAmount;
	int GoodsCount;
	void *Goods;
	int PaysCount;
	void *Pays;
	int CardInputType;
};

struct TAddInfo
{
	int ReadCardOnCash;
	int MultiAuth;
	int ReadPhoneNumberOnCash;
	int ReadServiceProviderOnCash;
	int MultiCloseDay;
};

struct TErrorStruct
{
	int  ErrorCode;
	const char* ErrorMessage;
};



struct TGiftCardStructure
{
	int  Amount;
	char *CardNumber;
	int ErrorCode;
	char *ErrorMessage;
	char *StringForPrint;
	char *DisplayMessage;
};

typedef void(__cdecl TLogProc)(int, char*);



struct CardAmount
{
	char Name[100];
	int Pay;
	int Cancel;
	int Return;
};

struct SimpleOutStruct
{
	int ErrorCode;
	char *ErrorMessage;
	char *StringForPrint;
};
//------


//------

//DLL functions
extern "C" int GetInfo(TInfo *info);
extern "C" int Init(char *path, TErrorStruct *err);
extern "C" int Done();
extern "C" int Pay(TPayStructure *payinfo);
extern "C" int CancelLastTransaction(TPayStructure *payinfo);
extern "C" int CloseDay(TPayStructure *payinfo);
extern "C" int ShowProperties();
extern "C" int PrintCheckCopy(TPayStructure *info);


extern "C" int GetGiftCardBalance(TGiftCardStructure *info);
extern "C" int ActivateGiftCard(TPayStructure *info);
extern "C" int CorrectDiscountCard(TPayStructure *info);
extern "C" int GetGiftCardNominal(TGiftCardStructure *info);
//-------------


#include <vector>

class CMessages;
class Properties;
class LastCheckedCardData;
class CControlPay
{

	bool IsInitControl;


public:
	char InfoName[50];
	TAddInfo AddInfo;
	char InfoTerminalID[50];
	char InfoNumberOfPoint[10];

	CControlPay();
	virtual ~CControlPay();
	int CheckConnection(SimpleOutStruct *info);
	int GetInfo(TInfo *info);
	int Init(char *path, TErrorStruct *err);
	int Done();
	int Pay(TPayStructure *payinfo);
	int CancelLastTransaction(TPayStructure *payinfo);
	int CloseDay(TPayStructure *payinfo);
	int ShowProperties();
	int PrintCheckCopy(TPayStructure *info);
	int PrintReport(TPayStructure *info);
	int GetGiftCardBalance(TGiftCardStructure *info);
	int ActivateGiftCard(TPayStructure *info, bool isprepaid = true);
	int CorrectDiscountCard(TPayStructure *info);
	int GetGiftCardNominal(TGiftCardStructure *info);
	int GiftCardPreActivationSlip(TPayStructure *info);
};

static CControlPay* ControlPay;
