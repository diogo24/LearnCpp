#include "stdafx.h"

namespace My_code {
	class complex {
		// ...
	private:
		int _real;
		int _imag;

	public:
		complex(int real, int imag);
		int real();
		int imag();
	};

	complex sqrt(complex);
	// ...

	int main();
}

int ModularityDefinedMain();

