#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;


struct vo {
	char filename[20];
	char ch;
};

class FileIn {
public:
	void init() {
		vo v;

		cout << "새로운 파일 이름을 입력하시오: ";
		cin >> v.filename;

		//입력 스트림을 비움
		cin.ignore(1, '\n');

		//새로운 ofstream 객체를 생성하여 파일을 오픈함.
		ofstream fout(v.filename);

		/*
		 cin.get(ch)가 false일 때까지 입력된 문자를 파일에 기록하며, Ctrl + Z를 입력하면 false를 반환한다.
		 cin.get(ch) 사용 이유 : cin >> ch;를 사용해서 할수도 있었으나
		 이 코드는 공백을 무시하므로 입력한 키 값중에서 백색문자는 제외하고 파일에 기록한다.
		*/
		while (cin.get(v.ch)) {
			fout << v.ch;
		}

		fout.close();
	}
};

class FileOut {
public:
	void init() {
		vo v;

		cout << "\n----------------------- 파일의 내용 -----------------------\n";

		// 새로운 ifstream 객체를 생성하여 파일을 오픈함.
		ifstream fin(v.filename);

		// 파일에서 한개의 문자를 읽어 화면에 출력함.
		while (fin.get(v.ch)) {
			cout << v.ch;
		}

		fin.close();
	}
};

//  입력받은 문자들을 파일에 기록하고, 파일을 다시 열어 화면에 출력하는 기능
int main()
{
	FileIn fin;
	FileOut fout;

	fin.init();
	fout.init();

	return 0;
}
