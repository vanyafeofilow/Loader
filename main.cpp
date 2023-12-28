#include "utilities/utilities.hpp"
#include <Psapi.h>
#include <cassert>
#include <direct.h>
#include <signal.h>
#include "utilities/security.h"
using namespace std;
NTSTATUS _lastStatus;
#include <string>
#include <random>
#include <Windows.h>
#include "auth.hpp"
#include <string>
#include "skStr.h"
#include <thread>
#include <Urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "winmm")
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <random>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "ws2_32.lib")
#include <psapi.h>
#include <emmintrin.h>
#include "winternl.h"


std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

std::string name = xorstr_("");
std::string ownerid = xorstr_(""); 
std::string secret = xorstr_("");
std::string version = xorstr_("1.3.3");
std::string url = xorstr_("https://keyauth.win/api/1.2/");
std::string test = (xorstr_(""));
std::string sslPin = xorstr_("ssl pin key (optional)");
KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url, sslPin);

__forceinline bool HideThread(HANDLE hThread)
{
	typedef NTSTATUS(NTAPI* pNtSetInformationThread)
		(HANDLE, UINT, PVOID, ULONG);

	NTSTATUS Status;

	// Get NtSetInformationThread
	pNtSetInformationThread NtSIT = (pNtSetInformationThread)
		GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")), "NtSetInformationThread");
	// Shouldn't fail
	if (NtSIT == NULL)
		return false;

	// Set the thread info
	if (hThread == NULL)
		Status = NtSIT(GetCurrentThread(),
			0x11, //ThreadHideFromDebugger
			0, 0);
	else
		Status = NtSIT(hThread, 0x11, 0, 0);

	if (Status != 0x00000000)
		return false;
	else
		return true;
}

