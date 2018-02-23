#ifndef PENCILS_H_INCLUDED
#define PENCILS_H_INCLUDED

class Pencils {
	int dozens;//Ÿ
	int np;//����
public:
	Pencils() : dozens(0), np(0) {};

	Pencils(int n) { dozens = n / 12; np = n % 12; }
	
	Pencils(int d, int n) : dozens(d), np(n) {}
	
	Pencils operator++();
	
	Pencils operator++(int);
	
	void display() const;
};

#endif // PENCILS_H_INCLUDED



#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <iostream>
using namespace std;

class MyString {
	int len;//���ڿ��� ����
	int bufSize;//���� ������ ���ڿ��� ����
	char *buf;
public:
	MyString();

	MyString(const char *str);
	
	MyString(const MyString &mstr);
	
	~MyString();
	
	int length() const; //���ڿ� ���� ��ȯ �޼ҵ�
	
	const MyString& operator=(const MyString &mstr);//���� ������
	
	MyString operator+(const MyString &mstr) const;//���ڿ� ���� ������
	
	MyString operator+=(const MyString &mstr);
	
	bool operator==(const MyString &mstr) const;// == ������
	
	bool operator>(const MyString &mstr) const;// > ������
	
	bool operator<(const MyString &mstr) const;// < ������
	
	char& operator[](int i);
	
	const char& operator[](int i) const;
	
	friend ostream& operator<<(ostream &os, const MyString &mstr);
};

inline ostream& operator<<(ostream &os, const MyString &mstr) {//��Ʈ�� ��� ������
	os << mstr.buf;
	return os;
}

#endif // !STRING_H_INCLUDED




#ifndef METER_H_INCLUDED
#define METER_H_INCLUDED
#include <iostream>
using namespace std;

class Meter {
	int m;
	int cm;
public:
	Meter(): m(0),cm(0) {}
	Meter(int meter,int cmeter): m(meter),cm(cmeter) {}
	void display() const {
		if (m)
			cout << m << "m";
		if (cm || !m)
			cout << cm << "cm";
		cout << endl;
	}
	int getM() const { return m; }
	int getCm() const { return cm; }
};

#endif // !METER_H_INCLUDED


#ifndef FEET_H_INCLUDED
#define FEET_H_INCLUDED
#include <iostream>
#include "iExam.h"
using namespace std;

class Feet {
	int ft;
	int in;
public:
	Feet() : ft(0),in(0) {}
	Feet(int f, int i) : ft(f),in(i) {}
	Feet(const Meter &m) {//1 �μ� ������ -�� ��ȯ
		//m�� ��Ƽ���� ������ ��ȯ
		int cmeter = m.getM() * 100 + m.getCm();

		//��ġ�� ��ȯ�Ͽ� �ݿø�.
		in = static_cast<int>(cmeter / 2.54 + 0.5);
		ft = in / 12;
		in %= 12;
	}

	void display() const {
		if (ft)
			cout << ft << "ft ";
		if (in || !ft)
			cout << in << "in ";
		cout << endl;
	}
};

#endif // !FEET_H_INCLUDED
