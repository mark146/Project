#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int *ptr;

	ptr = &a;
	cout << "ptr�� ����Ű�� ��: " << *ptr << endl;
	*ptr = 20;
	cout << "���� a�� ��: " << a << endl;

	getchar();
	return 0;
}