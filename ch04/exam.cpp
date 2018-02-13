#include <iostream>
using namespace std;

class test1 {
public:
	void init() {
		test1 t1;

		printf("exam1 \n");
		float fTemp, cTemp;

		cout << "화씨 온도 = ";
		cin >> fTemp;

		cTemp = t1.FachrToC(fTemp);
		cout << "--> 섭씨 온도 =" << cTemp << endl << endl;
	}

	float FachrToC(float fahr) {

		float c = (fahr - 32) * 5 / 9;

	return c;
	}
};




class test2 {
public:
	void init() {
		int a, b;
		printf("exam2 \n");

		cout << "두 수를 입력하시오 =";
		cin >> a >> b;
		if (a < b) SwapValues(a, b);
		cout << "큰수 = " << a << " 작은 수 = " << b << endl << endl;

	}

	//두 변수의 값을 바꾸는 함수
	void SwapValues(int &x, int &y) {//Call by reference
    //void SwapValues(int x, int y) {Call by value
		int temp = x;
		x = y;
		y = temp;
	}
};



struct SalesRec {
	char pID[10];
	int dYear, dMenth, dDate;
	char deliverAddr[40];
};

class test3 {
public:
	void init() {
		SalesRec s = { "C25TV001",2018,02,13,"서울시" };
		PrSalesRec(s);
	}

	void PrSalesRec(const SalesRec &srec) {
		printf("exam3 \n");
		cout << "품목 코드 =" << srec.pID << endl;
		cout << "배달 일자 = " << srec.dYear << "년" << endl;
		cout << srec.dMenth << "월";
		cout << srec.dDate << "일" << endl;
		cout <<"배달주소 = "<< srec.deliverAddr << endl << endl;
	}
};



class test4 {
public:
	void init() {
		const char *str = "a\tbcd\tabcdefghi\tabc";
		printf("exam4 \n");
		PrString(str);//탭 길이를 8로 하여 출력
		PrString(str, 4);//탭 길이를 4로 하여 출력

	}

	void PrString(const char *str, int tabLen = 8) {
		int col = 0;//열 번호

		while (*str) {//문자열의 끝까지 반복
			if (*str == '\t') {
				int n = (col / tabLen + 1) * tabLen;//다음 탭 위치까지 공백 문자를 채움
			
				for (; col < n; col++) {
					cout << ' ';
				}

			} else {
				cout << *str;
				col++;
			}

			str++;
		}
		cout << endl;
		
	}
};



struct TimeRec {
	int hours;
	int minutes;
};

class test5 {
public:
	void AddTime(TimeRec &t1, const TimeRec &t2) {// 누계할 시간,더할 시간
		t1.minutes += t2.minutes;
		t1.hours += t2.hours + t1.minutes / 60;
		t1.minutes %= 60;
	}

	void AddTime(TimeRec &t, int minutes) {
		t.minutes += minutes;
		t.hours += t.minutes / 60;
		t.minutes %= 60;
	}

	void init() {
		TimeRec tRec1 = { 2,30 };
		TimeRec tRec2 = { 1,45 };

		printf("exam5 \n");

		cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
		cout << tRec2.hours << "시간 " << tRec2.minutes << "분 = ";
		AddTime(tRec1, tRec2);

		cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;

		cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
		cout << "135분 = ";
		AddTime(tRec1, 135);

		cout << tRec1.hours << "시간" << tRec1.minutes << "분" << endl;
	}

};



class test6 {
	inline void SwapValues(int &x, int &y) {
		int temp = x;
		x = y;
		y = temp;
	}

public:
	void init() {
		int a, b;

		printf("exam6 \n");

		cout << "두 수를 입력하시오 = ";
		cin >> a >> b;
		if (a < b) SwapValues(a, b);//순서를 바꿔 a에 큰 값을 넣음.
		cout << "큰 수 =" << a << "작은 수 = " << b << endl;
	}
};



int main() {
	test1 t1;
	test2 t2;//Call by reference, value
	test3 t3;//const인수
	test4 t4;//디폴트 인수
	test5 t5;//다중 함수
	test6 t6;//inline 함수
 	
	t1.init();
	t2.init();
	t3.init();
	t4.init();
	t5.init();
	t6.init();
	

	getchar();
	getchar();
	return 0;
}