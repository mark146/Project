#include <iostream>
#include <cmath>
using namespace std;//class


class Test {
	int x, y;

public:
	void init() {
		cout << "�������� 2�� �Է��Ͻÿ�: \n";
		cin >> x >> y;
		cout << "�Է°�:(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	Test t;
	
	t.init();

	getchar();
	return 0;
}