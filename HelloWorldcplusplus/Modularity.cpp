#include "Vector.h"
#include "stdafx.h"

using namespace std;

double sqrt_sum(Vector_& v)
{
	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
		sum += sqrt(v[i]);            // sum of square roots
	return sum;
}

My_code::complex::complex(int real, int imag){
	_real = real;
	_imag = imag;
}

int My_code::complex::real(){
	return _real;
}

int My_code::complex::imag(){
	return _imag;
}

My_code::complex My_code::sqrt(complex complex) {
	return complex;
}

int My_code::main()
{
	complex z{ 1, 2 };
	auto z2 = sqrt(z);
	std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
	// ...

	return 0;
};

void user(int sz)  noexcept//?? how to use???
{
	Vector_ v(sz);
	iota(&v[0], &v[sz], 1); // fill v with 1,2,3,4...
	// ...
}

void test()
{
	try {
		Vector_ v(-27);
	}
	catch (std::length_error) {
		// handle negative size
		cout << "test failed: length error\n";
		//throw;    // rethrow
	}
	catch (std::bad_alloc) {
		// Ouch! test() is not designed to handle memory exhaustion
		std::terminate();       // terminate the program
	}
}

// static assestions
constexpr double C = 299792.458; // km/s

void f(double speed)
{
	const double local_max = 160.0 / (60 * 60);          // 160 km/h == 160.0/(60*60) km/s
	constexpr double local_max_compile = 160.0 / (60 * 60);
	//static_assert(speed<C, "can't go that fast");    // error: speed must be a constant
	//static_assert(local_max<C, "can't go that fast"); // error: local_max not compile time constant
	static_assert(local_max_compile < C, "can't go that fast"); // OK

	// ...
}

int ModularityDefinedMain() {
	auto value = My_code::main();

	int count = 3;
	Vector_ vector(count);
	f_e1(vector);
	f_e2(vector);
	f_e3(&vector);

	user(2);

	// Invariants
	test();

	// static assestions
	static_assert(4 <= sizeof(int), "integers are too small"); // check integer size
	f(12);

	return 0;
}