#include <iostream>

using namespace std;//struct

struct Vo {
	double x, y;
};

int main() {
	int x, y;
	cout << "�������� 2�� �Է��Ͻÿ�: \n";
	cin >> x >> y;
	Vo v = { x, y };
	cout << "�Է°� = (" << v.x << ", " << v.y << ")";

	getchar();
	getchar();
	return 0;
}