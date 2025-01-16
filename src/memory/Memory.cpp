#include "Memory.h"
#include <string> // For std::wstring

// Constructor that finds the PID and opens a handle
Memory::Memory(const wchar_t* processName) noexcept {

    ::PROCESSENTRY32 entry = {};
    entry.dwSize = sizeof(::PROCESSENTRY32);

    const HANDLE snapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    bool processFound = false;
    while (::Process32Next(snapShot, &entry)) {

        // Convert entry.szExeFile (char) to a wide string (wchar_t)
        wchar_t exeFileW[260]; // Match the size of entry.szExeFile
        ::MultiByteToWideChar(CP_ACP, 0, entry.szExeFile, -1, exeFileW, 260);

        // Compare the wide-character strings
        if (_wcsicmp(processName, exeFileW) == 0) {
            processId = entry.th32ProcessID;
            processFound = true;

            // OpenProcess gives us access to the process memory, threads and other resources
            processHandle = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
            break;
        }
    }

    if (snapShot)
        ::CloseHandle(snapShot);
}

// Destructor that frees the opened handle
Memory::~Memory() {
    if (processHandle)
        ::CloseHandle(processHandle);
}

// Returns the base address of a specified module (DLL), or 0 if not found
const std::uintptr_t Memory::GetModuleAddress(const wchar_t* moduleName) const noexcept {

    ::MODULEENTRY32 entry = {};
    entry.dwSize = sizeof(::MODULEENTRY32);

    const auto snapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);

    std::uintptr_t result = 0;
    while (::Module32Next(snapShot, &entry)) {

        // Convert entry.szModule (char) to a wide string (wchar_t)
        wchar_t moduleW[256]; // Match the size of entry.szModule
        ::MultiByteToWideChar(CP_ACP, 0, entry.szModule, -1, moduleW, 256);

        // Compare the wide-character strings
        if (_wcsicmp(moduleName, moduleW) == 0) {
            result = reinterpret_cast<std::uintptr_t>(entry.modBaseAddr);
            break;
        }

    }

    if (snapShot)
        ::CloseHandle(snapShot);

    return result;
}
