#ifndef COUNTER_H_INCLUDED //Counter.h�� �ߺ� include���� �ʾҴ��� �˻�
#define COUNTER_H_INCLUDED //Counter.h�� ó�� include �� �� ���ǵ�.
class Counter {
private:
	int value;
public:
	Counter() : value(0) { }//�ʱ�ȭ ����Ʈ

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



#ifndef PERSON_H_INCLUDED //Counter.h�� �ߺ� include���� �ʾҴ��� �˻�
#define PERSON_H_INCLUDED //Counter.h�� ó�� include �� �� ���ǵ�.
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
	//static ������ ���
	static int nConstr;//������ ��ü ��
	static int nDestr;//�Ҹ�� ��ü ��
public:
	NamedObj(const char *s);//������
	~NamedObj();//�Ҹ���

	void display() const {//��ü�� �Ӽ� ���
		cout << "ID : " << id << "--> �̸� : " << name << endl;
	}

	static int nObj() { return nConstr - nDestr; }//�����ϴ� ��ü �� ��ȯ

};

#endif



#ifndef CHARSTACK_H_INCLUDED
#define CHARSTACK_H_INCLUDED

class CharStack {
	enum { size=20};//������ ũ��
	
	int top;//������ �����͸� ����Ű�� ������
	
	char buf[size];//������ �������

public:

	CharStack() { top = size; }//������
	
	bool chkEmpty() const //���ÿ� �����Ͱ� ������ true
	{
		return top == size;
	}

	bool chkFull() const {//������ ���� �� ������ true
		return !top;
	}

	bool push(char ch); //���ÿ� �����͸� ����.

	char pop();//���ÿ��� �����͸� ����.

};

#endif