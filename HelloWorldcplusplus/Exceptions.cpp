#include "Vector.h"
#include "stdafx.h"

using namespace std;

void f_e1(Vector_& v)
{
	// ...
	try { // exceptions here are handled by the handler defined below

		v[v.size()] = 7; // try to access beyond the end of v
	}
	catch (out_of_range) {        // oops: out_of_range error
		// ... handle range error ...
	}
	// ...
}

void f_e2(Vector_ v)
{
	// ...
	try { // exceptions here are handled by the handler defined below

		v[v.size()] = 7; // try to access beyond the end of v
	}
	catch (out_of_range) {        // oops: out_of_range error
		// ... handle range error ...
	}
	// ...
}

void f_e3(Vector_* v)
{
	// ...
	try { // exceptions here are handled by the handler defined below

		v[v->size()] = 7; // try to access beyond the end of v
	}
	catch (out_of_range) {        // oops: out_of_range error
		// ... handle range error ...
	}
	// ...
}