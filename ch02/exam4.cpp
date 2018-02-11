#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int *ptr;

	ptr = &a;
	cout << "ptr가 가리키는 값: " << *ptr << endl;
	*ptr = 20;
	cout << "변수 a의 값: " << a << endl;

	getchar();
	return 0;
}