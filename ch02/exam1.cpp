#include <iostream>

using namespace std;//struct

struct Vo {
	double x, y;
};

int main() {
	int x, y;
	cout << "정수값을 2개 입력하시오: \n";
	cin >> x >> y;
	Vo v = { x, y };
	cout << "입력값 = (" << v.x << ", " << v.y << ")";

	getchar();
	getchar();
	return 0;
}