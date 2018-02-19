#include <iostream>
#include "iExam.h"
using namespace std;


class test1 {
public:
	void init() {
		Pencils p1(5, 7);
		Pencils p2(23);

		p1.display();
		(++p1).display();
		p1.display();
		cout << endl;
		p2.display();
		p1 = p2++;
		p1.display();
		p2.display();

	}
};

int main() {
	test1 t1;

	t1.init();

	getchar();
	return 0;
}