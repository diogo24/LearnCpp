#include "stdafx.h"

using namespace ArithmeticTypes;

Class_Complex& Class_Complex::operator *= (Class_Complex z) {
	re *= z.re, im *= z.im; 
	return *this;
}    // defined out-of-class somewhere
Class_Complex& Class_Complex::operator /= (Class_Complex z) {
	re /= z.re, im /= z.im;
	return *this;
} // defined out-of-class somewhere

Class_Complex operator+(Class_Complex a, Class_Complex b) { return a += b; }
Class_Complex operator-(Class_Complex a, Class_Complex b) { return a -= b; }
Class_Complex operator-(Class_Complex a){ return{ -a.real(), -a.imag() }; }     // unary minus
Class_Complex operator*(Class_Complex a, Class_Complex b) { return a *= b; }
Class_Complex operator/(Class_Complex a, Class_Complex b) { return a /= b; }

bool operator==(Class_Complex a, Class_Complex b)          // equal
{
	return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(Class_Complex a, Class_Complex b)          // not equal
{
	return !(a == b);
}

void Class_Complex::print() {
	std::cout << "real: " << re << " - img:" << im << "\n";
}

Class_Complex sqrt(Class_Complex);  // the definition is elsewhere

void ClassComplexUse(Class_Complex z)
{
	Class_Complex a{ 2.3 };        // construct {2.3,0.0} from 2.3
	Class_Complex b{ 1 / a };
	Class_Complex c{ a + z*Class_Complex{ 1, 2.3 } };
	// ...
	std::cout << "complex before calculation \n";
	c.print();
	if (c != b)
		c = -(b / a) + 2 * b;
	std::cout << "complex after calculation \n";
	c.print();
}