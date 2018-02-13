#include <iostream>
using namespace std;

class test1 {
public:
	void init() {
		test1 t1;

		printf("exam1 \n");
		float fTemp, cTemp;

		cout << "ȭ�� �µ� = ";
		cin >> fTemp;

		cTemp = t1.FachrToC(fTemp);
		cout << "--> ���� �µ� =" << cTemp << endl << endl;
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

		cout << "�� ���� �Է��Ͻÿ� =";
		cin >> a >> b;
		if (a < b) SwapValues(a, b);
		cout << "ū�� = " << a << " ���� �� = " << b << endl << endl;

	}

	//�� ������ ���� �ٲٴ� �Լ�
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
		SalesRec s = { "C25TV001",2018,02,13,"�����" };
		PrSalesRec(s);
	}

	void PrSalesRec(const SalesRec &srec) {
		printf("exam3 \n");
		cout << "ǰ�� �ڵ� =" << srec.pID << endl;
		cout << "��� ���� = " << srec.dYear << "��" << endl;
		cout << srec.dMenth << "��";
		cout << srec.dDate << "��" << endl;
		cout <<"����ּ� = "<< srec.deliverAddr << endl << endl;
	}
};



class test4 {
public:
	void init() {
		const char *str = "a\tbcd\tabcdefghi\tabc";
		printf("exam4 \n");
		PrString(str);//�� ���̸� 8�� �Ͽ� ���
		PrString(str, 4);//�� ���̸� 4�� �Ͽ� ���

	}

	void PrString(const char *str, int tabLen = 8) {
		int col = 0;//�� ��ȣ

		while (*str) {//���ڿ��� ������ �ݺ�
			if (*str == '\t') {
				int n = (col / tabLen + 1) * tabLen;//���� �� ��ġ���� ���� ���ڸ� ä��
			
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
	void AddTime(TimeRec &t1, const TimeRec &t2) {// ������ �ð�,���� �ð�
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

		cout << tRec1.hours << "�ð� " << tRec1.minutes << "�� + ";
		cout << tRec2.hours << "�ð� " << tRec2.minutes << "�� = ";
		AddTime(tRec1, tRec2);

		cout << tRec1.hours << "�ð� " << tRec1.minutes << "��" << endl;

		cout << tRec1.hours << "�ð� " << tRec1.minutes << "�� + ";
		cout << "135�� = ";
		AddTime(tRec1, 135);

		cout << tRec1.hours << "�ð�" << tRec1.minutes << "��" << endl;
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

		cout << "�� ���� �Է��Ͻÿ� = ";
		cin >> a >> b;
		if (a < b) SwapValues(a, b);//������ �ٲ� a�� ū ���� ����.
		cout << "ū �� =" << a << "���� �� = " << b << endl;
	}
};



int main() {
	test1 t1;
	test2 t2;//Call by reference, value
	test3 t3;//const�μ�
	test4 t4;//����Ʈ �μ�
	test5 t5;//���� �Լ�
	test6 t6;//inline �Լ�
 	
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