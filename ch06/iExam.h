#ifndef PENCILS_H_INCLUDED

#define PENCILS_H_INCLUDED

class Pencils {
	int dozens;//Å¸
	int np;//³¹°³
public:
	Pencils() : dozens(0), np(0) {};

	Pencils(int n) { dozens = n / 12; np = n % 12; }
	
	Pencils(int d, int n) : dozens(d), np(n) {}
	
	Pencils operator++();
	
	Pencils operator++(int);
	
	void display() const;
};

#endif // PENCILS_H_INCLUDED
