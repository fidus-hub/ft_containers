#pragma once

#include <iostream>

namespace ft
{
		template <class Iter> 
	struct iterator_traits
	{
		typedef typename Iter::difference_type			difference_type;
		typedef typename Iter::value_type				value_type;
		typedef typename Iter::pointer					pointer;
		typedef typename Iter::reference				reference;
		typedef typename Iter::iterator_category		iterator_category;

	};

		template< class T >
	struct iterator_traits<T*>
	{
		typedef	std::ptrdiff_t							difference_type;
		typedef	T										value_type;
		typedef	T*										pointer;
		typedef	T&										reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};

		template< class T >
	struct iterator_traits<const T*>
	{
		typedef	std::ptrdiff_t							difference_type;
		typedef	T										value_type;
		typedef	const T*								pointer;
		typedef	const T&								reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};

		template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
				++first1; ++first2;
		}
		return true;
	}

		template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	
}