class Class_Y {
public:
	Class_Y(/*Sometype*/int s);
	Class_Y(const Class_Y&) = default;  // I really do want the default copy constructor
	Class_Y(Class_Y&&) = default;       // and the default copy constructor
	// ...
};