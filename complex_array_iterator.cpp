#include "complex_array_iterator.h"

ndb::complex_array_iterator::complex_array_iterator(complex_array& array) : 
	_array(array), _ptr(array._data) {}

ndb::complex* ndb::complex_array_iterator::operator->() const {
	return _ptr;
}

ndb::complex& ndb::complex_array_iterator::operator*() const {
	return *_ptr;
}

ndb::complex_array_iterator::operator bool() const {
	return _ptr >= _array._data && _ptr < _array._data + _array._cap;
}

bool ndb::complex_array_iterator::operator!() const {
	return !this->operator bool();
}

ndb::complex_array_iterator& ndb::complex_array_iterator::operator++() {
	++_ptr;
	return *this;
}
ndb::complex_array_iterator& ndb::complex_array_iterator::operator++(int) {
	return ++(*this);
}