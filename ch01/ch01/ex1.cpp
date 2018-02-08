#include <iostream>//선행처리기 지시어
using namespace std;//명칭공간
namespace nsp1 { int n = 10; }
namespace nsp2 { int n = 20; }
int n = 30;

int main() {
	int n = 40;
	cout << "Hello world !" << endl;
	cout << nsp1::n << endl;
	cout << nsp2::n << endl;
	cout << ::n << endl;
	cout << n << endl;

	return 0;
}