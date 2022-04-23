#if !defined(REVERSE_ITERATOR_HPP)
#define REVERSE_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class reverse_iterator
	{
	private:
		Iterator m_baseit;

	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		
		reverse_iterator() : m_baseit() { }
		// template <typename U>
		// reverse_iterator(reverse_iterator<U>) {};

		// initialization constructor
		reverse_iterator(iterator_type it) : m_baseit(it) { }
		// copy constructor
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &other) : m_baseit(other.base()) { }
		// destructor
		~reverse_iterator() { }

		iterator_type base() const { return m_baseit; }

		reference operator*() const
		{
			iterator_type newIt(m_baseit);
			--newIt;
			return *newIt;
		}

		reverse_iterator operator+ (difference_type n)
		{
			m_baseit -= n;
			return *this;
		}

		reverse_iterator<Iterator> &operator++()
		{
			--m_baseit;
			return *this;
		}

		reverse_iterator<Iterator> operator++(int)
		{
			reverse_iterator<Iterator> it(m_baseit--);
			return it;
		}

		reverse_iterator<Iterator> &operator+=(difference_type offset)
		{
			m_baseit -= offset;
			return *this;
		}

		reverse_iterator operator- (difference_type n)
		{
			m_baseit += n;
			return *this;
		}

		reverse_iterator<Iterator> &operator--()
		{
			++m_baseit;
			return *this;
		}

		reverse_iterator<Iterator> operator--(int)
		{
			reverse_iterator<Iterator> it(m_baseit++);
			return it;
		}

		reverse_iterator<Iterator> &operator-=(difference_type offset)
		{
			m_baseit += offset;
			return *this;
		}

		pointer operator->() const
		{
			iterator_type it(m_baseit);
			--it;
			return it.operator->();
		}

		reverse_iterator<Iterator> &operator=(const reverse_iterator<Iterator> &other)
		{
			m_baseit = other.m_baseit;
			return *this;
		}

		reference operator[] (difference_type n) const
		{
			return m_baseit[-n-1];
		}

	};

	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	// template <typename Iterator>
	// bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	// {
	// 	return lhs.base() != rhs.base();
	// }

	template <typename Iterator1, typename Iterator2>
	bool operator!= ( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>&  rhs )
	{
		return  !(lhs.base() == rhs.base());
	}

	// template <typename Iterator>
	// bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	// {
	// 	return lhs.base() > rhs.base();
	// }

	template <typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(const reverse_iterator<Iterator> &it, size_t n)
	{
		reverse_iterator<Iterator> r(it.base() - n);
		return r;
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
	{
		reverse_iterator<Iterator> r(it.base() - n);
		return r;
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator-(const reverse_iterator<Iterator> &it, typename reverse_iterator<Iterator>::difference_type n)
	{
		reverse_iterator<Iterator> r(it.base() + n);
		return r;
	}

	template <typename Iterator>
	std::ptrdiff_t operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return rhs.base() - lhs.base();
	}
} // namespace ft


#endif // REVERSE_ITERATOR_HPP
