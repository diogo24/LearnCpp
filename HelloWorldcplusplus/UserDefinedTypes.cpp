#include "stdafx.h"

using namespace std;

void vector_init(Vector_Struct& v, int s)
{
	v.elem = new double[s];   // allocate an array of s doubles
	v.sz   = s;
}

double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
	Vector_Struct v;

	vector_init(v, s);

	for (int i = 0; i != s; ++i)
		cin >> v.elem[i];             // read into elements

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v.elem[i];             // take the sum of the elements
	return sum;
}

void f(Vector_Struct v, Vector_Struct& rv, Vector_Struct* pv)
{
	int i1 = v.sz;       // access through name
	int i2 = rv.sz;      // access through reference
	int i4 = pv->sz;     // access through pointer
}

void vectorMembersAccess() {
	Vector_Struct v;
	auto count = 5;
	vector_init(v, count);

	f(v, v, &v);
}

class Vector_Class {
public:
	Vector_Class(int s) :elem{ new double[s] }, sz{ s } { }   // construct a Vector
	double& operator[](int i) { return elem[i]; }   // element access: subscripting
	int size() { return sz; }
private:
	double* elem;    // pointer to the elements
	int sz;          // the number of elements
};

double read_and_sum_class(int s)
{
	Vector_Class v(s);

	for (int i = 0; i != v.size(); ++i)
		cin >> v[i];             // read into elements

	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
		sum += v[i];             // take the sum of the elements
	return sum;
}

void fs(Entry* p)
{
	if (p->t == str)
		cout << p->s;
	// ...
}

void f(Entry_Union* p)
{
	if (p->t == str)
		cout << p->v.s;
	// ...
}

Traffic_light& operator++(Traffic_light& t)
// prefix increment: ++
{
	switch (t) {
		case Traffic_light::green:    return t = Traffic_light::yellow;
		case Traffic_light::yellow:   return t = Traffic_light::red;
		case Traffic_light::red:      return t = Traffic_light::green;
	}
}

void UserDefinedMain() {
	auto sum = read_and_sum(3);
	cout << "sum value = ";
	cout << sum;
	cout << "\n";

	vectorMembersAccess();

	sum = read_and_sum(3);
	cout << "sum value class = ";
	cout << sum;
	cout << "\n";

	Color col           = Color::red;
	//int  col          = red; ??
	Traffic_light light = Traffic_light::red;

	Traffic_light next  = ++light;       // next becomes Traffic_light::green
}