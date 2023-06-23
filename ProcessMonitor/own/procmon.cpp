#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include<TlHelp32.h>
#include "mem.h"
int result{ 0 };

int main() {
	//Create a proccess monitor list (and change the process names to the ones you want to monnitor or you can add more)
	std::vector<std::string> proccessestomon = { "valorant.exe", "discord.exe", "rdr2.exe", "steam.exe" };
	//This function it's used to hid the console windows, if you want to see the console window just comment this line
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	while (true) {
		//Loop through the list and check if the proccess is running
		for (int i = 0; i < proccessestomon.size(); i++) {
			//Check if the proccess is running
			if (mem::isProcessRunning(proccessestomon[i].c_str())) {
				//If yes we have to remind the user to work
			
				 result = 1;
				/*
				UNCOMMENT IF YOU WANT TO SEE THE PROCESSES THAT ARE RUNNING + SHOWINDOW  FUNC IS COMMENTED
				std::cout << "Process: " << proccessestomon[i].c_str() << " Is Running" << std::endl;

				*/
				 //You can comment this line if you don't want to see the message box
				 MessageBox(NULL, L"Wake up, you should be working", L"Wake up", MB_OK | MB_ICONWARNING);
				 //We get the process id
				 uintptr_t pid = mem::GetProcId(proccessestomon[i].c_str());
				 //We make a handle to the process so we can terminate it after
				 HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
				 //We terminate the process
				 TerminateProcess(hProcess, 0);
			}
			else {
				//Function, nothing in my case
			     result = 0;
			}
		}
		Sleep(1000);
		if (GetAsyncKeyState(VK_ESCAPE)) {
			//So because it's not a gui app we have to use this function, we chec if Escape key was pressed so we will be able to terminate the process of this app (own.exe)

			mem::stopMonitoring();
		}
		/*
		UNCOMMENT IF YOU WANT TO SEE THE PROCESSES THAT ARE RUNNING + SHOWINDOW  FUNC IS COMMENTED
		if (result == 0) {
		 
			std::cout<<"You are working" << std::endl;
		}*/
	}

}