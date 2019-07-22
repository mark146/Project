#include "pch.h"
#include <iostream>

using namespace std;

//파일 핸들링
int main()
{
	FILE *pFile = NULL;
	pFile = fopen("c:\\IMSI\\b.txt", "r");

	char strTemp[255];

	while (!feof(pFile)) {
		fgets(strTemp, sizeof(strTemp), pFile);
		//printf("%s", strTemp);
		cout << strTemp;
	}

	fclose(pFile);

	return 0;
}