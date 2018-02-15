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

int main() {//����Ʈ private
	test1 t1;//������
	test2 t2;
	
	t1.init();
	t2.init();

	getchar();

	return 0;
}