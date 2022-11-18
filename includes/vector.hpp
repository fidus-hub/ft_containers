 #include <iostream>
 #include "random_access_iterator.hpp"
 #include "reverse_iterator.hpp"
 

 namespace ft 
 {
	 template <class T, class Allocator = std::allocator<T> >
	 class Vector 
	 {
		public :
		typedef typename Allocator::reference 		reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename ft::random_access_iterator<T>  iterator;
		typedef typename ft::random_access_iterator<const T>    const_iterator;
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef ft::reverse_iterator<iterator>		reverse_iterator;
		typedef size_t								size_type;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		

		//Constructors
		explicit Vector(const allocator_type& alloc = allocator_type())
		{
			size_ = 0;
			capacity_ = 0;
			alloc_ = alloc;
			buffer_ = NULL;
		}
		explicit Vector(size_type n, const T& value = T(), const allocator_type& alloc = allocator_type())
		{
			size_ = n;
			capacity_ = n;
			alloc_ = alloc;
			buffer_ = alloc_.allocate(n);
			for(size_t i = 0; i < n; i++)
				alloc_.construct(&buffer_[i], value);
		}
			template <class InputIterator>
		 Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator >::type = InputIterator()) 
		{
			size_t n = last - first;
			alloc_ = alloc;
			size_ = n;
			capacity_ = n;
			buffer_ = alloc_.allocate(n);
			for(size_t i = 0; first != last; i++,first++)
				buffer_[i] = *first;
			}

		Vector(const Vector<T,Allocator>& x)r
		{
			size_ = x.size_;
			capacity_ = x.capacity_;
			buffer_ = alloc_.allocate(capacity_);
			for (size_t i = 0 ; i < size_ ; i++)
				alloc_.construct(&buffer_[i], x.buffer_[i]);

		}
		~Vector()
		{
			alloc_.deallocate(buffer_, capacity_);
			for (size_t i = 0; i < size_; i++)
				alloc_.destroy(&buffer_[i]);
		}

		//Operators
		Vector<T,Allocator>& operator=(const Vector<T,Allocator>& x)
		{
			size_ = x.size_;
			capacity_ = x.capacity_;
			buffer_ = alloc_.allocate(capacity_);
			size_t i = 0;
			while(i < size_)
			{
				alloc_.construct(&buffer_[i], x.buffer_[i]);
				i++;
			}
			return *this;
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,  typename enable_if<!ft::is_integral<InputIterator>::value,InputIterator >::type = InputIterator())
		{
			erase(begin(),end());
			insert(begin(),first,last);

		}
	
		void assign(size_type n, const T& value)
		{
			erase(begin(),end());
			insert(begin(),n, value);
		}
		allocator_type get_allocator() const
		{
			return alloc_ ;
		}


		// iterators:
		iterator begin()
		{
			return iterator(buffer_);
		}
		const_iterator begin()const
		{
			return const_iterator(buffer_);
		}
		iterator end()
		{
			return iterator(buffer_ + size_);
		}
		const_iterator end()const
		{
			return const_iterator(buffer_ + size_);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(const_iterator(buffer_ + size_));
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(const_iterator(buffer_));
		}


		// 23.2.4.2 capacity:
		size_type size() const
		{
			return (size_);
		}
		size_type max_size() const
		{
			return alloc_.max_size();
		}
		size_type capacity() const
		{
			return (capacity_);
		}
		bool empty()const
		{
			return (size_ == 0);
		}
		void resize (size_type n, value_type val = value_type())
		{
			if(n < size_)
			{
				size_t i = size_;
				while(i > n)
				{
					alloc_.destroy(&buffer_[i]);
					i--;
				}
			}
			if(n > size_)
			{
				if (n > capacity_)
					reserve(n);
				size_t i = size_;
				while(i < n)
				{
					alloc_.construct(&buffer_[i],val);
					i++;
				}
			}
			size_ = n;
		}
		// void resize (size_type n, value_type val = value_type())
		// {
		// 	while(n < size_)
		// 		pop_back();
		// 	while (n > size_)
		// 		push_back(val);
		// }

		void reserve(size_type n)
		{
			if (n > capacity_)
			{
				pointer tmp = alloc_.allocate(n);
				size_t i = 0;
				while (i < size_)
				{
					alloc_.construct(&tmp[i],buffer_[i]);
					alloc_.destroy(&buffer_[i]);
					i++;
				}
				alloc_.deallocate(buffer_,capacity_);
				buffer_ = tmp;
				capacity_ = n;
			}

		}


			// element access:
		reference operator[](size_type n)
		{
			return buffer_[n];
		}
		const_reference operator[](size_type n) const
		{
			return buffer_[n];
		}
		const_reference at(size_type n) const
		{
			if(n > size_)
				throw std::out_of_range("Vector out of range");
			return buffer_[n];
		}
		reference at(size_type n)
		{
			if(n > size_)
				throw std::out_of_range("Vector out of range");
			return buffer_[n];
		}
		reference front()
		{
			return buffer_[0];
		}
		const_reference front() const
		{
			return buffer_[0];
		}
		reference back()
		{
			return buffer_[size_ -1];
		}
		const_reference back() const
		{
			return buffer_[size_ -1];
		}


		// 23.2.4.3 modifiers:
		void push_back(const T& val)
		{
			if(size_ == capacity_)
				reserve(capacity_ == 0 ? 1 : capacity_ * 2);
			buffer_[size_] = val;
			++size_;
		}
		void pop_back()
		{
			alloc_.destroy(&buffer_[size_]);
			size_--;
		}
		void swap (Vector& x)
		{
			size_t			tmpSize = size_;
			size_t			tmpCapacity = capacity_;
			value_type		*tmpBuffer = buffer_;

			size_		=	x.size_;
			capacity_	=	x.capacity_;
			buffer_		=	x.buffer_;

			x.size_		=	tmpSize;
			x.capacity_	=	tmpCapacity;
			x.buffer_	=	tmpBuffer;
		}
		void	clear()
		{
			size_t i = 0;
			while(i < size_)
			{
				alloc_.destroy(&buffer_[i]);
				i++;
			}
			size_ = 0;
		}
		iterator insert(iterator position, const T& val)
		{
			size_t len = std::distance(begin(),position);
			if (size_ >= capacity_)
			{
				if (size_ == 0)
					reserve(1);
				else
					reserve (capacity_ * 2);
			}
			size_t i = size_;
			while(i > len)
			{
				buffer_[i] = buffer_[i - 1];
				i--;
			}
			buffer_[len] = val;
			size_ += 1;
			return &buffer_[len];
		}
		void insert(iterator position, size_type n, const T& val)
		{
			size_t len = std::distance(begin(),position);
			if (size_ + n > capacity_)
			{
				if (n > size_)
					reserve(n + size_);
				else
					reserve(capacity_ * 2);
			}
			size_t i = size_;
			while(i > len)
			{
				alloc_.construct(&buffer_[i + n - 1], buffer_[i - 1]);
				i--;
			}
			for(size_t j = len; j < len + n; j++)
				alloc_.construct(&buffer_[j],val);
			size_ += n;
		}
			template <class InputIterator>
		void    insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value,InputIterator >::type = InputIterator())
		{
			size_t n = last - first;
			size_t len = std::distance(begin(), position);
			if (size_ + n > capacity_)
			{
				if (n > size_)
					reserve(n + size_);
				else
					reserve(capacity_ * 2);
			}
			for(size_t i = size_; i > len; i--)
				buffer_[i + n - 1] = buffer_[i - 1];
			for(size_t i = len; i < len + n && first != last; i++,first++)
				alloc_.construct(&buffer_[i],*first);
			size_ += n;
		}
		iterator erase(iterator position)
		{
			size_t len = std::distance(begin(),position);
			size_t i = len;
			while(i < size_ - 1)
			{
				std::swap(buffer_[i], buffer_[i + 1]);
				i++;
			}
			alloc_.destroy(&buffer_[size_ - 1]);
			size_--;
			return (position);
		}
		iterator erase(iterator first, iterator last)
		{
			size_t len = std::distance(first,last);
			for (size_t i = 0 ; i < len ; i++)
			{
				erase(first);
			}
			return (first);
		}

		private:
			size_t 			size_;
			size_t 			capacity_;
			allocator_type 	alloc_;
			pointer			buffer_;
			
	};

		template <class T, class Allocator>
	bool operator==(const Vector<T,Allocator>& x, const Vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return false;
		return (ft::equal(x.begin(), x.end(), y.begin()));
	}
		template <class T, class Allocator>
	bool operator!=(const Vector<T,Allocator>& x, const Vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return true;
		for (size_t i = 0 ; i < x.size() ; i++)
		{
		if (x[i] != y[i])
			return true;
		}
		return false;
	}
		template <class T, class Allocator>
	bool operator< (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
		template <class T, class Allocator>
	bool operator> (const Vector<T,Allocator>& x,const Vector<T,Allocator>& y)
	{
		return (ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
	}
		template <class T, class Allocator>
	bool operator>=(const Vector<T,Allocator>& x,const Vector<T,Allocator>& y)
	{
		if (x > y || x == y)
			return (true);
		return (false);
	}
		template <class T, class Allocator>
	bool operator<=(const Vector<T,Allocator>& x,const Vector<T,Allocator>& y)
	{
		if (x < y || x == y)
			return (true);
		return (false);
	}

		template <class T, class Alloc>
	void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
	{
		x.swap(y);
	}
 }
