#ifndef COUNTER_H_INCLUDED //Counter.h가 중복 include되지 않았는지 검사
#define COUNTER_H_INCLUDED //Counter.h가 처음 include 될 때 정의됨.
class Counter {
private:
	int value;
public:
	Counter() : value(0) { }//초기화 리스트

	void reset() {
		value = 0;
	}

	void count() {
		++value;
	}

	int getValue() const {
		return value;
	}
};
#endif



#ifndef PERSON_H_INCLUDED //Counter.h가 중복 include되지 않았는지 검사
#define PERSON_H_INCLUDED //Counter.h가 처음 include 될 때 정의됨.
class Person {
	char *name;
	char *addr;
public:
	Person(const char *name, const char *addr);
	~Person();

	void print() const;
	
	void chAddr(const char *newAddr);
};
#endif



#ifndef NAMEDOBJ_H_INCLUDED
#define NAMEDOBJ_H_INCLUDED
#include <iostream>
using namespace std;
class NamedObj {
	char *name;
	int id;
	//static 데이터 멤버
	static int nConstr;//생성된 객체 수
	static int nDestr;//소멸된 객체 수
public:
	NamedObj(const char *s);//생성자
	~NamedObj();//소멸자

	void display() const {//객체의 속성 출력
		cout << "ID : " << id << "--> 이름 : " << name << endl;
	}

	static int nObj() { return nConstr - nDestr; }//존재하는 객체 수 반환

};

#endif



#ifndef CHARSTACK_H_INCLUDED
#define CHARSTACK_H_INCLUDED

class CharStack {
	enum { size=20};//스택의 크기
	
	int top;//마지막 데이터를 가리키는 포인터
	
	char buf[size];//스택의 저장공간

public:

	CharStack() { top = size; }//생성자
	
	bool chkEmpty() const //스택에 데이터가 없으면 true
	{
		return top == size;
	}

	bool chkFull() const {//스택이 가측 차 있으면 true
		return !top;
	}

	bool push(char ch); //스택에 데이터를 넣음.

	char pop();//스택에서 데이터를 꺼냄.

};

#endif