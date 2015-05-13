class Class_X {
public:
	Class_X(/*Sometype*/int s);            // "ordinary constructor": create an object
	Class_X();                    // default constructor
	Class_X(const Class_X&);            // copy constructor
	Class_X(Class_X&&);                 // move constructor
	Class_X& operator=(const Class_X&); // copy assignment: clean up target and copy
	Class_X& operator=(Class_X&&);      // move assignment: clean up target and move
	~Class_X();                   // destructor: clean up
	// ...
};