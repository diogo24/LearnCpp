#include "stdafx.h"

// define necessary types that make the basics run
class Elem {};
class A {};
class T {};
class Point {
public:

	int x;
	int y;

	Point(int x, int y){
		x = x;
		y = y;
	}
};

template <class T>
class Link {

};

template <class T>
class complex {

public:
	T r;
	T i;
	complex() {
	}

	complex(T _r) {
		r = _r;
	}
	complex(T _r, T _i) {
		r = _r;
		i = _i;
	}

	complex<T>& operator+=(complex<T> z) { r += z.r, i += z.i; return *this; }   // add to re and im and return the result
};

void print_square(double x);


Elem* next_elem();      // no argument; return a pointer to Elem (an Elem*)
void exitBasic(int);         // int argument; return nothing
double sqrt(double d);    // double argument; return a double

//double get(const vector<double>& vec, int index);    // type: double(const vector<double>&,int)
//char& String::operator[](int index);                 // type: char& String::(int)

void print(int);     // takes an integer argument
void print(double);  // takes a floating-point argument
void print(std::string);  // takes a string argument

int BasicMain();