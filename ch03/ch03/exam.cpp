#include <iostream>

using namespace std;

class test1 {
	public :
		void init() {
			int a = 10;
			int *ptr;

			printf("ptr.exam1 \n");//������ ����

			ptr = &a;// a�� �ּҸ� �ִ´�.
			cout << "ptr�� ����Ű�� �� =  " << *ptr << endl;
		
			*ptr = 20;
			cout << "���� a�� �� = " << a << endl << endl;

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

		printf("ptr.exam2 \n");// ����ü�� ��ü�� ���� ������ ����

		(*ptrA).x = 30;
		cout << "(*ptra).x �� ����Ű�� �� =  " << (*ptrA).x << endl;

		ptrA->x = 40;
		cout << "ptra->x �� ����Ű�� �� = " << ptrA->x << endl << endl;

	}
};



class test3 {
public:
	void init() {
		printf("ptr.exam3 \n");//delete ����
		int * iniPtr = new int[4];//int�� ������ �ʱ�ȭ
		
		for (int i = 0; i < 4; i++) {
			*iniPtr = i;
			printf("*iniPtr = %d \n", *iniPtr);
		}
		
		delete iniPtr;//new�� �Ҵ���� ���� ��ü�� ���� �����Ϳ� delete�� ����ϸ� ����ġ ���� ����� ����
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

		while (*pt) {//���ڿ��� ���� �ƴϸ� �ݺ�
			if (*pt >= 'a' && *pt <= 'z')// �ҹ����� ���
				*pt = *pt - 'a' + 'A';// �빮�ڷ� �ٲ�.
			pt++;//���� ���ڷ� ������ �̵�
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