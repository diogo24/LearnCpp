class Class_Vector {
private:
	double* elem;       // elem points to an array of sz doubles
	int sz;

	bool deleted;
public:
	Class_Vector() :elem{ new double[0] }, sz{ 0 } {};

	explicit Class_Vector(int s)  // no implicit conversion from int to Vector
		:elem{ new double[s] }, sz{ s }        // constructor: acquire resources
	{
		for (int i = 0; i != s; ++i)       // initialize elements
			elem[i] = 0;
	}

	Class_Vector(const Class_Vector& v); // copy constructor

	Class_Vector(Class_Vector&& a);                     // move constructor

	Class_Vector& operator=(const Class_Vector& a);      // copy assignment

	Class_Vector& operator=(Class_Vector&& a);          // move assignment

	Class_Vector(std::initializer_list<double>);     // initialize with a list of doubles
	// ...
	void push_back(double);                    // add element at end, increasing the size by one
	// ...

	~Class_Vector() { 
		if (!!deleted) {
			delete[] elem; 
			deleted = true;
		}
	}                     // destructor: release resources

	double& operator[](int i) { return elem[i]; }
	const double& operator[](int i) const { return elem[i]; };
	int size() const { return sz; }

	void print();
};

Class_Vector operator+(const Class_Vector& a, const Class_Vector& b);

void ClassVectorUse();