
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
			typedef T*																						pointer;
			typedef T&																						reference;
			typedef typename ft::iterator_traits<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<std::random_access_iterator_tag, T>::iterator_category		iterator_category;

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
				random_access_iterator tmp(itr_ptr);
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
				random_access_iterator tmp(itr_ptr);
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
				return itr_ptr;
			}
			operator random_access_iterator<const value_type>() const
			{
				return random_access_iterator<const value_type>(itr_ptr);
			}

		protected:
			pointer itr_ptr; 
	};

}