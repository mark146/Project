#ifndef PENCILS_H_INCLUDED
#define PENCILS_H_INCLUDED

class Pencils {
	int dozens;//타
	int np;//낱개
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
	int len;//문자열의 길이
	int bufSize;//저장 가능한 문자열의 길이
	char *buf;
public:
	MyString();

	MyString(const char *str);
	
	MyString(const MyString &mstr);
	
	~MyString();
	
	int length() const; //문자열 길이 반환 메소드
	
	const MyString& operator=(const MyString &mstr);//대입 연산자
	
	MyString operator+(const MyString &mstr) const;//문자열 연결 연산자
	
	MyString operator+=(const MyString &mstr);
	
	bool operator==(const MyString &mstr) const;// == 연산자
	
	bool operator>(const MyString &mstr) const;// > 연산자
	
	bool operator<(const MyString &mstr) const;// < 연산자
	
	char& operator[](int i);
	
	const char& operator[](int i) const;
	
	friend ostream& operator<<(ostream &os, const MyString &mstr);
};

inline ostream& operator<<(ostream &os, const MyString &mstr) {//스트림 출력 연산자
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
	Feet(const Meter &m) {//1 인수 생성자 -형 변환
		//m을 센티미터 단위로 변환
		int cmeter = m.getM() * 100 + m.getCm();

		//인치로 변환하여 반올림.
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
