#include "stdafx.h"

using namespace std;

void fDestroy(int n)
{
	Class_Vector v(n);

	// ... use v ...

	{
		Class_Vector v2(2 * n);
		// ... use v and v2 ...
	} // v2 is destroyed here

	// ... use v ..

} // v is destroyed here

Class_Vector read(istream& is)
{
	Class_Vector v;
	for (double d; is >> d;)      // read floating-point values into d
		v.push_back(d);       // add d to v
	return v;
}

void Class_Vector::print()
{
	cout << "Print vector double list";
	for (size_t i = 0; i < sz; i++)
	{
		cout << elem[i] << "; ";
	}

	cout << "\n";
}

Class_Vector::Class_Vector(std::initializer_list<double> lst)  // initialize with a list
	:elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
{
	//http://choorucode.com/2010/08/30/visual-c-c4996-warning-on-copy-with-array-parameters/
	auto checkedArray = stdext::checked_array_iterator<double*>(elem, lst.size());
	auto result       = copy(lst.begin(), lst.end(), checkedArray);         // copy from lst into elem (§10.6)
}

void Class_Vector::push_back(double d){
	auto size = sz + 1;
	auto a    = new double[sz + 1];

	if (sz > 0) {
		auto checkedArray = stdext::checked_array_iterator<double*>(a, size);
		auto result       = copy(&elem[0], &elem[sz], checkedArray);
	}

	a[sz] = d;
	elem  = a;
	sz    = size;
}

Class_Vector::Class_Vector(const Class_Vector& a)     // copy constructor
	:elem{ new double[a.sz] },        // allocate space for elements
	sz{ a.sz }
{
	for (int i = 0; i != sz; ++i)      // copy elements
		elem[i] = a.elem[i];
}

Class_Vector::Class_Vector(Class_Vector&& a) // move constructor
	:elem{ a.elem },          // "grab the elements" from a
	sz{ a.sz }
{
	a.elem = nullptr;       // now a has no elements
	a.sz = 0;
}

Class_Vector& Class_Vector::operator=(const Class_Vector& a)       // copy assignment
{
	double* p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;        // delete old elements
	elem = p;
	sz = a.sz;
	return *this;
}

Class_Vector& Class_Vector::operator=(Class_Vector&& a)       // move assignment
{

	// well implemented???
	delete[] elem;        // delete old elements
	elem = a.elem;
	sz   = a.sz;

	a.elem = nullptr;       // now a has no elements
	a.sz   = 0;

	return *this;
}

class Vector_size_mismatch : public runtime_error {
public:
	Vector_size_mismatch() :runtime_error("Vector_size_mismatch"){};
};

Class_Vector operator+(const Class_Vector& a, const Class_Vector& b)
{
	if (a.size() != b.size())
		throw Vector_size_mismatch{};

	Class_Vector res(a.size());
	for (int i = 0; i != a.size(); ++i)
		res[i] = a[i] + b[i];
	return res;
}

void ClassVectorUse() {
	fDestroy(5);
	
	istringstream iss ("12.5 13.5");
	auto classVector = read(iss);
	classVector.print();

	// initializer_list 
	Class_Vector v1 = { 1, 2, 3, 4, 5 };          // v1 has 5 elements
	v1.print();
	Class_Vector v2 = { 1.23, 3.45, 6.7, 8 };     // v2 has 4 elements
	v2.print();
}