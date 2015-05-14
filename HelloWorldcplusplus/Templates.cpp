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

	return 0;
}
