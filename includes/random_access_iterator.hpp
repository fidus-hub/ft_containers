
#pragma once

#include <iostream>

namespace ft
{
     template <class T, class Alloc = std::allocator<T> > 
    class random_access_iterator
    {
        public :
		typedef T																						value_type;
		typedef typename std::iterator<std::random_access_iterator_tag, value_type>::pointer			pointer;
		typedef typename std::iterator<std::random_access_iterator_tag, value_type>::reference			reference;
		typedef typename std::iterator<std::random_access_iterator_tag, value_type>::difference_type	difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, value_type>::iterator_category	iterator_category;


		protected:
			pointer _iterator; 
	}

}