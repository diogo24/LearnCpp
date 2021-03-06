#include "stdafx.h"

using namespace std;
using namespace ArithmeticTypes;

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

class Triangle : public Shape {
	vector<Point> _points;

public:
	Triangle(std::initializer_list<Point> points) :_points{ points } {}

	void move(Point to) override {};
	void draw() const override {};
	void rotate(int angle) override {};
	Point center() const override { return _points[0]; };
};

enum class Kind { circle, triangle, smiley };

Shape* read_shape(istream& is)       // read shape descriptions from input stream is
{
	// ... read shape header from is and find its Kind k ...
	vector<double> points;
	for (double point; is >> point;) {
		points.push_back(point);
	}

	Point p(0, 1);
	int r = 2;

	Point p1(3, 4);
	Point p2(4, 5);
	Point p3(5, 6);

	Circle c1(p1, r);
	Shape* e1 = &c1;
	Circle c2(p2, r);
	Shape* e2 = &c2;
	Circle c3(p3, r);
	Shape* m = &c3;

	Kind k;
	if (points.size() == 3){
		k = Kind::circle;
	}
	if (points.size() == 6){
		k = Kind::triangle;
	}

	if (points.size() == 6){
		k = Kind::triangle;
	}

	switch (k) {
	case Kind::circle:
		// read circle data {Point,int} into p and r
		return new Circle{ p, r };
	case Kind::triangle:
		// read triangle data {Point,Point,Point} into p1, p2, and p3
		return new Triangle{ p1, p2, p3 };
	case Kind::smiley:
		// read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1, e2, and m
		Smiley* ps = new Smiley{ p, r };
		ps->add_eye(e1);
		ps->add_eye(e2);
		ps->set_mouth(m);
		return ps;
	}

	return new Circle{ p, r };
}

//Avoiding Resource Leaks
unique_ptr<Shape> read_shape_unique(istream& is) // read shape descriptions from input stream is
{
	// read shape header from is and find its Kind k
	vector<double> points;
	for (double point; is >> point;) {
		points.push_back(point);
	}

	Kind k;
	if (points.size() == 3){
		k = Kind::circle;
	}
	if (points.size() == 6){
		k = Kind::triangle;
	}

	if (points.size() == 6){
		k = Kind::triangle;
	}

	Point p(0, 1);
	int r = 2;

	switch (k) {
	case Kind::circle:
		// read circle data {Point,int} into p and r
		return unique_ptr<Shape> {new Circle{ p, r }};       // �11.2.1
		// ...
	};

	return unique_ptr<Shape> {new Circle{ p, r }};
}

void draw_all(vector<Shape*> shapes) {
	for (auto p : shapes)
		p->draw();
}

void draw_all_unique(vector<unique_ptr<Shape>>& shapes) {
	for (auto& p : shapes)
		p->draw();
}

void rotate_all_unique(vector<unique_ptr<Shape>>& v, int angle) // rotate v's elements by angle degrees
{
	for (auto& p : v)
		p->rotate(angle);
}

void use_shape()
{
	istringstream iss("12 13 14");

	vector<Shape*> v;
	while (iss)
		v.push_back(read_shape(iss));
	draw_all(v);               // call draw() for each element
	rotate_all(v, 45);          // call rotate(45) for each element
	for (auto p : v)           // remember to delete elements
		delete p;

	iss.clear();
	iss.seekg(0, ios::beg);

	//cast shape to smiley
	Shape* ps{ read_shape(iss) };

	if (Smiley* p = dynamic_cast<Smiley*>(ps)) {
		// ... is the Smiley pointer to by p ...
	}
	else {
		// ... not a Smiley, try something else ...
	}

	iss.clear();
	iss.seekg(0, ios::beg);

	//bad cast exception
	Shape* ps_badCast{ read_shape(iss) };
	Smiley& r{ dynamic_cast<Smiley&>(*ps_badCast) };    // somewhere, catch std::bad_cast

	iss.clear();
	iss.seekg(0, ios::beg);

	//all Shapes implicitly destroyed
	vector<unique_ptr<Shape>> v_unique;
	while (iss)
		v_unique.push_back(read_shape_unique(iss));
	draw_all_unique(v_unique);               // call draw() for each element
	rotate_all_unique(v_unique, 45);          // call rotate(45) for each element
}

void copyValue(Class_Complex z1)
{
	Class_Complex z2{ z1 };    // copy initialization
	Class_Complex z3;
	z3 = z2;            // copy assignment
	// ...
}

void bad_copy(Class_Vector v1)
{
	Class_Vector v2 = v1;    // copy v1's representation into v2
	v1[0] = 2;         // v2[0] is now also 2!
	v2[1] = 3;         // v1[1] is now also 3!
}

void sumVectors(const Class_Vector& x, const Class_Vector& y, const Class_Vector& z)
{
	Class_Vector r;
	// ...
	r = x + y + z;
	// ...
}

Class_Vector VectorCopyAndMove()
{
	Class_Vector x(1000);
	Class_Vector y(1000);
	Class_Vector z(1000);

	sumVectors(x, y, z);

	z = x;                // we get a copy
	y = std::move(x);     // we get a move
	return z;             // we get a move
};

// resource management
std::vector<thread> my_threads;

void heartbeat() {};

Class_Vector init(int n)
{
	thread t{ heartbeat };             // run heartbeat concurrently (on its own thread)
	my_threads.push_back(move(t));    // move t into my_threads
	// ... more initialization ...

	Class_Vector vec(n);
	for (int i = 0; i<vec.size(); ++i)
		vec[i] = 777;
	return vec;                       // move res out of init()
};

void AbstractTypeUse(){
	Container_Vector containerVector(10);
	containerVector.initializeVector({ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 });
	use(containerVector);

	Container_List lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	use(lc);

	vector<Shape*> shapes(0);
	rotate_all(shapes, 30);
	use_shape();

	Class_Complex c{ 2, 2 };
	copyValue(c);
	auto vcm = VectorCopyAndMove();

	Class_Complex z1 = 3.14; // z1 becomes {3.14,0.0}
	Class_Complex z2 = z1 * 2; // z2 becomes {6.28,0.0}

	//explicit Class_Vector(int s); don't allow int to vector conversion
	//Class_Vector v1 = 7; // OK: v1 has 7 elements
	
	Class_Vector v1(7);    // OK: v1 has 7 elements
	//Class_Vector v2 = 7;   // error: no implicit conversion from int to Vector

	auto v = init(10000);     // start heartbeat and initialize v
};