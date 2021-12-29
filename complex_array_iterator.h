#pragma once
#include "complex.h"
#include "complex_array.h"

namespace ndb {
	class complex_array_iterator
	{
	public:
		friend class complex_array;
	private:
		complex_array& _array;
		complex* _ptr;
		complex_array_iterator(complex_array& array);
	public:
		complex_array_iterator(complex_array_iterator const&) = delete;
		complex_array_iterator& operator = (complex_array_iterator const&) = delete;
		complex* operator->() const;
		complex& operator*() const;
		operator bool() const;
		bool operator!() const;
		complex_array_iterator& operator++();
		complex_array_iterator& operator++(int);
	};
}

