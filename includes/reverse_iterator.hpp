#pragma once

#include <iostream>
#include "utils.hpp"

namespace ft
{
		template <class T> 
	class reverse_iterator
	{
		public :
			typedef T													iterator_type; 
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

			reverse_iterator() : itr_ptr() {}
			explicit reverse_iterator(iterator_type it) : itr_ptr(it) {}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_itr) : itr_ptr(rev_itr.base()) {}

			iterator_type base() const
			{
				return itr_ptr;
			}
			reference operator*() const
			{
				return *itr_ptr;
			}
			pointer operator->() const
			{
				return &(operator*());;
			}
			reference operator[](difference_type n) const
			{
				return (itr_ptr[-n]);
			}


			reverse_iterator& operator++()
			{
				--itr_ptr;
				return *this;
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			reverse_iterator& operator--()
			{
				++itr_ptr;
				return *this;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator	tmp(this->base());
				tmp.itr_ptr -= n;
				return (tmp);
			}
			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator	tmp(this->base());
				tmp.itr_ptr += n;
				return (tmp);
			}
			reverse_iterator operator+=(difference_type n)
			{
				itr_ptr -= n;
				return *this;
			}
			reverse_iterator operator-=(difference_type n)
			{
				itr_ptr += n;
				return *this;
			}


		protected:
			iterator_type itr_ptr; 
	};
	template <class T>
	bool operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class T>
	bool operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class T>
	bool operator<(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class T>
	bool operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class T>
	bool operator>(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class T>
	bool operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class T>
	reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& rand)
	{
		return rand + n;
	}
	template <class T>
	typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}