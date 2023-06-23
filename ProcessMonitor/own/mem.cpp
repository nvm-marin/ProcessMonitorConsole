#include "mem.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

void mem::stopMonitoring() {
	exit(0);
}

uintptr_t mem::GetProcId(const char* procName) {
	uintptr_t procId = 0;
	//We make a snapshot to all proccesses
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE) {
		//We create a PROCESSENTRY32 struct
		PROCESSENTRY32 procEntry;
		//We set the size of the struct
		procEntry.dwSize = sizeof(procEntry);
		//We loop through all proccessess
		if (Process32First(hSnap, &procEntry)) {
			do {
				//We use wProcName to store the process name
				//We use MAX_PATH to set the max length of the process name
				WCHAR wProcName[MAX_PATH];
				//We use MultiByteToWideChar to convert the char* to wchar_t*
				MultiByteToWideChar(CP_ACP, 0, procName, -1, wProcName, MAX_PATH);
				if (_wcsicmp(procEntry.szExeFile, wProcName) == 0) {
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	//We close the handle and return the process id
	CloseHandle(hSnap);
	return procId;
}

bool mem::isProcessRunning(const char* procname) {
	bool exists = false;
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hsnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 procentry;
		procentry.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hsnap, &procentry)) {
			do {
				WCHAR wProcName[MAX_PATH];
				MultiByteToWideChar(CP_ACP, 0, procname, -1, wProcName, MAX_PATH);

				if (_wcsicmp(procentry.szExeFile, wProcName) == 0) {
					exists = true;
					break;
				}
			} while (Process32Next(hsnap, &procentry));
		}
	}
	CloseHandle(hsnap);
	return exists;
}