#include "stdafx.h"

class Shape {
public:
	virtual Point center() const = 0;     // pure virtual
	virtual void move(Point to) = 0;

	virtual void draw() const = 0;       // draw on current "Canvas"
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {}                  // destructor
	// ...
};

std::unique_ptr<Shape> read_shape_unique(std::istream& is);