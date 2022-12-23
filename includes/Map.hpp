#pragma once

#include <iostream>
#include "AVL.hpp"
#include "reverse_iterator.hpp"
#include "Bidirectional_iterator.hpp"
#include "vector.hpp"
#include "utils.hpp"




namespace ft 
{
	template <class Key, class T, class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
//////////////////////* ----------- Member Types ----------- *//////////////////
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef pair<const Key, T>										value_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef typename Allocator::reference							reference;
			typedef typename Allocator::const_reference						const_reference;
			typedef size_t													size_type;
			 typedef typename ft::Bidirectional_iterator<const Key, T>		iterator;
			typedef typename ft::Bidirectional_iterator<const Key, T>		const_iterator;
			typedef typename Allocator::pointer								pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef std::reverse_iterator<iterator>							reverse_iterator;
			typedef std::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef ft::my_node<const Key, T>								node_type;
			typedef typename ft::AVL<const Key, T, Compare, Allocator >		tree_type;

		size_type 		_size;
		node_type 		*root;
		key_compare		_compare;
		allocator_type	_alloc;
		tree_type		tree;

		class value_compare
		: public std::binary_function<value_type, value_type, bool>
		{
		friend class Map;
		protected:
			Compare _comp;
			value_compare(Compare c) : _comp(c) {}

		public:
			bool operator()(const value_type &x, const value_type &y) const{ return _comp(x.first, y.first); }
		};
//////////////////* ----------- Member Functions ----------- *//////////////////

		explicit Map(const Compare &comp = Compare(), const Allocator &alloc = Allocator())
		{
			_size = 0;
			root = NULL;
			_compare = comp;
			_alloc = alloc;

		}
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = allocator_type(),  typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			_size = 0;
			root = NULL;
			_compare = comp;
			_alloc = alloc;
			insert(first,last);

		}
		Map(const Map &x)
		{
			root = NULL;
			_size = 0;
			*this = x;
		}
		~Map(){}

		Map &operator=(const Map &x)
		{
			erase(begin(), end());
			for (const_iterator it = x.begin(); it != x.end(); it++)
				insert(*it);
			_size = x.size();
			return *this;
		}

		allocator_type get_allocator() const
		{
			return _alloc;
		};
//////////////////* ----------- Iterators ----------- *////////////////////////

		iterator				begin()			{ return iterator(findmin(root), root); }
		const_iterator			begin()	const	{ return const_iterator(findmin(root), root); }
		iterator				end()			{ return iterator(NULL,root, findmax(root)); }
		const_iterator			end() const		{ return const_iterator(NULL, root,findmax(root)); }
		reverse_iterator 		rbegin()		{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin() const 	{ return reverse_iterator(end()); }
		reverse_iterator		rend()			{ return reverse_iterator(begin()); }
		const_reverse_iterator	rend() const	{ return reverse_iterator(begin()); }

//////////////////* ----------- CAPACITY ----------- */////////////////////////

		bool		empty() const		{ return _size == 0; }
		size_type	size() const		{ return _size; }
		size_type	max_size() const	{ return _alloc.max_size(); }
//////////////////* ----------- Element access ----------- *///////////////////

		mapped_type& operator[](const key_type& k)
		{
			iterator it = find(k);
				if (it == end())
				{
					root = tree.Insert(root, NULL, ft::make_pair(k, T()));
					_size++;
					return find(k)->second;
				}
				return it->second;
		}
//////////////////* ----------- MODIFIERS ----------- */////////////////////////

		pair<iterator, bool> insert(const value_type &k)
		{
			iterator it = find(k.first);
			if(it!= end())
				return pair<iterator,bool>(it, false);
			root = tree.Insert(root, NULL, k);
			_size++;
			return pair<iterator,bool>(it, true);
		}

		iterator insert(iterator position, const value_type &k)
			{
				iterator it = find(k.first);
				if (it != end())
					return position;
				root = tree.Insert(root, NULL, k);
				_size++;
				return begin();
			}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			for (InputIterator it = first; it != last; it++)
				insert(*it);
		}

		void erase(iterator position)
		{
			if (position != end())
			{
				root = tree.Delete(root, *position);
				_size--;
			}

		}
		void erase(iterator first, iterator last)
		{
			ft::Vector<Key> vec;
			for(iterator it = first; it != last; it++)
				vec.push_back(it->first);
			for (size_t i = 0; i < vec.size(); i++)
				erase(vec[i]);
		}
		size_t erase(const key_type &k)
		{
			iterator it = find(k);
			if (it == end())
				return 0;
			root = tree.Delete(root, *it);
			_size--;
			return 1;
		}
		void swap(Map &x)
		{
			node_type	*tmp	 = root;
			size_type	tmp_size = _size;
						root	 = x.root;
						x.root	 = tmp;
						_size	 = x._size;
						x._size  = tmp_size;
		}
		void clear()
		{
			_size = 0;
		}

