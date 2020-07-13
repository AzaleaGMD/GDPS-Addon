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

__declspec(naked) void loadModBadges() {

	__asm {

		pushad
		mov eax, [eax + 0x000001D4]
		add eax, 48
		mov ecx, modBadgesString
		add ecx, 10
		mov[ecx], al
		inc ecx
		mov dword ptr[ecx], 0x3130305F
		popad
		push modBadgesString
		call dword ptr[createWithSprite]
		jmp[retLoadModBadges]

	}
}
__declspec(naked) void loadModBadges2() {

	__asm {

		pushad
		mov eax, [eax + 0x00000154]
		add eax, 48
		mov ecx, modBadgesString
		add ecx, 10
		mov[ecx], al
		inc ecx
		mov dword ptr[ecx], 0x3130305F
		popad
		push modBadgesString
		call dword ptr[createWithSprite]
		jmp[retLoadModBadges2]

	}
}
__declspec(naked) void pressCutButtonFunction() {

	__asm {

		pushad
		push ebp
		mov ebp, esp
		call copyObject
		mov esp, ebp
		pop ebp
		popad
		pushad
		push ebp
		mov ebp, esp
		call deleteObject
		mov esp, ebp
		pop ebp
		popad
		ret 0x0004

	}
}
DWORD pressCutButton = (DWORD)pressCutButtonFunction;
__declspec(naked) void loadCutButton() {

	__asm {

		push cutButtonSprite
		call dword ptr[createWithSprite]
		mov esi, eax
		mov dword ptr ss : [esp], 0x3F800000
		mov ecx, esi
		mov edx, dword ptr ds : [esi]
		call dword ptr[edx + 0x50]
		push pressCutButton
		push ebx
		mov ecx, esi
		call createMenu
		mov ecx, [esp + 0x18]
		add esp, 0x08
		mov[ebx + 0x0000021C], eax
		mov edx, [ecx]
		push eax
		call dword ptr[edx + 0x000000E0]
		sub esp, 0x08
		lea ecx, [esp + 0x20]
		mov dword ptr[esp + 0x04], 0x3F000000
		mov dword ptr[esp], 0xC2E60000
		call edi
		push eax
		lea eax, [esp + 0x4C]
		push eax
		lea ecx, [esp + 0x38]
		call dword ptr[operatorPlus]
		mov ecx, [ebx + 0x0000021C]
		lea edx, [esp + 0x48]
		push edx
		mov eax, [ecx]
		call dword ptr[eax + 0x5C]
		movss xmm1, [floatCutButton]
		mov ecx, [ebx + 0x0000021C]
		call arrangeMenu
		push GJ_PasteBtn2_001
		jmp[retLoadCutButton]

	}
}
__declspec(naked) void loadCutShortcut() {

	__asm {

		cmp eax, 0x58
		je cutFunction
		cmp eax, 0x43
		jne jp1
		jmp[retLoadCutShortcut]
		cutFunction:
		call dword ptr[sharedDirector]
			mov ecx, eax
			mov edx, [eax]
			call dword ptr[edx + 0x58]
			cmp byte ptr[eax + 0x31], 0x00
			je jp2
			push 0x00
			lea ecx, [edi - 0x000000F8]
			pushad
			push ebp
			mov ebp, esp
			call copyObject
			mov esp, ebp
			pop ebp
			popad
			call deleteObject
			pop edi
			pop esi
			mov ecx, [esp + 0x14]
			xor ecx, esp
			call loadCutShortcut_3
			mov esp, ebp
			pop ebp
			ret 0x0004
			jp1:
		jmp[loadCutShortcut_1]
			jp2 :
			jmp[loadCutShortcut_2]

	}
}
__declspec(naked) void XGDPS_creditsSkipIcons() {

	__asm {

		jmp[XGDPS_creditsSkipIconsJump]

	}
}
__declspec(naked) void XGDPS_creditsShowButton() {

	__asm {

		call dword ptr[edx + 0x000000E0]
		push XGDPS_creditsSpriteName
		call dword ptr[createWithSprite]
		mov esi, eax
		mov dword ptr ss : [esp], 0x3F800000
		mov ecx, esi
		mov edx, [esi]
		call dword ptr[edx + 0x50]
		push XGDPS_creditsFunction
		push ebx
		mov ecx, esi
		call createMenu
		mov esi, [esp + 0x20]
		add esp, 0x08
		mov ecx, esi
		mov edx, [esi]
		push eax
		call dword ptr[edx + 0x000000E0]
		jmp[retXGDPS_creditsShowButton]

	}
}
__declspec(naked) void XGDPS_creditsPosition() {

	__asm {

		push ebx
		push ecx
		mov ebx, [XGDPS_creditsPosition_multiplier]
		cvtsi2ss xmm1, ebx
		mulss xmm0, xmm1
		mov ebx, [XGDPS_creditsPosition_adjusterX]
		cvtsi2ss xmm1, ebx
		subss xmm0, xmm1
		mov ebx, [XGDPS_creditsPosition_splitAmount]
		dec ebx
		cmp eax, ebx
		jl jumpPoint1
		mov ecx, [XGDPS_creditsPosition_adjusterX2]
		cvtsi2ss xmm1, ecx
		movss[esp + 0x0C], xmm1
		inc ebx
		cvtsi2ss xmm1, ebx
		mov ecx, [XGDPS_creditsPosition_multiplier]
		cvtsi2ss xmm2, ecx
		mulss xmm1, xmm2
		subss xmm0, xmm1
		mov ecx, [XGDPS_creditsPosition_multiplier]
		cvtsi2ss xmm2, ecx
		divss xmm1, xmm1
		addss xmm1, xmm1
		divss xmm2, xmm1
		addss xmm0, xmm2
		jumpPoint1 :
		movss xmm1, [esp + 0x0C]
		mov ecx, [XGDPS_creditsPosition_adjusterY]
		cvtsi2ss xmm2, ecx
		subss xmm1, xmm2
		movss[esp + 0x0C], xmm1
		pop ecx
		pop ebx
		jmp [retXGDPS_creditsPosition]

	}
}
__declspec(naked) void XGDPS_creditsMain() {

	__asm {

		cmp eax, 0
		je credit_1_function
		cmp eax, 1
		je credit_2_function
		cmp eax, 2
		je credit_3_function
		cmp eax, 3
		je credit_4_function
		cmp eax, 4
		je credit_5_function
		cmp eax, 5
		je credit_6_function
		cmp eax, 6
		je credit_7_function
		cmp eax, 7
		je credit_8_function
		cmp eax, 8
		je credit_9_function
		cmp eax, 9
		je credit_10_function
		cmp eax, 0xA
		je credit_11_function
		jmp[XGDPS_creditsMain_returnNotFound]


		credit_1_function:
		push[XGDPS_creditsMain_credit_1_length]
			push XGDPS_creditsMain_credit_1_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_2_function :
		push[XGDPS_creditsMain_credit_2_length]
			push XGDPS_creditsMain_credit_2_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_3_function :
		push[XGDPS_creditsMain_credit_3_length]
			push XGDPS_creditsMain_credit_3_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_4_function :
		push[XGDPS_creditsMain_credit_4_length]
			push XGDPS_creditsMain_credit_4_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_5_function :
		push[XGDPS_creditsMain_credit_5_length]
			push XGDPS_creditsMain_credit_5_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_6_function :
		push[XGDPS_creditsMain_credit_6_length]
			push XGDPS_creditsMain_credit_6_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_7_function :
		push[XGDPS_creditsMain_credit_7_length]
			push XGDPS_creditsMain_credit_7_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_8_function :
		push[XGDPS_creditsMain_credit_8_length]
			push XGDPS_creditsMain_credit_8_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_9_function :
		push[XGDPS_creditsMain_credit_9_length]
			push XGDPS_creditsMain_credit_9_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_10_function :
		push[XGDPS_creditsMain_credit_10_length]
			push XGDPS_creditsMain_credit_10_string
			jmp[XGDPS_creditsMain_returnFound]

			credit_11_function :
		push[XGDPS_creditsMain_credit_11_length]
			push XGDPS_creditsMain_credit_11_string
			jmp[XGDPS_creditsMain_returnFound]

	}
}
__declspec(naked) void XGDPS_creditsMenuIcon() {

	__asm {

		push eax
		push XGDPS_creditsMenuIcon_string
		jmp[retXGDPS_creditsMenuIcon]

	}
}
__declspec(naked) void loadPointer() {

	__asm {

		pushad
		mov eax, createWithSprite_
		mov eax, [eax]
		mov[createWithSprite], eax
		mov eax, operatorPlus_
		mov eax, [eax]
		mov[operatorPlus], eax
		mov eax, floatCutButton_
		mov eax, [eax]
		mov[floatCutButton], eax
		mov eax, sharedDirector_
		mov eax, [eax]
		mov[sharedDirector], eax
		popad
		ret

	}
}

