#include <iostream>

using namespace std;

class test1 {
	public :
		void init() {
			int a = 10;
			int *ptr;

			printf("ptr.exam1 \n");//포인터 사용법

			ptr = &a;// a의 주소를 넣는다.
			cout << "ptr가 가리키는 값 =  " << *ptr << endl;
		
			*ptr = 20;
			cout << "변수 a의 값 = " << a << endl << endl;

			//delete ptr;
			//ptr = NULL;
		}
};



struct vo {
	int x;
};

class test2 {
public:
	void init() {
		vo v;
		vo* ptrA = &v;

		printf("ptr.exam2 \n");// 구조체나 객체에 대한 포인터 사용법

		(*ptrA).x = 30;
		cout << "(*ptra).x 가 가리키는 값 =  " << (*ptrA).x << endl;

		ptrA->x = 40;
		cout << "ptra->x 가 가리키는 값 = " << ptrA->x << endl << endl;

	}
};



class test3 {
public:
	void init() {
		printf("ptr.exam3 \n");//delete 사용법
		int * iniPtr = new int[4];//int형 포인터 초기화
		
		for (int i = 0; i < 4; i++) {
			*iniPtr = i;
			printf("*iniPtr = %d \n", *iniPtr);
		}
		
		delete iniPtr;//new로 할당되지 않은 개체에 대한 포인터에 delete를 사용하면 예기치 않은 결과가 제공
		iniPtr = NULL;
	}
};



class test4 {
public:
	void init() {
		char str[14] = "Hello, world!";
		char *pt;
		printf("\nptr.exam4 \n");

		cout << str << endl;
		pt = str;

		while (*pt) {//문자열의 끝이 아니면 반복
			if (*pt >= 'a' && *pt <= 'z')// 소문자인 경우
				*pt = *pt - 'a' + 'A';// 대문자로 바꿈.
			pt++;//다음 문자로 포인터 이동
		}

		cout << str << endl;
	}
};



int main() {
	test1 t1;
	test2 t2;
	test3 t3;
	test4 t4;

	t1.init();
	t2.init();
	t3.init();
	t4.init();

	getchar();
	return 0;
}