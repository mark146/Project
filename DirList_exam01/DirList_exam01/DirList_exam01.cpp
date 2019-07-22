#include "pch.h"
#include <iostream>
#include <stdio.h>

#include <windows.h>
#include "fileapi.h"
#include <tchar.h>

//디렉토리 List 출력 
//cmd = dir /s	
int main()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char path[255];
	strcpy(path, "C:\\*");
	wchar_t wpath[255];
	mbstowcs(wpath, path, strlen(path) + 1);
	hFind = FindFirstFileW(wpath, &FindFileData);

	do {
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			_tprintf(__TEXT("%s <DIR> \n"), FindFileData.cFileName);
		}
		else {
			_tprintf(__TEXT("%s\n"), FindFileData.cFileName);
		}
	} while (FindNextFile(hFind, &FindFileData) != 0);

	FindClose(hFind);

	return 0;
}