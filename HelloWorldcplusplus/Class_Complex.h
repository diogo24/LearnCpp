namespace ArithmeticTypes {
	class Class_Complex {
		double re, im; // representation: two doubles
	public:
		Class_Complex(double r, double i) :re{ r }, im{ i } {}    // construct complex from two scalars
		Class_Complex(double r) :re{ r }, im{ 0 } {}              // construct complex from one scalar
		Class_Complex() :re{ 0 }, im{ 0 } {}                      // default complex: {0,0}

		double real() const { return re; }
		void real(double d) { re = d; }
		double imag() const { return im; }
		void imag(double d) { im = d; }

		Class_Complex& operator+=(Class_Complex z) { re += z.re, im += z.im; return *this; }   // add to re and im and return the result
		Class_Complex& operator-=(Class_Complex z) { re -= z.re, im -= z.im; return *this; }

		Class_Complex& operator*=(Class_Complex);    // defined out-of-class somewhere
		Class_Complex& operator/=(Class_Complex);    // defined out-of-class somewhere

		void print();
	};
}

void ClassComplexUse(ArithmeticTypes::Class_Complex z);