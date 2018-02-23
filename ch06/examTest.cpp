#include <iostream>
#include "iExam.h"
using namespace std;


class test1 {
public:
	void init() {
		Pencils p1(5, 7);
		Pencils p2(23);

		printf("exam1 \n");

		p1.display();
		(++p1).display();
		p1.display();
		cout << endl;
		p2.display();
		p1 = p2++;
		p1.display();
		p2.display();
		cout << endl;
	}
};

class test2 {
public:
	void init() {
		MyString str1("MyString class");
		MyString str2("Object Oriented");
		MyString str3;

		printf("exam2 \n");

		cout << str1 << endl;
		str3 = "Programming";//문자열 대입 연산자 - 자동 형 변환
		cout << str3 << "의 문자열 길이는 ";
		cout << str3.length() << endl;//문자열 길이를 구하는 메소드
		str1 = str2;//대입 연산자로 문자열 복사
		cout << str1 << endl;
		str1 = str2 + str3; // 문자열 연결 연산자
		cout << str1 << endl;
		MyString str4(str3); // 복사 생성자 이용
		cout << str4 << endl;
		str2 += "Programming"; //+= 연산자 이용
		cout << str2 << endl;
		str2[6] = '-'; //[]연산자 이용
		cout << str2 << endl;
		cout << endl;
	}
};


class test3 {
public:
	void init() {
		Meter mLen(10, 50);
		Feet fLen = mLen;

		printf("exam3 \n");

		mLen.display();
		fLen.display();
		
	}
};

int main() {
	test1 t1;
	test2 t2;
	test3 t3;

	t1.init();
	t2.init();
	t3.init();

	getchar();
	return 0;
}