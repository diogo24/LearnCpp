#include "stdafx.h"

using namespace std;

double square(double x)
{
	return x*x;
}

void print_square(double x)
{
	cout << "the square of " << x << " is " << square(x) << "\n";
}

void print(int i) {}
void print(double d) {}
void print(string s) {}

void user()
{
	print(42);                 // calls print(int)
	print(9.65);               // calls print(double)
	print("D is for Digital"); // calls print(string)
}

double d1 = 2.3;          // initialize d1 to 2.3
double d2{ 2.3 };

complex<double> z = 1;            // a complex number with double-precision floating-point scalars
complex<double> z2{ d1, d2 };
complex<double> z3 = { 1, 2 };       // the = is optional with { ... }

vector<int> v{ 1, 2, 3, 4, 5, 6 };      // a vector of ints

// var in c#
auto b = true;

vector<int> vec;    // vec is global (a global vector of integers)

struct Record {
	string name;   // name is a member (a string member)
	// ...
};

void fct(int arg)   // fct is global (a global function)
// arg is local (an integer argument)
{
	string motto{ "Who dares win" };         // motto is local
	auto p = new Record{ "Hume" };            // p points to an unnamed Record (created by new)
	// ...
}

const int dmv = 17;                             // dmv is a named constant
int var       = 17;                                   // var is not a constant

//constexpr double max1 = 1.4*square_(dmv);        // OK if square(17) is a constant expression
/*constexpr double max2 = 1.4*square(var);  */      // error: var is not a constant expression
const double max3 = 1.4*square(var);            // OK, may be evaluated at run time

double sum(const vector<double>&);              // sum will not modify its argument (§1.8)
vector<double> vectDob{ 1.2, 3.4, 4.5 };               // v is not a constant
//const double s1 = sum(v);                       // OK: evaluated at run time
/*constexpr double s2 = sum(v);   */                // error: sum(v) not constant expression

char va[6]; // array of 6 characters
char* p; // pointer to character

char* pc = &va[3];       // p points to v's fourth element
char x = *pc;           // *p is the object that p points to

void copy_fct()
{
	int v1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int v2[10];                 // to become a copy of v1

	for (auto i = 0; i != 10; ++i)  // copy elements
		v2[i] = v1[i];
	// ...
}

void print()
{
	int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto x : v)              // for each x in v
		cout << x << '\n';

	for (auto x : { 10, 21, 32, 43, 54, 65 })
		cout << x << '\n';
	// ...
}

void increment()
{
	int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto& x : v)
		++x;
	// ...
}

void sort(vector<double>& v);
// When we don’t want to modify an argument, but still don’t want the cost of copying, we use a const reference.
double sum(const vector<double>&);

const int n = 1;
T a[n];   // T[n]: array of n Ts
T* pt;     // T*: pointer to T
T& r = a[0];     // T&: reference to T
T f(A);   // T(A): function taking an argument of type A returning a result of type T

double* pd        = nullptr;
Link<Record>* lst = nullptr;  // pointer to a Link to a Record
//int x           = nullptr;              // error: nullptr is a pointer not an integer

int count_x(char* p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
	if (p == nullptr) return 0;
	int count = 0;
	for (; p != nullptr; ++p)
		if (*p == x)
			++count;
	return count;

	//or
	/*int count = 0;
	while (p) {
	if (*p == x)
	++count;
	++p;
	}
	return count;*/
}

bool accept()
{
	cout << "Do you want to proceed (y or n)?\n";   // write question

	char answer = 0;
	cin >> answer;                                  // read answer

	if (answer == 'y')
		return true;
	return false;
}

bool accept2()
{
	cout << "Do you want to proceed (y or n)?\n";   // write question

	char answer = 0;
	cin >> answer;                            // read answer
	switch (answer) {
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		cout << "I'll take that for a no.\n";
		return false;
	}
}

void action()
{
	while (true) {
		cout << "enter action:\n";            // request action
		string act;
		cin >> act;          // rear characters into a string
		Point delta{ 0, 0 };   // Point holds an {x,y} pair

		for (char ch : act) {
			switch (ch) {
			case 'u': // up
			case 'n': // north
				++delta.y;
				break;
			case 'r': // right
			case 'e': // east
				++delta.x;
				break;
				// ... more actions ...

			default:
				cout << "I freeze!\n";
			}
			/*move(current + delta*scale);
			update_display();*/
		}
	}
}

int BasicMain() {
	// comments
	cout << "Hello World!\n";

	print_square(1.234);

	return 0;
}