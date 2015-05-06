#include "stdafx.h"

void UserDefinedMain();

struct Vector_Struct {
	int sz;       // number of elements
	double* elem; // pointer to elements
};

void vector_init(Vector_Struct& v, int s);
double read_and_sum(int s);
void f(Vector_Struct v, Vector_Struct& rv, Vector_Struct* pv);
void vectorMembersAccess();


double read_and_sum_class(int s);


enum Type { str, num };

struct Entry {
	char* name;
	Type t;
	char* s; // use s if t==str
	int i;   // use i if t==num
};

void fs(Entry* p);

// Union
union Value {
	char* s;
	int i;
};

struct Entry_Union {
	char* name;
	Type t;
	Value v; // use v.s if t==str; use v.i if t==num
};

void f(Entry_Union* p);

// Enums

enum Color { red, blue, green };
enum class Traffic_light { green, yellow, red };