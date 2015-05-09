class Class_Vector {
private:
	double* elem;       // elem points to an array of sz doubles
	int sz;

	bool deleted;
public:
	Class_Vector() :elem{ new double[0] }, sz{ 0 } {};

	Class_Vector(int s) :elem{ new double[s] }, sz{ s }        // constructor: acquire resources
	{
		for (int i = 0; i != s; ++i)       // initialize elements
			elem[i] = 0;
	}

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
	int size() const { return sz; }

	void print();
};

void ClassVectorUse();