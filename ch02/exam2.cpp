#include <iostream>
#include <cmath>
using namespace std;//class


class Test {
	int x, y;

public:
	void init() {
		cout << "정수값을 2개 입력하시오: \n";
		cin >> x >> y;
		cout << "입력값:(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	Test t;
	
	t.init();

	getchar();
	return 0;
}