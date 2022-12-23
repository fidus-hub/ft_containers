#pragma once

#include <iostream>

namespace ft
{
	 	template <class Category, class T, class Distance = ptrdiff_t,
					class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

		template < class Iterator > 
	struct iterator_traits
	{
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;

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
	};

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
	};
	template <typename T> struct is_integral{static const bool value = false;};
	template <> struct is_integral<bool>{static const bool value = true;};
	template <> struct is_integral<char>{static const bool value = true;};
	template <> struct is_integral<char16_t>{static const bool value = true;};
	template <> struct is_integral<char32_t>{static const bool value = true;};
	template <> struct is_integral<wchar_t>{static const bool value = true;};
	template <> struct is_integral<signed char>{static const bool value = true;};
	template <> struct is_integral<short int>{static const bool value = true;};
	template <> struct is_integral<int>{static const bool value = true;};
	template <> struct is_integral<long int>{static const bool value = true;};
	template <> struct is_integral<long long int>{static const bool value = true;};
	template <> struct is_integral<unsigned char>{static const bool value = true;};
	template <> struct is_integral<unsigned short int>{static const bool value = true;};
	template <> struct is_integral<unsigned int>{static const bool value = true;};
	template <> struct is_integral<unsigned long int>{static const bool value = true;};
	template <> struct is_integral<unsigned long long int>{static const bool value = true;};

	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };


	template<class T1, class T2> 
    struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;
		first_type	first;
		second_type	second;

		pair() :first(first_type()),second(second_type()){};
		template<class U, class V>
		pair(const pair<U,V> &pr): first(pr.first), second(pr.second){}
		pair (const T1 &a, const T2 &b): first(a), second(b){}
		pair &operator=(const pair &other)
		{
			first = other.first;
			second = other.second;
			return *this; 
		}
    };


template<class T> 
const T& max(const T& a, const T& b)
{
	return (a < b) ? b : a;
}

// AVL tree my_node
template <class Key, class T>
struct my_node
{
	my_node* 				left;
	my_node* 				right;
	// int key;
	ft::pair<const Key, T> *pair;
	my_node* 				par;
	int 					height;
};

    template<class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2>& rhs)
    {
       return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template<class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2>& rhs)
    {
        return !(lhs==rhs);
    }

    template<class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2>& rhs)
    {
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
    }

    template<class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2>& rhs)
    {
       return !(rhs<lhs);
    }

    template<class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2>& rhs)
    {
        return rhs < lhs;
    }
    
    template<class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2>& rhs)
    {
        return !(lhs<rhs);
    }
    
    template<class T1, class T2>
    pair<T1, T2>make_pair(T1 x, T2 y)
    { 
        return (pair<T1, T2>(x, y));
    };

	 template<class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first, InputIterator1 last, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        for ( ; (first != last) && (first2 != last2); ++first, (void) ++first2)
        {
            if (comp(*first, *first2))
                return true;
            if (comp(*first2, *first))
                return false;
        }
        return (first == last) && (first2 != last2);
    };

};
