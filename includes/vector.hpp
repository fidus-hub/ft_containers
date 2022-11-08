 #include <iostream>
 

 namespace ft 
 {
	 template <class T, class Allocator = std::allocator<T> >
	 class vector 
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
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		

		//Constructors
		explicit vector(const Allocator& = Allocator());
		explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator());
        	template <class InputIterator>
        vector(InputIterator first, InputIterator last,const Allocator& = Allocator());
        vector(const vector<T,Allocator>& x);
       ~vector();

		//Operators
		vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
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
		void assign(InputIterator first, InputIterator last)
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
			return iterator(buffer_ + size_)
		}
		const_iterator end()const
		{
			return const_iterator(buffer_ + size_)
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
			return const_reverse_iterator(const_iterator(buffer_)));
		}


		// 23.2.4.2 capacity:
		size_type size() const
		{
			return (size_);
		}
		size_type max_size() const;
		{
			return _alloc.max_size()
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
				reserve(n);
				size_t i = size_;
				while(i < n)
				{
					alloc_.contruct(&buffer_[i],val);
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
				int i = 0;
				while (i < size_)
				{
					alloc_.construct(&tmp[i],buffer_[i]);
					alloc_.destroy(&buffer_[i]);
					i++;
				}
				alloc_.deallocate(buffer_,capacity_);
				buff = tmp;
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
				throw std::out_of_range("vector out of range");
			return buffer_[n];
		}
		reference at(size_type n)
		{
			if(n > size_)
				throw std::out_of_range("vector out of range");
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
		void push_back(const t& val)
		{
			if(size_ == capacity_)
				reserve(capacity_ == 0 ? 1 : capacity_ * 2);
			buffer_[size_ + 1] = val;
			++size_;
		}
		void pop_back()
		{
			alloc_.destroy(&buffer_[size_])
			size_--;
		}
		void swap (vector& x)
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
			int i = 0;
			while(i < size_)
			{
				alloc_.destroy(&buffer_[i])
				i++;
			}
			size_ = 0;
		}
		iterator insert(iterator position, const T& val)
		{
			size_t len = std::distance(begin(),position);
			size_ += 1;
			if (size_ >= capacity_)
				reserve (capacity_ * 2)
			size_t i = size_;
			while(i > len)
			{
				buffer_[i] = buffer_[i - 1];
				i--;
			}
			buffer_[len] = val;
			return &buffer_[len];
		}
		void insert(iterator position, size_type n, const T& val)
		{
			size_t len = std::distance(begin(),position);
			size_ += n;
			if (size_ >= capacity_)
				reserve (capacity_ * 2)
			size_t i = size_;
			while(i > len)
			{
				buffer_[i] = buffer_[i - n];
				i--;
			}
			for(j = (len + n); j > len; j--)
				buffer_[j] = val;
			return &buffer_[len];
		}
			template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			size_t n = last - first;
			size_t len = std::distance(begin(), position);
			size_ += n;
			if (size_ >= capacity_)
				reserve (capacity_ * 2)
			for(size_t i = size_; i > len; i--)
				buffer_[i] = buffer_[i - n];
			for(size_t i = len; i < len + n && first != last; i++,first++)
				buffer_[i] = *first;
				//alloc_.construct(&buffer_[i],*first);
		}
		iterator erase(iterator position)
		{
			//size_t len = std::distance(begin(),position);
			//_alloc.destroy(&buffer_[len]);
			//size_t i = len;
			//while(i < size_ - 1)
			//{
			//	buffer_[i] = buffer_[i + 1];
			//	i++;
			//}
			//--_size;
			//return position;

			size_t len = std::distance(begin(),position);
			size_t i = len;
			while(i < size_ - 1)
			{
				std::swap(buffer_[i], buffer_[i + 1]);
				i++;
			}
			_alloc.destroy(&buffer_[size_ - 1]);
			size_ - 1;
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

			// size_t dis = 0;
			// size_t len = 0;

			// des = std::distance(first,last);
			// len = std::distance(begin(),first);
			// for(int i = len; i < len + des; i++)
			// 	_alloc.destroy(&buffer_[i]);
			// for(int i = len; i < size_ - des; i++)
			// 	buffer_[i] = buffer_[i + des];
			// size_ -= des;
			// return iterator(&buffer_[len]);
		}

		private:
			size_t 			size_;
			size_t 			capacity_;
			allocator_type 	alloc_;
			pointer			buffer_;
			
	 };



    //   template <class T, class Allocator>
    //     bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    //   template <class T, class Allocator>
    //     bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    //   template <class T, class Allocator>
    //     bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    //   template <class T, class Allocator>
    //     bool operator> (const vector<T,Allocator>& x,const vector<T,Allocator>& y);
    //   template <class T, class Allocator>
    //     bool operator>=(const vector<T,Allocator>& x,const vector<T,Allocator>& y);
    //   template <class T, class Allocator>
    //     bool operator<=(const vector<T,Allocator>& x,const vector<T,Allocator>& y);

 }

 int main()
 {
	//  ft::vector<int>  amine(10,15);

	//  ft::vector<int> copy_amine;
	//  copy_amine(amine.begin(),  amine.end());
	//  amine.push_back(10);
	// ft::vector<int>::iterator it;

 }