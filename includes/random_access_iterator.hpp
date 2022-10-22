
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
			random_access_iterator(const random_access_iterator& copy) : itr_ptr(copy.itr_ptr) {}
			~random_access_iterator() {}




		protected:
			pointer itr_ptr; 
	}

}