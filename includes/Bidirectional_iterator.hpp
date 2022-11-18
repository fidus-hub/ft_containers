#pragma once

#include <iostream>
#include "utils.hpp"

namespace ft
{
        template<class T>
    class Bidirectional_iterator
    {
		public :
			typedef T		                                                                    value_type;
			typedef typename ft::iterator<std::Bidirectional_Iterator, T>::pointer				pointer;
			typedef typename ft::iterator<std::Bidirectional_Iterator, T>::reference			reference;
			typedef typename ft::iterator<std::Bidirectional_Iterator, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::Bidirectional_Iterator, T>::iterator_category	iterator_category;

			Bidirectional_iterator() :itr_ptr(nullptr) {}
			Bidirectional_iterator(pointer ptr) : itr_ptr(ptr) {}
			Bidirectional_iterator(const Bidirectional_iterator& other) : itr_ptr(other.itr_ptr) {}
			~Bidirectional_iterator() {}

			Bidirectional_iterator& operator=(const Bidirectional_iterator& other)
			{
				itr_ptr = other.itr_ptr;
				return *this;
			}

			pointer	base() const
			{
				return (itr_ptr);
			}

			Bidirectional_iterator& operator++()
			{
				itr_ptr++;
				return *this;
			}
			Bidirectional_iterator operator++(int)
			{
				Bidirectional_iterator tmp = *this;
				itr_ptr++;
				return tmp;
			}
			Bidirectional_iterator& operator--()
			{
				itr_ptr--;
				return *this;
			}
			Bidirectional_iterator operator--(int)
			{
				Bidirectional_iterator tmp = *this;
				operator--();
				return tmp;
			}
			reference operator*() const
			{
				return *itr_ptr;
			}
			pointer operator->() const
			{
				return &*itr_ptr;
			}
			operator Bidirectional_iterator<const value_type>() const
			{
				return Bidirectional_iterator<const value_type>(itr_ptr);
			}

		protected:
			pointer itr_ptr; 
	};
	template <class T>
	bool operator==(const Bidirectional_iterator<T>& lhs, const Bidirectional_iterator<T>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class T>
	bool operator!=(const Bidirectional_iterator<T>& lhs, const Bidirectional_iterator<T>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

}