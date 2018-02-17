#include <iostream>
#include <cstring>
#include "exam.h"

using namespace std;

class test1 {
private: 
	Counter cnt;//디폴트 private

public:
	void init() {

		printf("exam1 \n");
		
		cout << "계수기의 현재 값 = " << cnt.getValue() << endl;
		cnt.count();
		cnt.count();
		cout << "계수기의 현재 값 = " << cnt.getValue() << endl << endl;
	}
};



Person::Person(const char *name, const char *addr) {
	this->name = new char[strlen(name) + 1];//이름을 저장할 공간 할당
	strcpy(this->name, name);// 데이터 멤버 name에 이름을 복사
	this->addr = new char[strlen(addr) + 1];//주소를 저장할 공간 할당
	strcpy(this->addr, addr);//데이터 멤버 addr에 주소를 복사
	cout << "Person 객체 생성함(" << name << ")" << endl;
}

Person::~Person() {
	cout << "Person 객체 제거함(" << name << ")" << endl;
	delete[] name;
	delete[] addr;
}

void Person::print() const {
	cout << addr << " 에 사는 " << name << " 입니다 " << endl;
}

void Person::chAddr(const char* newAddr) {
	delete[] addr; //기존 공간 반납
	addr = new char[strlen(newAddr) + 1];//새로운 주소에 맞는 공간 할당
	strcpy(addr, newAddr);//데이터 멤버 addr에 새로운 주소를 복사
}

class test2 {
		Person *p1 = new Person("이철수","서울시 종로구");//디폴트 private
		Person *p2 = new Person("박은미", "강원도 동해시");

public:
	void init() {

		printf("exam2 \n");

		p1->print();
		p2->print();
		cout << endl << "주소 변경: ";
		p2->chAddr("대전시 서구");
		p2->print();
		delete p1;
		delete p2;
	}

};



NamedObj::NamedObj(const char *s) {
	name = new char[strlen(s) + 1];//문자열을 복사할 공간을 할당
	strcpy(name, s);
	id = ++nConstr;//생성된 객체의 수를 증가시키고 이를 ID로 부여
}

NamedObj::~NamedObj() {
	++nDestr;//소멸된 객체의 수를 증가시킴.
	delete[] name;
}

//static 데이터 멤버의 정의 및 초기화
int NamedObj::nConstr = 0;
int NamedObj::nDestr = 0;


class test3 {
public:
	void f() {
		NamedObj x("Thrird");//세 번째 객체의 생성
		x.display();//함수 반환 후 x는 소멸됨.
	}

	void init() {
		printf("exam3 \n");
		cout << "NamedObj 클래스의 객체 수:" << NamedObj::nObj() << endl;
		NamedObj a("First");//첫 번째 객체 생성
		NamedObj b("Second");//두 번째 객체 생성
		a.display();
		b.display();
		f();
		NamedObj c("Fourth");
		c.display();
		cout << "NamedObj 클래스의 객체 수:" << NamedObj::nObj() << endl;
	}
};



bool CharStack::push(char ch) {
	if (chkFull()) {
		cout << "스택이 가득 차 있습니다." << endl;
	 return false;
	}
	buf[--top] = ch;//스택에 공간이 있으면 저장
	return true;
}

char CharStack::pop() {
	if (chkEmpty()) {
		cout << "스택에 데이터가 없습니다." << endl;
		return 0;
	}
	return buf[top++];//top 위치의 데이터 반환
}



class test4 {
	CharStack chStack;//20개의 문자를 저장할 수 있는 스택
	char str[20];

public:
	void init() {
		cout << "영어 단어를 입력하시오:";
		cin >> str;

		char* pt = str;//포인터로 문자열 시작 위치를 가리킴.
		while (*pt) //문자열의 끝이 아니면 반복
			chStack.push(*(pt++));//스택에 문자를 넣음.
		cout << "역순 단어 출력:";
		while (!chStack.chkEmpty()) //스택이 비어 있지 않으면 반복
			cout << chStack.pop(); //스택에서 인출한 문자를 출력
		cout << endl;
	}
};



int main() {//디폴트 private
	test1 t1;//생성자
	test2 t2;
	test3 t3;
	test4 t4;

	t1.init();
	t2.init();
	t3.init();
	t4.init();

	getchar();
	getchar();

	return 0;
}