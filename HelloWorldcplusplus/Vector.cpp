#include "Vector.h"
#include "stdafx.h"

using namespace std;

//Vector_::Vector_(int s)
//	:elem{ new double[s] }, sz{ s }           // initialize members
//{
//}

// Invariants
Vector_::Vector_(int s)
{
	if (s<0) {
		auto msg = "Invalid size";
		throw length_error{ msg };
	}

	elem = new double[s];
	sz = s;
}

double& Vector_::operator[](int i)
{
	if (i<0 || size() <= i)
		throw out_of_range{ "Vector::operator[]" };

	return elem[i];
}

int Vector_::size()
{
	return sz;
}