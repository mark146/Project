#ifndef COUNTER_H_INCLUDED //Counter.h가 중복 include되지 않았는지 검사

#define COUNTER_H_INCLUDED //Counter.h가 처음 include 될 때 정의됨.

class Counter {
private:
	int value;

public:
	Counter() : value(0) { }//초기화 리스트

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


#ifndef PERSON_H_INCLUDED //Counter.h가 중복 include되지 않았는지 검사

#define PERSON_H_INCLUDED //Counter.h가 처음 include 될 때 정의됨.
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
