#include "stdafx.h"

using namespace std;

void Container_Vector::initializeVector(initializer_list<double> valuesList) {
	for (auto value : valuesList) {
		v.push_back(value);
	}
}

void use(Abstract_Container& c)
{
	const int sz = c.size();

	for (int i = 0; i != sz; ++i)
		cout << c[i] << '\n';
}

void rotate_all(vector<Shape*>& v, int angle) // rotate v's elements by angle degrees
{
	for (auto p : v)
		p->rotate(angle);
}

enum class Kind { circle, triangle, smiley };

//Shape* read_shape(istream& is)       // read shape descriptions from input stream is
//{
//	// ... read shape header from is and find its Kind k ...
//	vector<double> points;
//	for (double point; is >> point;) {
//		points.push_back(point);
//	}
//
//	Kind k;
//	if (points.size() == 3){
//		k = Kind::circle;
//	}
//	if (points.size() == 6){
//		k = Kind::triangle;
//	}
//
//	if (points.size() == 6){
//		k = Kind::triangle;
//	}
//
//	switch (k) {
//	case Kind::circle:
//		// read circle data {Point,int} into p and r
//		return new Circle{ p, r };
//	case Kind::Triangle:
//		// read triangle data {Point,Point,Point} into p1, p2, and p3
//		return new Triangle{ p1, p2, p3 };
//	case Kind::smiley:
//		// read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1, e2, and m
//		Smiley* ps = new Smiley{ p, r };
//		ps->add_eye(e1);
//		ps->add_eye(e2);
//		ps->set_mouth(m);
//		return ps;
//	}
//}
//
//void use_shape()
//{
//	vector<Shape*> v;
//	while (cin)
//		v.push_back(read_shape(cin));
//	draw_all(v);               // call draw() for each element
//	rotate_all(v, 45);          // call rotate(45) for each element
//	for (auto p : v)           // remember to delete elements
//		delete p;
//}

void AbstractTypeUse(){
	Container_Vector containerVector(10);
	containerVector.initializeVector({ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 });
	use(containerVector);

	Container_List lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	use(lc);

	vector<Shape*> shapes(0);
	rotate_all(shapes, 30);
	//use_shape();
}