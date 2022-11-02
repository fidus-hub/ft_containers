#pragma once

#include <iostream>
#include "utils.hpp"

namespace ft
{
		template <class T> 
	class reverse_iterator
	{
		public :
			typedef T																				iterator_type; 
			typedef T																				value_type;
			typedef T*																				pointer;
			typedef T&																				reference;
			typedef typename ft::iterator_traits<std::reverse_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<std::reverse_iterator_tag, T>::iterator_category	iterator_category;

			reverse_iterator() : itr_ptr(nullptr) {}

			~reverse_iterator() {}

			reverse_iterator& operator=(const reverse_iterator& other)
			{
				itr_ptr = other.itr_ptr;
				return *this;
			}

			T base() const
			{
				return itr_ptr;
			}
			reference operator*() const
			{
				return *itr_ptr;
			}
			pointer operator->() const
			{
				return itr_ptr;
			}
			reverse_iterator& operator[](difference_type n) const
			{
				return *(itr_ptr + n);
			}


			random_access_iterator& operator++()
			{
				itr_ptr--;
				return *this;
			}
			random_access_iterator& operator++(int)
			{
				random_access_iterator tmp(itr_ptr);
				itr_ptr--;
				return tmp;
			}
			random_access_iterator& operator--()
			{
				itr_ptr++;
				return *this;
			}
			random_access_iterator& operator--(int)
			{
				random_access_iterator tmp(itr_ptr);
				operator++();
				return tmp;
			}
			random_access_iterator operator+(difference_type n) const
			{
				return (itr_ptr - n);
			}
			random_access_iterator operator-(difference_type n) const
			{
				return (itr_ptr + n);
			}
			random_access_iterator operator+=(difference_type n)
			{
				itr_ptr -= n;
				return *this;
			}
			random_access_iterator operator-=(difference_type n)
			{
				itr_ptr += n;
				return *this;
			}

			operator random_access_iterator<const value_type>() const
			{
				return random_access_iterator<const value_type>(itr_ptr);
			}


		protected:
			iterator_type itr_ptr; 
	};
	template <class T>
	bool operator== (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.get_pointer() == rhs.get_pointer());
	}
	template <class T>
	bool operator!= (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.get_pointer() != rhs.get_pointer());
	}
	template <class T>
	bool operator<  (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.get_pointer() > rhs.get_pointer());
	}
	template <class T>
	bool operator<=  (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.get_pointer() >= rhs.get_pointer());
	}
	template <class T>
	bool operator>  (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.get_pointer() < rhs.get_pointer());
	}
	template <class T>
	bool operator>=  (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.get_pointer() <= rhs.get_pointer());
	}
	template <class T>
	reverse_iterator<T> operator+ (typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& rand)
	{
		return (rand.base() - n);
	}
	template <class T>
	typename reverse_iterator<T>::difference_type operator- (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}