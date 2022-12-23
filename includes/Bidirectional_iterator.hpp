#pragma once

#include <iostream>
#include "utils.hpp"
#include "Map.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T>
	class Bidirectional_iterator
	{
	public:
//////////////////////* ----------- Member Types ----------- *//////////////////
		typedef typename ft::iterator<std::random_access_iterator_tag, pair<const Key, T> >::difference_type		difference_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, pair<const Key, T> >::value_type				value_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, pair<const Key, T> >::pointer				pointer;
		typedef typename ft::iterator<std::random_access_iterator_tag, pair<const Key, T> >::reference				reference;
		typedef typename ft::iterator<std::random_access_iterator_tag, pair<const Key, T> >::iterator_category		iterator_category;
		typedef my_node<const Key, T> 																			node_type;
		typedef pair< Key, T> 																					pair;
		pair *stock;
	

	private:
			node_type *node;
			node_type *root;
			node_type *end;

//////////////////* ----------- Value ----------- */////////////////////////////

	public:

				node_type* findmin(node_type* node)
				{
					node_type* CurrentNode = node;
					while (CurrentNode && CurrentNode->left != NULL)
						CurrentNode = CurrentNode->left;
					return CurrentNode;
				}
				node_type* findmin(node_type* node) const
				{
					node_type* CurrentNode = node;
					while (CurrentNode && CurrentNode->left != NULL)
						CurrentNode = CurrentNode->left;
					return CurrentNode;
				}
				node_type* findmax(node_type* node)
				{
					node_type* CurrentNode = node;
					while (CurrentNode && CurrentNode->right != NULL)
						CurrentNode = CurrentNode->right;
					return CurrentNode;
				}
				node_type* findmax(node_type* node) const
				{
					node_type* CurrentNode = node;
					while (CurrentNode && CurrentNode->right != NULL)
						CurrentNode = CurrentNode->right;
					return CurrentNode;
				}
//////////////////* ----------- Getters ----------- *///////////////////////////

		node_type* get_node() const
		{
			return node;
		};
		node_type* get_root() const
		{
			return root;
		};
		node_type* get_end() const
		{
			return end;
		};
//////////////* ----------- Constructors & Destructor ----------- */////////////

		Bidirectional_iterator() : node(NULL), root(NULL),end(NULL){};

		Bidirectional_iterator(node_type *_node,node_type *_root)
		{
			node = _node;
			root = _root;
			end = NULL;
		};

		Bidirectional_iterator(node_type *_node,node_type *_root,node_type* end)
		{
			node = _node;
			root = _root;
			this->end = end;
		}

		Bidirectional_iterator &operator=(Bidirectional_iterator const &other)
		{
			this->node = other.get_node();
			this->root = other.get_root();
			this->end = other.get_end();
			return *this;
		};

		~Bidirectional_iterator()
		{
		};
//////////////* ----------- Misc Operators ----------- *///////////////////////

		pair &operator*() const
		{
			return *node->pair;
			//return *node->pair;
		};
		pair *operator->() const
		{
			return (node->pair);
		};
//////////////* ----------- Arithmetic Operators ----------- *//////////////////

		Bidirectional_iterator &operator++()
		{
			node_type* nd = node;
			node_type* max = findmax(root);
	
			if (node == max)
			{
				node = NULL;
				end = node;
				return *this;
			}
			if (nd && nd->right != NULL)
				node = findmin(nd->right);
			else if (nd && nd->right == NULL)
			{
				node_type* prt = nd->par;
				while (prt != NULL && nd == prt->right)
				{
					nd = prt;
					prt = prt->par;

				}
				node = prt;
			}

			return (*this);
		};

		Bidirectional_iterator &operator--()
		{
			node_type *nd = node;
			if (node == NULL && end)
			{
				node = end;
				end = NULL;
				return (*this);
			}
			if (nd && nd->left != NULL)
			{
				node = findmax(nd->left);
			}
			else if (nd && nd->left == NULL)
			{
				node_type* prt = nd->par;
				while (prt != NULL && nd == prt->left)
				{
					nd = prt;
					prt = prt->par;
				}
				node = prt;
			}
			return (*this);
		};

		Bidirectional_iterator operator++(int)
		{
			Bidirectional_iterator tmp(*this);
			operator++();
			return tmp;
		};
		Bidirectional_iterator operator--(int)
		{
			Bidirectional_iterator tmp(*this);
			operator--();
			return tmp;
		};

		Bidirectional_iterator &operator +=(difference_type rhs)
		{
			for(difference_type it = rhs; it >= 1; it--)
			{
				(*this)++;
			}
				return *this;
		};
		Bidirectional_iterator &operator -=(difference_type rhs)
		{
			for(difference_type it = rhs; it >= 1; it--)
			{
				(*this)--;
			}
			return *this;
		};


		bool operator==(Bidirectional_iterator const &other) const
		{
			if (node == other.get_node())
				return true;
			return false;
		};

		bool operator!=(Bidirectional_iterator const &other) const
		{
			if (node == other.get_node())
				return false;
			return true;
		};

		operator Bidirectional_iterator<const Key, T>()
		{
			return Bidirectional_iterator<const Key, T>(node, root,end);
		};
	};
};
