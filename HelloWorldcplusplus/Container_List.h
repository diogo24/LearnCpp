#include "stdafx.h"

class Container_List : public Abstract_Container {        // List_container implements Container
	std::list<double> ld;     // (standard-library) list of doubles (§9.3)
public:
	Container_List() { }      // empty List
	Container_List(std::initializer_list<double> il) : ld{ il } { }
	~Container_List() {}

	double& operator[](int i);
	int size() const { return ld.size(); }

};

