#if !defined(VECTOR_ITERATOR_HPP)
#define VECTOR_ITERATOR_HPP

# include <limits>	
# include <exception>
# include "../utils/iterator_traits.hpp"

namespace ft
{
	template <typename T>
	struct vectorIterator
	{
		public:
		typedef T						value_type;
		typedef value_type				*pointer;
		typedef value_type const 		*const_pointer;
		typedef value_type				&reference;
		typedef value_type const 		&const_reference;
		typedef std::ptrdiff_t 			difference_type;
		typedef ft::random_access_iterator_tag 	iterator_category;

		private:
		pointer m_ptr;

		public:
		pointer get_pointer() { return m_ptr; };
		vectorIterator(pointer ptr = NULL) : m_ptr(ptr) {};

		template<typename U>
		vectorIterator(vectorIterator<U> other) : m_ptr(other.get_pointer()) {};
		vectorIterator& operator++() {
			m_ptr++;
			return *this;
		}
		vectorIterator operator++(int)
		{
			vectorIterator it = *this;
			++(*this);
			return it;
		}
		vectorIterator& operator--()
		{
			m_ptr--;
			return *this;
		}
		vectorIterator operator--(int)
		{
			vectorIterator it = *this;
			--(*this);
			return it;
		}
		vectorIterator &operator+=(int value) 
		{
			m_ptr += value;
			return *this;
		}
		vectorIterator &operator-=(int value) 
		{
			m_ptr -= value;
			return *this;
		}	
		vectorIterator operator+(int value)
		{
			vectorIterator it = *this;
			it += value;
			return it;			
		}
		vectorIterator operator-(int value)
		{
			vectorIterator it = *this;
			it -= value;
			return it;			
		}
		difference_type operator-(vectorIterator const &other) const 
		{
			return (m_ptr - other.m_ptr);
		}
		reference operator[](int index)
		{
			return *(m_ptr + index);
		}
		pointer operator->()
		{
			return m_ptr;
		}
		reference operator*()
		{
			return *m_ptr;
		}
		bool operator==(const vectorIterator& other) const
		{
			return (other.m_ptr == m_ptr);
		}
		bool operator!=(const vectorIterator& other) const
		{
			return (other.m_ptr != m_ptr);
		}
	};
} // namespace ft

#endif