#pragma once
#include <iostream>
#include <windows.h>

namespace mem {
	uintptr_t GetProcId(const char* procName);
	bool isProcessRunning(const char* procname);
	void stopMonitoring();

}
