#include<iostream>
#include<Windows.h>

void placeJMP(BYTE* address, DWORD jumpTo, DWORD length)
{
	DWORD oldProtect, newProtect, relativeAddress;
	VirtualProtect(address, length, PAGE_EXECUTE_READWRITE, &oldProtect);
	relativeAddress = (DWORD)(jumpTo - (DWORD)address) - 5;
	*address = 0xE9;
	*((DWORD*)(address + 0x1)) = relativeAddress;
	for (DWORD x = 0x5; x < length; x++)
	{
		*(address + x) = 0x90;
	}
	VirtualProtect(address, length, oldProtect, &newProtect);
}

DWORD base = (DWORD)GetModuleHandleA(0);
DWORD libcocosbase = (DWORD)GetModuleHandleA("libcocos2d.dll");

DWORD createMenu = base + 0x18EE0;

DWORD createWithSprite = base + 0x282284; // USE AS A POINTER
DWORD createWithSprite_ = (DWORD)createWithSprite;

DWORD operatorPlus = base + 0x282278; // USE AS A POINTER
DWORD operatorPlus_ = (DWORD)operatorPlus;

DWORD sharedDirector = base + 0x282270; // USE AS A POINTER
DWORD sharedDirector_ = (DWORD)sharedDirector;

DWORD arrangeMenu = base + 0x19080;

DWORD floatCutButton = base + 0x2E62F8; // USE AS A POINTER
DWORD floatCutButton_ = (DWORD)floatCutButton;
DWORD GJ_PasteBtn2_001 = base + 0x29870C;
DWORD copyObject = base + 0x87FB0;
DWORD deleteObject = base + 0x7BF50;
DWORD retLoadCutButton = base + 0x77455;
char cutButtonSpriteChar[21] = "GJ_cutButton_001.png";
DWORD cutButtonSprite = (DWORD)cutButtonSpriteChar;
DWORD retLoadCutShortcut = base + 0x091C09;
DWORD loadCutShortcut_1 = base + 0x091C40;
DWORD loadCutShortcut_2 = base + 0x092166;
DWORD loadCutShortcut_3 = base + 0x261E27;

DWORD retLoadModBadges = base + 0x211191;
DWORD retLoadModBadges2 = base + 0x5FA2B;
char modBadgesStringChar[20] = "modBadge_01_001.png";
DWORD modBadgesString = (DWORD)modBadgesStringChar;


DWORD XGDPS_creditsSkipIconsJump = base + 0x49466;
DWORD retXGDPS_creditsShowButton = base + 0x190C42;
DWORD XGDPS_creditsFunction = base + 0x14B270;
char XGDPS_creditsSpriteNameChar[21] = "GJ_creditButton2.png";
DWORD XGDPS_creditsSpriteName = (DWORD)XGDPS_creditsSpriteNameChar;
DWORD retXGDPS_creditsPosition = base + 0x49657;
DWORD XGDPS_creditsPosition_multiplier = 70;
DWORD XGDPS_creditsPosition_adjusterX = 105;
DWORD XGDPS_creditsPosition_adjusterX2 = -80;
DWORD XGDPS_creditsPosition_adjusterY = -5;
DWORD XGDPS_creditsPosition_splitAmount = 6;
DWORD retXGDPS_creditsMenuIcon = base + 0x49602;
char XGDPS_creditsMenuIcon_stringChar[29] = "communityCreditsBtn_%03d.png";
DWORD XGDPS_creditsMenuIcon_string = (DWORD)XGDPS_creditsMenuIcon_stringChar;
DWORD XGDPS_creditsMain_returnNotFound = base + 0x495DE;
DWORD XGDPS_creditsMain_returnFound = base + 0x495D2;
char XGDPS_creditsMain_credit_1_stringChar[] = "Azalea";
DWORD XGDPS_creditsMain_credit_1_string = (DWORD)XGDPS_creditsMain_credit_1_stringChar;
DWORD XGDPS_creditsMain_credit_1_length = sizeof(XGDPS_creditsMain_credit_1_stringChar) - 1;
char XGDPS_creditsMain_credit_2_stringChar[] = "Lex305";
DWORD XGDPS_creditsMain_credit_2_string = (DWORD)XGDPS_creditsMain_credit_2_stringChar;
DWORD XGDPS_creditsMain_credit_2_length = sizeof(XGDPS_creditsMain_credit_2_stringChar) - 1;
char XGDPS_creditsMain_credit_3_stringChar[] = "Wylie";
DWORD XGDPS_creditsMain_credit_3_string = (DWORD)XGDPS_creditsMain_credit_3_stringChar;
DWORD XGDPS_creditsMain_credit_3_length = sizeof(XGDPS_creditsMain_credit_3_stringChar) - 1;
char XGDPS_creditsMain_credit_4_stringChar[] = "13laze";
DWORD XGDPS_creditsMain_credit_4_string = (DWORD)XGDPS_creditsMain_credit_4_stringChar;
DWORD XGDPS_creditsMain_credit_4_length = sizeof(XGDPS_creditsMain_credit_4_stringChar) - 1;
char XGDPS_creditsMain_credit_5_stringChar[] = "Adafcaefc";
DWORD XGDPS_creditsMain_credit_5_string = (DWORD)XGDPS_creditsMain_credit_5_stringChar;
DWORD XGDPS_creditsMain_credit_5_length = sizeof(XGDPS_creditsMain_credit_5_stringChar) - 1;
char XGDPS_creditsMain_credit_6_stringChar[] = "Absolute";
DWORD XGDPS_creditsMain_credit_6_string = (DWORD)XGDPS_creditsMain_credit_6_stringChar;
DWORD XGDPS_creditsMain_credit_6_length = sizeof(XGDPS_creditsMain_credit_6_stringChar) - 1;
char XGDPS_creditsMain_credit_7_stringChar[] = "Rain";
DWORD XGDPS_creditsMain_credit_7_string = (DWORD)XGDPS_creditsMain_credit_7_stringChar;
DWORD XGDPS_creditsMain_credit_7_length = sizeof(XGDPS_creditsMain_credit_7_stringChar) - 1;
char XGDPS_creditsMain_credit_8_stringChar[] = "Bentai";
DWORD XGDPS_creditsMain_credit_8_string = (DWORD)XGDPS_creditsMain_credit_8_stringChar;
DWORD XGDPS_creditsMain_credit_8_length = sizeof(XGDPS_creditsMain_credit_8_stringChar) - 1;
char XGDPS_creditsMain_credit_9_stringChar[] = "Lakifarux";
DWORD XGDPS_creditsMain_credit_9_string = (DWORD)XGDPS_creditsMain_credit_9_stringChar;
DWORD XGDPS_creditsMain_credit_9_length = sizeof(XGDPS_creditsMain_credit_9_stringChar) - 1;
char XGDPS_creditsMain_credit_10_stringChar[] = "Blexood";
DWORD XGDPS_creditsMain_credit_10_string = (DWORD)XGDPS_creditsMain_credit_10_stringChar;
DWORD XGDPS_creditsMain_credit_10_length = sizeof(XGDPS_creditsMain_credit_10_stringChar) - 1;
char XGDPS_creditsMain_credit_11_stringChar[] = "Yeet";
DWORD XGDPS_creditsMain_credit_11_string = (DWORD)XGDPS_creditsMain_credit_11_stringChar;
DWORD XGDPS_creditsMain_credit_11_length = sizeof(XGDPS_creditsMain_credit_11_stringChar) - 1;
