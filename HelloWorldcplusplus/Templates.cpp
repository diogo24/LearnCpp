#include "stdafx.h"

using namespace std;

void write(const Template_Vector<string>& vs)        // Vector of some strings
{
	for (int i = 0; i != vs.size(); ++i)
		cout << vs[i] << '\n';
}

void write2(Template_Vector<string>& vs)     // Vector of some strings
{
	for (auto& s : vs)
		cout << s << '\n';
}

// currently not supported

//template<typename T, int N>
//struct Buffer {
//	using value_type = T;
//	constexpr int size() { return N; }
//	T[N];
//	// ...
//};
//
//Buffer<char, 1024> glob;  // global buffer of characters (statically allocated)
//
//void f_Buffer()
//{
//	Buffer<int, 10> buf; // local buffer of integers (on the stack)
//	// ...
//}

// function templates
template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for (auto x : c)
		v += x;
	return v;
}

void use_of_function_Templates(vector<int>& vi, std::list<double>& ld, vector<complex<double>>& vc)
{
	int x     = sum(vi, 0);                       // the sum of a vector of ints (add ints)
	double d  = sum(vi, 0.0);                  // the sum of a vector of ints (add doubles)
	double dd = sum(ld, 0.0);                 // the sum of a list of doubles
	auto z    = sum(vc, complex<double>{});      // the sum of a vector of complex<double>
	// the initial value is {0.0,0.0}
}

void fct_objects(int n, const string & s)
{
	Less_than<int> lti{ 42 };          // lti(i) will compare i to 42 using < (i<42)
	Less_than<string> lts{ "Backus" }; // lts(s) will compare s to "Backus" using < (s<"Backus")

	bool b1 = lti(n);   // true if n<42
	bool b2 = lts(s);   // true if s<"Backus"
	// ...
}

// function templates using function objects
template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for (const auto& x : c)
		if (pred(x))
			++cnt;
	return cnt;
}

void use_of_fct_Objects(const vector<int>& vec, const list<string>& lst, int x, const string& s)
{
	cout << "number of values less than " << x
		<< ": " << count(vec, Less_than<int>{x})
		<< '\n';
	cout << "number of values less than " << s
		<< ": " << count(lst, Less_than<string>{s})
		<< '\n';
}

// implicitly generating function objects
void f_implicitly_generating_fct_objects(const vector<int>& vec, const list<string>& lst, int x, const string& s)
{
	cout << "number of values less than " << x
		<< ": " << count(vec, [&](int a){ return a<x; })
		<< '\n';
	cout << "number of values less than " << s
		<< ": " << count(lst, [&](const string& a){ return a<s; })
		<< '\n';
}

template<typename C, typename Oper>
void for_all(C& c, Oper op)    // assume that C is a container of pointers
{
	for (auto& x : c)
		op(*x);        // pass op() a reference to each element pointed to
}

//Now, we can write a version of user() from §4.5 without writing a set of _all functions :
//Click here to view code image
//use_shape in abstractTypes.cpp

void use_shape_fct_Objs()
{
	vector<unique_ptr<Shape>> v;
	while (cin)
		v.push_back(read_shape_unique(cin));
	for_all(v, [](Shape& s){ s.draw(); });      // draw_all()
	for_all(v, [](Shape& s){ s.rotate(45); });  // rotate_all(45)
}

int TemplatesMain(){
	Template_Vector<char> vc(200);          // vector of 200 characters
	Template_Vector<string> vs(17);         // vector of 17 strings
	Template_Vector<list<int>> vli(45);     // vector of 45 lists of integers

	Template_Vector<string> stringVector(3);
	stringVector[0] = "Templates";
	stringVector[1] = "Writing String Vector";
	stringVector[2] = "in the console";
	write(stringVector);

	Template_Vector<string> stringVector2 { "Templates", "Writing String Vector", "in the console" };
	write2(stringVector2);

	//f_Buffer();

	// function templates
	vector<double> list = { 1, 2, 3};
	double val = 0;
	cout << "Sum with a template function: " << sum(list, val);

	//use_of_function_Templates ?? implement example

	//function objects
	fct_objects(5, "Ola");
	std::list<string> sl = { "A", "B", "C" };
	auto il = { 2, 3, 4 };
	auto i  = 3;
	auto s  = "banana";
	
	//use_of_fct_Objects(il, sl, i, s);
	//f_implicitly_generating_fct_objects(il, sl, i, s);

	//use_shape_fct_Objs();

	return 0;
}
