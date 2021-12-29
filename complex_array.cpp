#include "complex_array.h"
#include <cmath>

ndb::complex_array::complex_array(unsigned capacity) : 
	_cap(capacity),
	_data(new complex[_cap]) {}

void ndb::complex_array::copy_data(complex_array const& source) {
	
	for (std::size_t i = 0; i < _cap; i++) {
		new(&_data[i]) complex(source._data[i]);
	}
}

void ndb::complex_array::free_data() {
	for (std::size_t i = 0; i < _cap; i++) {
		_data[i].~complex();
	}
	delete[] _data;
	_data = nullptr;
}

ndb::complex_array::complex_array(complex_array const& other) :
	_cap(other._cap), _data(new complex[_cap]) {
	copy_data(other);
}

ndb::complex_array::complex_array(complex_array&& other) noexcept: 
	_cap(other._cap), _data(std::exchange(other._data,nullptr)) {}

/*ndb::complex_array& ndb::complex_array::operator=(complex_array const& other) {
	if (this != &other) {
		_cap = other._cap;
		complex* new_data = new complex[_cap];
		
		free_data();

		_data = new_data;
		copy_data(other);
	}
	return *this;
}*/

/*ndb::complex_array& ndb::complex_array::operator=(complex_array&& other) noexcept {
	if (this != &other) {
		free_data();	
		_cap = other._cap;
		_data = std::exchange(other._data, nullptr);
	}
	return *this;
}*/

ndb::complex_array& ndb::complex_array::operator*=(complex_array other) {
	using std::swap;
	using ndb::swap;
	swap(*this, other);
	return *this;
}

ndb::complex_array::~complex_array() {
	free_data();
}

void ndb::swap(ndb::complex_array& lhs, ndb::complex_array& rhs) {
	using std::swap;

	swap(lhs._cap, rhs._cap);
	swap(lhs._data, rhs._data);
}

std::size_t ndb::complex_array::capacity() const {
	return _cap;
}

ndb::complex& ndb::complex_array::at(std::size_t index) {
	return const_cast<complex&>(const_cast<complex_array const&>(*this).at(index));
}

ndb::complex const& ndb::complex_array::at(std::size_t index) const {
	if (0 > index or index >= _cap) throw std::out_of_range("Index out of range!");
	return _data[index];
}

ndb::complex& ndb::complex_array::operator[](std::size_t index) {
	return const_cast<complex&>(const_cast<complex_array const&>(*this)[index]);
}

ndb::complex const& ndb::complex_array::operator[](std::size_t index) const {
	return _data[index];
}

std::size_t ndb::complex_array::operator()(const complex& c) const {
	return (*this)(0, _cap - 1, c);
}
std::size_t ndb::complex_array::operator()(std::size_t low, std::size_t high, const complex& c) const {
	if (low < 0) {
		low = 0;
	}
	if (low >= _cap) {
		low = _cap - 1;
	}
	if (high < 0) {
		high = 0;
	}
	if (high >= _cap) {
		high = _cap - 1;
	}
	for (std::size_t i = low; i < high; i++) {
		if (_data[i] == c) {
			return i;
		}
	}
	return std::numeric_limits< std::size_t>::max();
}

ndb::complex_array_iterator ndb::complex_array::get_iterator() {
	return complex_array_iterator(* this);
}