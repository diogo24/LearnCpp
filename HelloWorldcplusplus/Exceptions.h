#include "stdafx.h"
#include "Vector.h"

class Vector_size_mismatch : public std::runtime_error {
public:
	Vector_size_mismatch() :std::runtime_error("Vector_size_mismatch"){};
};

class Negative_size : public std::runtime_error {
public:
	Negative_size() :std::runtime_error("A container can't have a negative size"){};
};

void f_e1(Vector_& v);
void f_e2(Vector_ v);
void f_e3(Vector_* v);