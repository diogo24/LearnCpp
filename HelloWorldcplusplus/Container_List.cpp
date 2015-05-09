#include "stdafx.h"

using namespace std;

double& Container_List::operator[](int i)
{
	for (auto& x : ld) {
		if (i == 0) return x;
		--i;
	}
	throw out_of_range("List container");
}