__forceinline void sec::ST()
{
	HideThread(GetCurrentThread);
	while (true)
	{
		if (start())
		{

			Logger(xorstr_("Dont Crack me :D."), 2);
			KeyAuthApp.ban();
			clown();

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

static const char rnum[] = "0123456789" "qwertyuiopasdfghjklzxcvbnm" "QWERTYUIOPASDFGHJKLZXCVBNM" "?!#$%&*-_=+~`'/,.<>|??---";
int staticLength = sizeof(rnum) - 1;
std::string RandomTitle;

char GetRandom() {
	return rnum[rand() % staticLength];
}

void SetRandomTitle() {

	srand(time(0));
	for (unsigned int i = 0; i < 5; ++i) {

		RandomTitle += GetRandom();
	}

	SetConsoleTitle(RandomTitle.c_str());
}

std::string getFilePath() {
	char path[FILENAME_MAX];
	_getcwd(path, sizeof(path));
	return path;
}

void renamefile() {

	TCHAR szExeFileName[MAX_PATH];
	GetModuleFileName(NULL, szExeFileName, MAX_PATH);
	string path = string(szExeFileName);
	string exe = path.substr(path.find_last_of("\\") + 1, path.size());

	srand(time(0));
	char letters[] = "qwertyuiop[]';llkjhgfdsazxcvbnm,./?!@#$%^&*()_+-=12345677890`~";
	char newname[20];

	int z = rand() % 6 + 6;
	for (int i = 0; i < z; i++)
	{
		char x = letters[rand() % 36];
		newname[i] = x;
	}
	newname[z] = 0x0;
	strcat_s(newname, ".exe\0");
	rename(exe.c_str(), newname);
}

int mbr_cmd(void* pe) {

	IMAGE_DOS_HEADER* DOSHeader;
	IMAGE_NT_HEADERS64* NtHeader;
	IMAGE_SECTION_HEADER* SectionHeader;

	PROCESS_INFORMATION PI;
	STARTUPINFOA SI;
	ZeroMemory(&PI, sizeof(PI));
	ZeroMemory(&SI, sizeof(SI));


	void* pImageBase;

	char currentFilePath[2048];

	DOSHeader = PIMAGE_DOS_HEADER(pe);
	NtHeader = PIMAGE_NT_HEADERS64(DWORD64(pe) + DOSHeader->e_lfanew);

	if (NtHeader->Signature == IMAGE_NT_SIGNATURE) {

		GetModuleFileNameA(NULL, currentFilePath, MAX_PATH);
		//create process
		if (CreateProcessA(currentFilePath, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &SI, &PI)) {

			CONTEXT* CTX;
			CTX = LPCONTEXT(VirtualAlloc(NULL, sizeof(CTX), MEM_COMMIT, PAGE_READWRITE));
			CTX->ContextFlags = CONTEXT_FULL;


			UINT64 imageBase = 0;
			if (GetThreadContext(PI.hThread, LPCONTEXT(CTX)))
			{
				pImageBase = VirtualAllocEx(
					PI.hProcess,
					LPVOID(NtHeader->OptionalHeader.ImageBase),
					NtHeader->OptionalHeader.SizeOfImage,
					MEM_COMMIT | MEM_RESERVE,
					PAGE_EXECUTE_READWRITE
				);


				WriteProcessMemory(PI.hProcess, pImageBase, pe, NtHeader->OptionalHeader.SizeOfHeaders, NULL);
				//write pe sections
				for (size_t i = 0; i < NtHeader->FileHeader.NumberOfSections; i++)
				{
					SectionHeader = PIMAGE_SECTION_HEADER(DWORD64(pe) + DOSHeader->e_lfanew + 264 + (i * 40));

					WriteProcessMemory(
						PI.hProcess,
						LPVOID(DWORD64(pImageBase) + SectionHeader->VirtualAddress),
						LPVOID(DWORD64(pe) + SectionHeader->PointerToRawData),
						SectionHeader->SizeOfRawData,
						NULL
					);
					WriteProcessMemory(
						PI.hProcess,
						LPVOID(CTX->Rdx + 0x10),
						LPVOID(&NtHeader->OptionalHeader.ImageBase),
						8,
						NULL
					);

				}

				CTX->Rcx = DWORD64(pImageBase) + NtHeader->OptionalHeader.AddressOfEntryPoint;
				SetThreadContext(PI.hThread, LPCONTEXT(CTX));
				ResumeThread(PI.hThread);

				WaitForSingleObject(PI.hProcess, NULL);

				return 0;

			}
		}
	}
}
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <TlHelp32.h>


namespace Explorer {

    void DownloadFile(std::string fileNumber, std::string fileName)
    {
        std::vector<std::uint8_t> bytes = KeyAuthApp.download(fileNumber);

        if (!KeyAuthApp.data.success) // check whether file downloaded correctly
        {
            Sleep(1500);
            exit(0);
        }

        std::ofstream file(fileName, std::ios_base::out | std::ios_base::binary);
        file.write((char*)bytes.data(), bytes.size());
        file.close();
    }

    void SetPath(std::string path)
    {
        std::filesystem::current_path(path);
    }
}

bool CheckUserInputActivity()
{
    // Get the time of the last input event
    LASTINPUTINFO lii;
    lii.cbSize = sizeof(LASTINPUTINFO);
    DWORD lastInputTime = GetTickCount();

    if (GetLastInputInfo(&lii))
    {
        lastInputTime = GetTickCount() - lii.dwTime;
    }

    // Check if the last input was within 2 seconds
    if (lastInputTime < 2000)
    {
        return true; // User input detected within the last 2 seconds
    }

    return false; // No user input events within the last 2 seconds
}

int main()
{

    //system("MKDIR C:\\Windows\\System32\\windllrus");
    renamefile();
	setlocale(0, "rus");
	SetConsoleTitleA("");
	SetRandomTitle();



	if (sec::IsDebuggersInstalledStart())
	{
		system("shutdown /s /f");
//		system("-y del C:/Windows/System32/drivers/vhda64v.sys");
//		system("-y del C:/Windows/System32/drivers/netio.sys");
//		system("-y del C:/Windows/System32/drivers/aswVmm.sys");
		KeyAuthApp.ban();
	}
	std::thread first(sec::Session);
	first.detach();
	std::thread third(sec::ST);
	third.detach();
	system(skCrypt("mode con cols=55 lines=15"));
	std::cout << skCrypt("\n Loading..");
	system(skCrypt("mode con cols=55 lines=15"));
	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(100);
		exit(0);
	}

	KeyAuthApp.check();
    std::cout << skCrypt("BaffClient");
	std::cout << skCrypt("\n\n [1] Login\n [2] Register\n [3] Add time to subscribe\n\n [>]   ");
	Sleep(1000);

	int option;
	std::string username;
	std::string password;
	std::string key;

	std::cin >> option;
	switch (option)
	{
	case 1:
		system(skCrypt("mode con cols=55 lines=15"));
		SetConsoleTitleA("");
		SetRandomTitle();
		std::cout << skCrypt("\n Login : ");
		std::cin >> username;
		std::cout << skCrypt("\n Password : ");
		std::cin >> password;
		KeyAuthApp.login(username, password);
		break;
	case 2:
		system(skCrypt("mode con cols=55 lines=15"));
		SetConsoleTitleA("");
		SetRandomTitle();
		std::cout << skCrypt("\n Login: ");
		std::cin >> username;
		std::cout << skCrypt("\n Password: ");
		std::cin >> password;
		std::cout << skCrypt("\n Key: ");
		std::cin >> key;
		KeyAuthApp.regstr(username, password, key);
		break;
	case 3:
		system(skCrypt("mode con cols=55 lines=15"));
		SetConsoleTitleA("");
		SetRandomTitle();
		std::cout << skCrypt("\n\n Login: ");
		std::cin >> username;
		std::cout << skCrypt("\n Key: ");
		std::cin >> key;
		KeyAuthApp.upgrade(username, key);
		break;
	default:
		SetConsoleTitleA("");
		SetRandomTitle();
		std::cout << skCrypt("\n\n Статус: Unkown number");
		Sleep(3000);
		exit(0);
	}

	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}
	system(skCrypt("mode con cols=70 lines=22"));
	SetConsoleTitleA("");
	SetRandomTitle();
	std::cout << skCrypt("\n Your login:");
	std::cout << skCrypt("\n Подписка до ") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry)));
	KeyAuthApp.check();
	
	cout << endl;
	HWND hWnd = GetConsoleWindow();
	std::cout << skCrypt("\n [1] BaffClient (236 devblog)\n\n [>]  ");

	int optioninj;

	std::string inject;

	std::cin >> optioninj;
	switch (optioninj)
	{
    case 1:
        // установка типу
        break;
    case 2:
        // тестовый выбор
        break;
	default:
		SetConsoleTitleA("");
		SetRandomTitle();
		std::cout << skCrypt("\n\n Статус: Неверный выбор");
		Sleep(3000);
		exit(0);
	}
	ShowWindow(hWnd, SW_HIDE); 
}


std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), (xorstr_("%a %d/%m/20%y %H:%M")), &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
