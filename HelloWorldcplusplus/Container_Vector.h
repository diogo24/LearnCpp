#include "stdafx.h"

class Container_Vector : public Abstract_Container {   // Container_Vector implements Abstract_Container
	Class_Vector v;
public:
	Container_Vector(int s) : v(s) { } // Vector of s elements
	~Container_Vector() {}

	double& operator[](int i) { return v[i]; }
	int size() const { return v.size(); }
	void initializeVector(std::initializer_list<double>);
};