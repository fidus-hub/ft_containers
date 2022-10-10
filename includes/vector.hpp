 #include <iostream>
 
 namespace ft 
 {
	 template <class T, class Allocator = std::allocator<T> >
	 class vector 
	 {
		public :
		typedef typename Allocator::reference 		reference;
		typedef typename Allocator::const_reference const_reference;
		// typedef typename ft::random_access_iterator<T>  iterator;
		// typedef typename ft::random_access_iterator<const T>    const_iterator;
		// typedef implementation defined
		// typedef implementation defined
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		//typedef ft::reverse_iterator<iterator>		reverse_iterator;
		//typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		

		//Constructors
		explicit vector(const Allocator& = Allocator());
		explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator());
        	template <class InputIterator>
        vector(InputIterator first, InputIterator last,const Allocator& = Allocator());
        vector(const vector<T,Allocator>& x);
       ~vector();

		//Operators
        vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

        // 	template <class InputIterator>
        // void assign(InputIterator first, InputIterator last)
		// {
		// 	erase(begin(),end());
		// 	insert(begin(),first,last);

		// }
	
        // void assign(size_type n, const T& u)
		// {
		// 	erase(begin(),end());
		// 	insert(begin(),n, u);
		// }
        allocator_type get_allocator() const;


		// iterators:
		// iterator begin();
		// const_iterator begin()const;
		// iterator end();
		// const_iterator end()const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;


		// 23.2.4.2 capacity:
		size_type size() const
		{
			return size_;
		}
		size_type max_size() const;
		void resize(size_type sz, T c = T()); size_type capacity() const;
		bool empty()const;
		void reserve(size_type n)
		{
			if (n > capacity_)
			{
				pointer tmp = alloc_.allocate(n);
				int i = 0;
				while (i < size_)
				{
					alloc_.contruct(&tmp[i],buffer_[i]);
					alloc_.destroy(&buff[i]);
					i++;
				}
				alloc_.deallocate(buffer_,capacity_);
				buff = tmp;
				capacity_ = n;
			}

		}


			// element access:
		reference operator[](size_typen); const_reference operator[](size_type n) const; const_reference at(size_type n) const; reference at(size_typen);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;


		// 23.2.4.3 modifiers:
		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void     swap(vector<T,Allocator>&);
        void     clear();

		private:
			size_t size_;
			size_t capacity_;
			allocator_type alloc_;
			pointer		buffer_;
			
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