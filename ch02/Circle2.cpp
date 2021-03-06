#include <iostream>
#include <cmath>
using namespace std;//class

const double PI = 3.141593;

struct C2d {//2차원 좌표
	double x, y;
};

class CircleClass {//원
	C2d center;//중심좌표
	double radius;//반경
public:
	void init(double cx, double cy, double r) {// 중심 (cx, cy), 반경 r로 원을 초기화
		center.x = cx;
		center.y = cy;
		radius = r;
	}

	double area() const {//원의 면적 계산
		return radius * radius * PI;
	}

	bool chkOverlap(const CircleClass& c) const {//두 원이 서로 중첩되는지 검사
		double dx = c.center.x - c.center.x;
		double dy = c.center.y - c.center.y;
		double dCntr = sqrt(dx*dx + dy * dy);
		return dCntr < radius + c.radius;
	}

	void display() const {//원 객체의 정보 디스플레이
		cout << " 중심:(" << center.x << ", " << center.y << ")";
		cout << " 반경:" << radius << endl;
	}
};

int main() {
	CircleClass c1, c2;
	c1.init(0, 0, 10); //중심(0,0), 반경10으로 초기화
	c2.init(30, 10, 5);//중심(30,10), 반경 5로 초기화

	cout << "원1" << endl;
	c1.display();
	cout << "원1의 면적" << c1.area() << endl;
	cout << "원2" << endl;
	c2.display();
	cout << "원2의 면적" << c2.area() << endl << endl;

	//두 원의 중첩 여부 출력
	if (c1.chkOverlap(c2))
		cout << "두 원은 중첩됩니다." << endl;
	else
		cout << "두 원은 중첩되지 않습니다." << endl;
	getchar();
	return 0;
}