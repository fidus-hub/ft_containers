
#pragma once

#include <iostream>
#include "utils.hpp"

namespace ft
{
	template <class T> 
	class random_access_iterator
	{
		public :
			typedef T																						value_type;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::pointer						pointer;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::reference					reference;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category		iterator_category;

			random_access_iterator() :itr_ptr(nullptr) {}
			random_access_iterator(pointer ptr) : itr_ptr(ptr) {}
			random_access_iterator(const random_access_iterator& other) : itr_ptr(other.itr_ptr) {}
			~random_access_iterator() {}

			random_access_iterator& operator=(const random_access_iterator& other)
			{
				itr_ptr = other.itr_ptr;
				return *this;
			}

			pointer	get_pointer() const
			{
				return (itr_ptr);
			}

			random_access_iterator& operator++()
			{
				itr_ptr++;
				return *this;
			}
			random_access_iterator& operator++(int)
			{
				random_access_iterator tmp = *this;
				itr_ptr++;
				return tmp;
			}
			random_access_iterator& operator--()
			{
				itr_ptr--;
				return *this;
			}
			random_access_iterator& operator--(int)
			{
				random_access_iterator tmp = *this;
				operator--();
				return tmp;
			}
			random_access_iterator operator+(difference_type n) const
			{
				return (itr_ptr + n);
			}
			random_access_iterator operator-(difference_type n) const
			{
				return (itr_ptr - n);
			}
			random_access_iterator operator+=(difference_type n)
			{
				itr_ptr += n;
				return *this;
			}
			random_access_iterator operator-=(difference_type n)
			{
				itr_ptr -= n;
				return *this;
			}
			reference operator[](difference_type n) const
			{
				return *(itr_ptr + n);
			}
			reference operator*() const
			{
				return *itr_ptr;
			}
			pointer operator->() const
			{
				return &*itr_ptr;
			}
			operator random_access_iterator<const value_type>() const
			{
				return random_access_iterator<const value_type>(itr_ptr);
			}

		protected:
			pointer itr_ptr; 
	};
	template <class T>
	bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() == rhs.get_pointer());
	}
	template <class T>
	bool operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() != rhs.get_pointer());
	}
	template <class T>
	bool operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() < rhs.get_pointer());
	}
	template <class T>
	bool operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() <= rhs.get_pointer());
	}
	template <class T>
	bool operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() > rhs.get_pointer());
	}
	template <class T>
	bool operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() >= rhs.get_pointer());
	}
	template <class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& rand)
	{
		return (rand + n);
	}
	template <class T>
	typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return (lhs.get_pointer() - rhs.get_pointer());
	}

}