//////////////////* ----------- OBSERVERS ----------- */////////////////////////

		key_compare key_comp() const
		{
			return _compare;
		}
		value_compare value_comp() const
		{
			return value_compare(_compare);
		}
//////////////////* ----------- OPERATIONS ----------- *////////////////////////

		iterator find(const key_type &k)
		{
			node_type* found = tree.find(root ,k);
			if (found != NULL)
				return iterator(found, root);
			return end();
		}
		const iterator find(const key_type &k) const
		{
			node_type * found = tree.find(root ,k);
			if (found != NULL)
				return const_iterator(found, root);
			return end();
		}
		size_type count(const key_type& x) const
		{
			if (find(x) != end())
				return 1;
			return 0;
		}
		iterator lower_bound(const key_type& x)
		{
			return iterator(tree.lowerBound(root,x),root);
		}
		const_iterator lower_bound(const key_type& x) const
		{
			return const_iterator(tree.lowerBound(root,x),root);
		}
		iterator upper_bound(const key_type& x)
		{
			return iterator(tree.upperbound(root,x),root);
		}
		const_iterator upper_bound(const key_type& x) const
		{
			return const_iterator(tree.upperbound(root,x),root);
		}
		ft::pair<const iterator, const iterator>equal_range(const key_type &k) const
		{
			return ft::pair<const iterator, const iterator>(lower_bound(k),upper_bound(k));
		}
		ft::pair< iterator,  iterator>equal_range(const key_type &k) 
		{
			return ft::pair< iterator,  iterator>(lower_bound(k),upper_bound(k));
		}

		node_type *findmin(node_type *root)
			{
				if (root == NULL)
					return NULL;
				while (root && root->left != NULL)
					root = root->left;
				return root;
			}
		node_type *findmax(node_type *root)
			{
				if (root == NULL)
					return NULL;
				while (root && root->right != NULL)
					root = root->right;
				return root;
			}
		node_type *findmin(node_type *root) const
			{
				if (root == NULL)
					return NULL;
				while (root && root->left != NULL)
					root = root->left;
				return root;
			}
		node_type *findmax(node_type *root) const
			{
				if (root == NULL)
					return NULL;
				while (root && root->right != NULL)
					root = root->right;
				return root;
			}


		// 	struct Trunk
		// {
		// 	Trunk *prev;
		// 	std::string str;
		
		// 	Trunk(Trunk *prev, std::string str)
		// 	{
		// 		this->prev = prev;
		// 		this->str = str;
		// 	}
		// };

		// void showTrunks(Trunk *p)
		// {
		// 	if (p == nullptr) {
		// 		return;
		// 	}
		
		// 	showTrunks(p->prev);
		// 	std::cout << p->str;
		// }

		// // template<class Key, class T>
		// void printTree(node_type* root, Trunk *prev, bool isLeft)
		// {
		// 	if (root == nullptr) {
		// 		return;
		// 	}
		
		// 	std::string prev_str = "    ";
		// 	Trunk *trunk = new Trunk(prev, prev_str);
		
		// 	printTree(root->right, trunk, true);
		
		// 	if (!prev) {
		// 		trunk->str = "———";
		// 	}
		// 	else if (isLeft)
		// 	{
		// 		trunk->str = ".———";
		// 		prev_str = "   |";
		// 	}
		// 	else {
		// 		trunk->str = "`———";
		// 		prev->str = prev_str;
		// 	}
		
		// 	showTrunks(trunk);
		// 	std::cout << " " << root->pair->first << std::endl;
		
		// 	if (prev) {
		// 		prev->str = prev_str;
		// 	}
		// 	trunk->str = "   |";
		
		// 	printTree(root->left, trunk, false);
		// }
	
	};
//////////////////* ----------- Non-Member Functions ----------- *//////////////////

	 template<class Key, class T, class Compare, class Alloc>
	bool operator==(const Map<Key, T, Compare, Alloc>&l, const Map<Key, T, Compare, Alloc> &r)
	{
		return std::equal(l.begin(), l.end(), r.begin());
	}
	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const Map<Key, T, Compare, Alloc>&l, const Map<Key, T, Compare, Alloc> &r)
	{
		return !(l == r);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ) 
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ) {

		return !( rhs < lhs );
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ) {

		return rhs < lhs;
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ) {

		return !(lhs < rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	void swap (Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y) {

		std::swap(x.root, y.root);
		std::swap(x._size, y._size);
		std::swap(x._alloc, y._alloc);
		std::swap(x._compare, y._compare);
	}
};

