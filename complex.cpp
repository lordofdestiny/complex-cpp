#include "complex.h"
#include <cmath>

namespace ndb {
	complex operator+(complex first, complex second) {
		return { first._real + second._real, first._imag + second._imag };
	}

	complex operator-(complex first, complex second) {
		return { first._real - second._real, first._imag - second._imag };
	}

	complex operator*(complex first, complex second) {
		return {
			first._real * second._real - first._imag * second._imag,
			first._imag * second._real + first._real * second._imag
		};
	}
	complex operator/(complex first, complex second) {
		double _norm = norm(second);
		return {
			(first._real * second._real + first._imag * second._imag) / _norm,
			(first._imag * second._real - first._real * second._imag) / _norm
		};
	};
	complex operator~(complex cnum) {
		return { cnum._real, -cnum._imag };
	}

	bool operator==(complex const& first, complex const& second) {
		return std::abs(first._real - second._real) < complex::epsilon 
			&& std::abs(first._imag - second._imag) < complex::epsilon;
	}
	bool operator!=(complex const& first, complex const& second) {
		return !(first == second);
	}
	std::ostream& operator<<(std::ostream& os, complex const& cnum) {
		return os << "(" << cnum._real << "," << cnum._imag << ")";
	}
	std::istream& operator>>(std::istream& is, complex& cnum) {
		return is >> cnum._real >> cnum._imag;
	}
	double real(complex const& cnum) {
		return cnum._real;
	}
	double imag(complex const& cnum) {
		return cnum._imag;
	}
	double abs(complex const& cnum) {
		return std::hypot(cnum._real, cnum._imag);
	}
	double arg(complex const& cnum) {
		return std::atan2(cnum._imag, cnum._real);
	}
	double norm(complex const& cnum) {
		return std::pow(cnum._real, 2) + std::pow(cnum._imag, 2);
	}
	complex conj(complex const& cnum) {
		return { cnum._real, -cnum._imag };
	}
	complex polar(double mag, double arg) {
		return { mag * std::cos(arg),mag * std::sin(arg) };
	}
}