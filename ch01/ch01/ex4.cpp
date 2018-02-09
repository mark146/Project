#include <iostream>
using namespace std;

void main() {
	int n[3];
	int n2[8][5];
	
	int size = sizeof(n) / sizeof(n[0]);//sizeof(int);

	cout << "배열 크기 : " << size << endl;
	
	int row = sizeof(n2) / sizeof(n2[0]);

	int col = sizeof(n2[0]) / sizeof(sizeof(n2[0][0]));

	cout << "행의 갯수 row : " << row << ", 열의 갯수 col : " << col << endl;

	for (int i = 0; i < 3; i++) {
		cout << "n[" << i << "] 입력 : "; cin >> n[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << "n[" << i << "] 값 : " << n[i] << endl;
	}

	getchar();
	getchar();	
}