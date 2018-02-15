#ifndef COUNTER_H_INCLUDED //Counter.h�� �ߺ� include���� �ʾҴ��� �˻�

#define COUNTER_H_INCLUDED //Counter.h�� ó�� include �� �� ���ǵ�.

class Counter {
private:
	int value;

public:
	Counter() : value(0) { }//�ʱ�ȭ ����Ʈ

	void reset() {
		value = 0;
	}

	void count() {
		++value;
	}

	int getValue() const {
		return value;
	}
};

#endif


#ifndef PERSON_H_INCLUDED //Counter.h�� �ߺ� include���� �ʾҴ��� �˻�

#define PERSON_H_INCLUDED //Counter.h�� ó�� include �� �� ���ǵ�.
class Person {
	char *name;
	char *addr;
public:
	Person(const char *name, const char *addr);
	~Person();

	void print() const;
	
	void chAddr(const char *newAddr);
};
#endif