void writeByte(BYTE* address, BYTE content)
{
	DWORD oldProtect, newProtect;
	VirtualProtect(address, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	*address = content;
	VirtualProtect(address, 1, oldProtect, &newProtect);
}

void mainMod() {

	loadPointer();

	placeJMP((BYTE*)base + 0x77450, (DWORD)loadCutButton, 0x5);
	placeJMP((BYTE*)base + 0x91C04, (DWORD)loadCutShortcut, 0x5);
	
	placeJMP((BYTE*)base + 0x211187, (DWORD)loadModBadges, 0x5);
	placeJMP((BYTE*)base + 0x5FA21, (DWORD)loadModBadges2, 0x5);

	writeByte((BYTE*)base + 0x49762, 11);
	placeJMP((BYTE*)base + 0x4917D, (DWORD)XGDPS_creditsSkipIcons, 0x5);
	placeJMP((BYTE*)base + 0x190C3C, (DWORD)XGDPS_creditsShowButton, 0x5);
	placeJMP((BYTE*)base + 0x4964F, (DWORD)XGDPS_creditsPosition, 0x5);
	placeJMP((BYTE*)base + 0x495AE, (DWORD)XGDPS_creditsMain, 0x5);
	placeJMP((BYTE*)base + 0x495FC, (DWORD)XGDPS_creditsMenuIcon, 0x5);

}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)mainMod, hModule, 0, nullptr);

	case DLL_THREAD_ATTACH:


	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
