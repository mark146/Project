#include <iostream>
#include <cstring>
#include "exam.h"

using namespace std;

class test1 {
private: 
	Counter cnt;//����Ʈ private

public:
	void init() {

		printf("exam1 \n");
		
		cout << "������� ���� �� = " << cnt.getValue() << endl;
		cnt.count();
		cnt.count();
		cout << "������� ���� �� = " << cnt.getValue() << endl << endl;
	}
};



Person::Person(const char *name, const char *addr) {
	this->name = new char[strlen(name) + 1];//�̸��� ������ ���� �Ҵ�
	strcpy(this->name, name);// ������ ��� name�� �̸��� ����
	this->addr = new char[strlen(addr) + 1];//�ּҸ� ������ ���� �Ҵ�
	strcpy(this->addr, addr);//������ ��� addr�� �ּҸ� ����
	cout << "Person ��ü ������(" << name << ")" << endl;
}

Person::~Person() {
	cout << "Person ��ü ������(" << name << ")" << endl;
	delete[] name;
	delete[] addr;
}

void Person::print() const {
	cout << addr << " �� ��� " << name << " �Դϴ� " << endl;
}

void Person::chAddr(const char* newAddr) {
	delete[] addr; //���� ���� �ݳ�
	addr = new char[strlen(newAddr) + 1];//���ο� �ּҿ� �´� ���� �Ҵ�
	strcpy(addr, newAddr);//������ ��� addr�� ���ο� �ּҸ� ����
}

class test2 {
		Person *p1 = new Person("��ö��","����� ���α�");//����Ʈ private
		Person *p2 = new Person("������", "������ ���ؽ�");

public:
	void init() {

		printf("exam2 \n");

		p1->print();
		p2->print();
		cout << endl << "�ּ� ����: ";
		p2->chAddr("������ ����");
		p2->print();
		delete p1;
		delete p2;
	}

};



NamedObj::NamedObj(const char *s) {
	name = new char[strlen(s) + 1];//���ڿ��� ������ ������ �Ҵ�
	strcpy(name, s);
	id = ++nConstr;//������ ��ü�� ���� ������Ű�� �̸� ID�� �ο�
}

NamedObj::~NamedObj() {
	++nDestr;//�Ҹ�� ��ü�� ���� ������Ŵ.
	delete[] name;
}

//static ������ ����� ���� �� �ʱ�ȭ
int NamedObj::nConstr = 0;
int NamedObj::nDestr = 0;


class test3 {
public:
	void f() {
		NamedObj x("Thrird");//�� ��° ��ü�� ����
		x.display();//�Լ� ��ȯ �� x�� �Ҹ��.
	}

	void init() {
		printf("exam3 \n");
		cout << "NamedObj Ŭ������ ��ü ��:" << NamedObj::nObj() << endl;
		NamedObj a("First");//ù ��° ��ü ����
		NamedObj b("Second");//�� ��° ��ü ����
		a.display();
		b.display();
		f();
		NamedObj c("Fourth");
		c.display();
		cout << "NamedObj Ŭ������ ��ü ��:" << NamedObj::nObj() << endl;
	}
};



bool CharStack::push(char ch) {
	if (chkFull()) {
		cout << "������ ���� �� �ֽ��ϴ�." << endl;
	 return false;
	}
	buf[--top] = ch;//���ÿ� ������ ������ ����
	return true;
}

char CharStack::pop() {
	if (chkEmpty()) {
		cout << "���ÿ� �����Ͱ� �����ϴ�." << endl;
		return 0;
	}
	return buf[top++];//top ��ġ�� ������ ��ȯ
}



class test4 {
	CharStack chStack;//20���� ���ڸ� ������ �� �ִ� ����
	char str[20];

public:
	void init() {
		cout << "���� �ܾ �Է��Ͻÿ�:";
		cin >> str;

		char* pt = str;//�����ͷ� ���ڿ� ���� ��ġ�� ����Ŵ.
		while (*pt) //���ڿ��� ���� �ƴϸ� �ݺ�
			chStack.push(*(pt++));//���ÿ� ���ڸ� ����.
		cout << "���� �ܾ� ���:";
		while (!chStack.chkEmpty()) //������ ��� ���� ������ �ݺ�
			cout << chStack.pop(); //���ÿ��� ������ ���ڸ� ���
		cout << endl;
	}
};



int main() {//����Ʈ private
	test1 t1;//������
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