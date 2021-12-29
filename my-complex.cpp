#include <iostream>
#include "complex.h"
#include "complex_array.h"

int main()
{
	ndb::complex_array arr(10);
	for (unsigned i = 0; i < arr.capacity(); i++) {
		arr[i] = ndb::complex(i / 2 + 3, 5 - i);
	}

	ndb::complex_array_iterator iter = arr.get_iterator();
	while (iter) {
		std::cout << '(' << iter->real() << ", " << iter->imag() << ")\n";
		std::cout << *iter << '\n';
		iter++;
	}
}