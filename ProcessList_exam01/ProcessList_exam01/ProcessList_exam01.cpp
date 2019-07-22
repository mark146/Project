#include "pch.h"
#include <iostream>

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <tlhelp32.h>

using namespace std;

//ProcessList 출력
int main()
{
	PROCESSENTRY32 pe32;
	HANDLE hProcess;
	static int count = 0;
	char str[50];
	hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hProcess, &pe32)) {
		do {
			printf("Parent = %Id Process ID = %Id Process Name = %ls\n", pe32.th32ParentProcessID, pe32.th32ProcessID, pe32.szExeFile);
			//cout << "Parent = " << pe32.th32ParentProcessID  << " Process ID = " << pe32.th32ProcessID  << " Process Name = " << pe32.szExeFile << endl;
			sprintf(str, "%ls", pe32.szExeFile);
			count++;
		} while (Process32Next(hProcess, &pe32));
	}

	_getch();

	CloseHandle(hProcess);

	return 0;
}