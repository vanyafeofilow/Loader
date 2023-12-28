#include "pch.h"
#include "ScyllaHideDetector.h"

void ntdll_unhooking()
{
	auto ntdll = GetModuleBaseAddress(L"ntdll.dll");
	PVOID ntdll_mapped = nullptr;
	MapNativeModule("ntdll.dll", &ntdll_mapped);

	// NtYieldExecution
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtYieldExecution");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtYieldExecution");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtYieldExecution>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtSetInformationThread
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtSetInformationThread");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtSetInformationThread");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		using NtSetInformationThread = NTSTATUS(NTAPI*)();
		reinterpret_cast<NtSetInformationThread>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtSetInformationProcess
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtSetInformationProcess");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtSetInformationProcess");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtSetInformationProcess>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtQuerySystemInformation
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtQuerySystemInformation");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtQuerySystemInformation");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtQuerySystemInformation_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtQueryInformationProcess
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtQueryInformationProcess");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtQueryInformationProcess");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtQueryInformationProcess_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtQueryObject
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtQueryObject");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtQueryObject");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtQueryObject_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtCreateThreadEx
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtCreateThreadEx");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtCreateThreadEx");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtCreateThreadEx>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtSetDebugFilterState
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtSetDebugFilterState");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtSetDebugFilterState");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtSetDebugFilterState>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtClose
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtClose");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtClose");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}

		reinterpret_cast<NtClose_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtQueryPerformanceCounter
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtQueryPerformanceCounter");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtQueryPerformanceCounter");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		reinterpret_cast<NtQueryPerformanceCounter_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtGetContextThread
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtGetContextThread");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtGetContextThread");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		reinterpret_cast<NtGetContextThread_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtSetContextThread
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtSetContextThread");
		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto original_func = GetProcedureAddress(ntdll_mapped, "NtSetContextThread");

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		reinterpret_cast<NtSetContextThread_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// NtQuerySystemTime
	try
	{
		auto hooked_func = GetProcedureAddress(ntdll, "NtQuerySystemTime");
		if (*(PUCHAR)hooked_func == 0xE9) // jmp rel32
		{
			LONG relativeOffset = *(PLONG)((ULONG_PTR)hooked_func + 1);
			hooked_func = (NtQuerySystemTime_t)((ULONG_PTR)hooked_func + relativeOffset + 5);
		}
		auto original_func = GetProcedureAddress(ntdll_mapped, "NtQuerySystemTime");

		if (*(PUCHAR)original_func == 0xE9) // jmp rel32
		{
			LONG relativeOffset = *(PLONG)((ULONG_PTR)original_func + 1);
			original_func = (NtQuerySystemTime_t)((ULONG_PTR)original_func + relativeOffset + 5);
		}

		auto func_data = RtlLookupFunctionEntry((DWORD64)hooked_func, (DWORD64*)&ntdll, nullptr);
		auto func_size = func_data->EndAddress - func_data->BeginAddress;

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (result != func_size)
		{
			DWORD oldprotect = 0;
			VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (result == func_size)
			{
				VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		LARGE_INTEGER time;
		reinterpret_cast<NtQuerySystemTime_t>(hooked_func)(&time);
	}
	catch (...)
	{
	}
}

__forceinline void kernelbase_unhooking()
{
	auto kernelbase = GetModuleBaseAddress("kernelbase.dll");
	PVOID kernelbase_mapped = nullptr;
	MapNativeModule("kernelbase.dll", &kernelbase_mapped);

	// GetTickCount
	try
	{
		auto hooked_func = GetProcedureAddress(kernelbase, "GetTickCount");

		auto original_func = GetProcedureAddress(kernelbase_mapped, "GetTickCount");

		auto func_size = 0x18;

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (static_cast<int>(result) != func_size)
		{
			DWORD oldprotect = 0;
			hash_VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (static_cast<int>(result) == func_size)
			{
				hash_VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		reinterpret_cast<GetTickCount_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// GetTickCount64
	try
	{
		auto hooked_func = GetProcedureAddress(kernelbase, "GetTickCount64");

		auto original_func = GetProcedureAddress(kernelbase_mapped, "GetTickCount64");

		auto func_size = 0x18;

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook
		if (static_cast<int>(result) != func_size)
		{
			DWORD oldprotect = 0;
			hash_VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (static_cast<int>(result) == func_size)
			{
				hash_VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		reinterpret_cast<GetTickCount64_t>(hooked_func)();
	}
	catch (...)
	{
	}

	// OutputDebugStringA
	try
	{
		auto hooked_func = GetProcedureAddress(kernelbase, "OutputDebugStringA");

		auto original_func = GetProcedureAddress(kernelbase_mapped, "OutputDebugStringA");

		auto func_size = 0x18;

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (static_cast<int>(result) != func_size)
		{
			DWORD oldprotect = 0;
			hash_VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (static_cast<int>(result) == func_size)
			{
				hash_VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		reinterpret_cast<OutputDebugStringA_t>(hooked_func)("");
	}
	catch (...)
	{
	}

	// GetLocalTime
	try
	{
		auto hooked_func = GetProcedureAddress(kernelbase, "GetLocalTime");

		auto original_func = GetProcedureAddress(kernelbase_mapped, "GetLocalTime");

		auto func_size = 0x18;

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (static_cast<int>(result) != func_size)
		{
			DWORD oldprotect = 0;
			hash_VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (static_cast<int>(result) == func_size)
			{
				hash_VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		SYSTEMTIME sm;
		reinterpret_cast<GetLocalTime_t>(hooked_func)(&sm);
	}
	catch (...)
	{
	}

	// GetSystemTime
	try
	{
		auto hooked_func = GetProcedureAddress(kernelbase, "GetSystemTime");

		auto original_func = GetProcedureAddress(kernelbase_mapped, "GetSystemTime");

		auto func_size = 0x18;

		auto result = RtlCompareMemory(hooked_func, original_func, func_size);

		// detect hook and restore bytes
		if (static_cast<int>(result) != func_size)
		{
			DWORD oldprotect = 0;
			hash_VirtualProtect(hooked_func, func_size, PAGE_EXECUTE_READWRITE, &oldprotect);

			RtlCopyMemory(hooked_func, original_func, func_size);

			result = RtlCompareMemory(hooked_func, original_func, func_size);
			if (static_cast<int>(result) == func_size)
			{
				hash_VirtualProtect(hooked_func, func_size, oldprotect, &oldprotect);
			}
		}
		SYSTEMTIME sm;
		reinterpret_cast<GetSystemTime_t>(hooked_func)(&sm);
	}
	catch (...)
	{
	}
}
