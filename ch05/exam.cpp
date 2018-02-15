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

int main() {//디폴트 private
	test1 t1;//생성자
	test2 t2;
	
	t1.init();
	t2.init();

	getchar();

	return 0;
}