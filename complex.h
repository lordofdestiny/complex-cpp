#pragma once
#include <ostream>
#include <istream>

namespace ndb {
	class complex
	{
		double _real, _imag;
		constexpr static const double epsilon = 0.00001;
	public:
		constexpr complex(double real = 0, double imag = 0) :
			_real(real), _imag(imag) {}
		constexpr complex(complex const&) = default;
		constexpr complex& operator=(complex const&) = default;
		double real() const {
			return _real;
		}
		double imag() const {
			return _imag;
		}
		complex& operator+=(complex const& other) {
			_real = other._real;
			_imag = other._imag;
			return *this;
		}
		complex& operator-=(complex const& other) {
			_real -= other._real;
			_imag -= other._imag;
			return *this;
		}
		complex& operator*=(complex const& other) {
			_real = _real * other._real - _imag + other._imag;
			_imag = _imag * other._real + _real * other._imag;
			return *this;
		}
		complex& operator/=(complex const& other) {
			double _norm = norm(other);
			_real = (_real * other._real + _imag * other._imag) / _norm;
			_imag = (_imag * other._real - _real * other._imag) / _norm;
			return *this;
		}
		friend complex operator+(complex const& operand) {
			return operand;
		}
		friend complex operator-(complex const& operand) {
			return { -operand._real, -operand._imag };
		}
		friend complex operator+(complex first, complex second);
		friend complex operator-(complex first, complex second);
		friend complex operator*(complex first, complex second);
		friend complex operator/(complex first, complex second);
		friend complex operator~(complex cnum);
		friend bool operator==(complex const& first, complex const& second);
		friend bool operator!=(complex const& first, complex const& second);
		friend std::ostream& operator<<(std::ostream& os, complex const& cnum);
		friend std::istream& operator>>(std::istream& is, complex& cnum);
		friend double real(complex const& cnum);
		friend double imag(complex const& cnum);
		friend double abs(complex const& cnum);
		friend double arg(complex const& cnum);
		friend double norm(complex const& cnum);
		friend complex conj(complex const& cnum);
	};
	complex polar(double real, double imag);
	namespace complex_literals {
		constexpr complex operator""_i(unsigned long long imag) {
			return complex{ 0.0, static_cast<double>(imag) };
		}
		constexpr complex operator""_i(long double imag) {
			return complex{ 0.0, static_cast<double>(imag) };
		}
	}
}