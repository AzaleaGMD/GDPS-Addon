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

DWORD floatCutButton = base + 0x2E62F8; // USE AS A POINTER
DWORD floatCutButton_ = (DWORD)floatCutButton;

DWORD arrangeMenu = base + 0x19080;

DWORD GJ_PasteBtn2_001 = base + 0x29870C;

DWORD copyObject = base + 0x87FB0;
DWORD deleteObject = base + 0x7BF50;

DWORD retLoadCutButton = base + 0x77455;

DWORD retLoadModBadges = base + 0x211191;
DWORD retLoadModBadges2 = base + 0x5FA2B;

BYTE valueModBadges = 0;

char cutButtonSpriteChar[21] = "GJ_cutButton_001.png";

char modBadgesStringChar[20] = "modBadge_01_001.png";

DWORD cutButtonSprite = (DWORD)cutButtonSpriteChar;

DWORD modBadgesString = (DWORD)modBadgesStringChar;


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
		popad
		ret

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

__declspec(naked) void loadModBadges() {

	__asm {

		pushad
		mov eax, [eax + 0x000001D4]
		add eax, 48
		mov ecx, modBadgesString
		add ecx, 10
		mov [ecx], al
		inc ecx
		mov dword ptr [ecx], 0x3130305F
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

void mainMod() {
	loadPointer();
	placeJMP((BYTE*)base + 0x77450, (DWORD)loadCutButton, 0x5);
	placeJMP((BYTE*)base + 0x211187, (DWORD)loadModBadges, 0x5);
	placeJMP((BYTE*)base + 0x5FA21, (DWORD)loadModBadges2, 0x5);
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