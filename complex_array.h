#pragma once
#include "complex.h"
#include "complex_array_iterator.h"

namespace ndb {
	class complex_array
	{	
		void copy_data(complex_array const& source);
		void free_data();
		std::size_t _cap;
		complex* _data;
	public:
		explicit complex_array(unsigned);
		complex_array(complex_array const&);
		complex_array(complex_array&&) noexcept;
		//complex_array& operator=(complex_array const&);	
		//complex_array& operator=(complex_array&&) noexcept;
		complex_array& operator*=(complex_array other);

		friend void swap(ndb::complex_array& lhs, ndb::complex_array& rhs);

		std::size_t capacity() const;

		complex& at(std::size_t index);
		complex const& at(std::size_t index) const;

		complex& operator[](std::size_t index);
		complex const& operator[](std::size_t index) const;

		std::size_t operator()(const complex& c) const;
		std::size_t operator()(std::size_t low, std::size_t high, const complex& c) const;

		~complex_array();

		friend class complex_array_iterator;

		complex_array_iterator get_iterator();
	};

	void swap(ndb::complex_array& lhs, ndb::complex_array& rhs);
}