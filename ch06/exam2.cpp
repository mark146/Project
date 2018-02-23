#include <iostream>
#include <cstring>
#include "iExam.h"
using namespace std;

MyString::MyString() : len(0), bufSize(0) {
	buf = new char[len + 1];
	buf[0] = '\0';
}

MyString::MyString(const char *str) {
	len = bufSize = strlen(str);//문자열 길이
	buf = new char[len + 1];//문자열 저장공간 할당
	strcpy(buf, str);//문자열 복사
}

MyString::MyString(const MyString &mstr) :len(mstr.len), bufSize(mstr.len) {//복사 생성자
	buf = new char[len + 1];
	strcpy(buf, mstr.buf);
}

MyString::~MyString() {//소멸자
	delete[] buf; 
}

int MyString::length() const {//문자열 길이 반환 메소드
	return len; 
}

const MyString& MyString::operator=(const MyString &mstr) {//대입 연산자
	if (bufSize < mstr.len) {//문자열 공간이 필요량보다 작으면
		delete[] buf;//기존 공간 반환
		len = bufSize = mstr.len;//새로운 문자열의 길이
		buf = new char[len + 1];//새로운 공간 할당
	}
	else 
		len = mstr.len; //문자열의 길이만 수정

		strcpy(buf, mstr.buf);
		return *this;

}


MyString MyString::operator+(const MyString &mstr) const {//문자열 연결 연산자
	char *tStr = new char[len + mstr.len + 1];
	strcpy(tStr, buf);
	strcpy(tStr + len, mstr.buf);
	MyString tmStr(tStr);
	delete[] tStr;
	return tmStr;
}

MyString MyString::operator+=(const MyString &mstr) {
	if (bufSize < len + mstr.len) {
		bufSize = len += mstr.len;
		char* tbuf = new char[len + 1];
		strcpy(tbuf, buf);
		delete[] buf;
		buf = tbuf;
	}
	strcat(buf, mstr.buf);

	return *this;
}

//관계 연산자 ==
bool MyString :: operator==(const MyString &mstr) const {
	return !strcmp(buf, mstr.buf);
}

//관계 연산자 >
bool MyString::operator>(const MyString &mstr) const {
	return strcmp(buf, mstr.buf) > 0;
}

//관계 연산자 <
bool MyString::operator<(const MyString &mstr) const {
	return strcmp(buf, mstr.buf) < 0;
}

char& MyString::operator[](int i) {return buf[i]; }

const char& MyString::operator[](int i) const { return buf[i]; }
