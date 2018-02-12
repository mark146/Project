#include <iostream>
#include <cmath>
using namespace std;//struct

const double PI = 3.141593;

struct C2d {//2���� ��ǥ
	double x, y;
};

struct Circle {//��
	C2d center;//�߽���ǥ
	double radius;//�ݰ�
};

double circleArea(Circle c) {//���� ������ ����
	return c.radius * c.radius * PI;
}

bool chkOverlap(Circle c1, Circle c2) {//�� ���� ���� ��ø�Ǵ��� �˻�
	double dx = c1.center.x - c2.center.x;
	double dy = c1.center.y - c2.center.y;
	double dCntr = sqrt(dx*dx + dy * dy);
	return dCntr < c1.radius + c2.radius;
}

void dispCircle(Circle c) {
	cout << " �߽�:(" << c.center.x << ", " << c.center.y << ")";
	cout << " �ݰ�:" << c.radius << endl;
}

int main() {
	Circle c1 = { {0,0},10 };//�߽�(0,0), �ݰ�10���� �ʱ�ȭ
	Circle c2 = { {30,10},5 };//�߽�(30,10), �ݰ�5�� �ʱ�ȭ

	cout << "��1" << endl;
	dispCircle(c1);
	cout << "��1�� ����" << circleArea(c1) << endl;
	cout << "��2" << endl;
	dispCircle(c2);
	cout << "��2�� ����" << circleArea(c2) << endl;

	//�� ���� ��ø ���� ���
	if (chkOverlap(c1, c2))
		cout << "�� ���� ��ø�˴ϴ�." << endl;
	else
		cout << "�� ���� ��ø���� �ʽ��ϴ�." << endl;
	getchar();
	return 0;
}