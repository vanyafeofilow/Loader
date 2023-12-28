#pragma once

BOOL IsWoW64();
PVOID64 GetPeb64();
BOOL Is_RegKeyValueExists(HKEY hKey, const TCHAR* lpSubKey, const TCHAR* lpValueName, const TCHAR* search_str);
BOOL Is_RegKeyExists(HKEY hKey, const TCHAR* lpSubKey);
BOOL check_mac_addr(const TCHAR* szMac);
BOOL SetPrivilege(HANDLE, LPCTSTR, BOOL);
BOOL SetDebugPrivileges(VOID);
ULONG get_idt_base();
ULONG get_ldt_base();
ULONG get_gdt_base();
BOOL IsElevated();
BOOL find_str_in_data(PBYTE needle, size_t needleLen, PBYTE haystack, size_t haystackLen);
UINT enum_system_firmware_tables(_In_ DWORD FirmwareTableProviderSignature, _Out_ PVOID pFirmwareTableBuffer, _In_ DWORD BufferSize);
PBYTE get_system_firmware(_In_ DWORD signature, _In_ DWORD table, _Out_ PDWORD pBufferSize);
bool attempt_to_read_memory(void* addr, void* buf, int size);
bool attempt_to_read_memory_wow64(PVOID buffer, DWORD size, PVOID64 address);
bool attempt_to_read_memory_wow64(PVOID buffer, DWORD size, ULONGLONG address);
std::vector<PMEMORY_BASIC_INFORMATION>* enumerate_memory();
std::vector<PMEMORY_BASIC_INFORMATION64>* enumerate_memory_wow64();

#define	MALLOC(x)	hash_HeapAlloc(hash_GetProcessHeap(), 0, x)
#define FREE(x)		hash_HeapFree(hash_GetProcessHeap(), 0, x)

#if _WIN32 || _WIN64
#if _WIN64
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif