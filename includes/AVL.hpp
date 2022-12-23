#include <iostream>
#include "utils.hpp"

namespace ft 
{


template <class Key, class T , class compare = std::less<Key>, class Alloc = std::allocator<Key> >
class AVL
{
	typedef my_node<Key, T>										node_type;
	typedef ft::pair<Key, T>									pair;
	typedef typename Alloc::template rebind<node_type>::other	rebind_allocator;
	typedef typename Alloc::template rebind<pair>::other		_allocator;
	rebind_allocator											Node_All;
	_allocator 													Pair_All;
	compare														_comp;


	public:
	AVL(rebind_allocator rebind = rebind_allocator(), _allocator alloc = _allocator(), compare _c = compare()) 
	{
		Node_All = rebind;
		Pair_All = alloc;
		_comp = _c;
	}
	~AVL() {
	}

	node_type* Insert(node_type* root, node_type* parent, pair _pair)
	{
		if (root == NULL) 
		{
			root = Node_All.allocate(1);
			root->pair = Pair_All.allocate(1);
			Pair_All.construct(root->pair, _pair);
			root->height = 1;
			root->left = NULL;
			root->right = NULL;
			root->par = parent;
			return root;
		}
		if (_comp(_pair.first, root->pair->first)) 
			root->left = Insert(root->left,root, _pair);
		else if (_comp(root->pair->first, _pair.first))
			root->right = Insert(root->right,root, _pair);
		root = Balance(root);
		UpdateHeight(root);

		return root;
	}

	node_type* Delete(node_type* root,pair _pair)
	{
		if (root == NULL)
			return NULL;
		else
		{	if (root->pair->first != _pair.first)
			{
				if (_comp(root->pair->first, _pair.first))
					root->right = Delete(root->right, _pair);
				else if (!_comp(root->pair->first, _pair.first)) 
					root->left = Delete(root->left, _pair);
			}
			if (root->pair->first == _pair.first)
			{
				if (root->right == NULL && root->left != NULL)
				{
					if (root->par != NULL) 
					{
						if (_comp(root->par->pair->first , root->pair->first))
							root->par->right = root->left;
						else
							root->par->left = root->left;
						UpdateHeight(root->par);
					}
					root->left->par = root->par;
					root->left = Balance(root->left);
					return root->left;
				}
				else if (root->left == NULL && root->right != NULL) 
				{
					if (root->par != NULL) 
					{
						if (_comp(root->par->pair->first , root->pair->first))
							root->par->right = root->right;
						else
							root->par->left = root->right;
						UpdateHeight(root->par);
					}
					root->right->par = root->par;
					root->right = Balance(root->right);
					return root->right;
				}

				else if (root->left == NULL && root->right == NULL) 
				{
					if ( root->par && _comp(root->par->pair->first, root->pair->first)) {
						root->par->right = NULL;
					}
					else if (root->par)
					{
						root->par->left = NULL;
					}
					if (root->par != NULL)
						UpdateHeight(root->par);
					root = NULL;
					return NULL;
				}

				else 
				{
					node_type* tmpnode = root;
					tmpnode = tmpnode->right;
					while (tmpnode->left != NULL) 
						tmpnode = tmpnode->left;

					pair *val =  tmpnode->pair;

					root->right = Delete(root->right, *tmpnode->pair);

					root->pair = val;

					root = Balance(root);
				}
			}
			if (root != NULL)
				UpdateHeight(root);
		}
		return root;
	}

/* ---------------------- ROTATIONS --------------------- */
	node_type* left_left(node_type* root)
	{

		node_type* tmpnode = root->left;

		root->left = tmpnode->right;

		if (tmpnode->right != NULL)
			tmpnode->right->par = root;


		tmpnode->right = root;

		tmpnode->par = root->par;

		root->par = tmpnode;


		if (tmpnode->par != NULL && _comp(root->pair->first, tmpnode->par->pair->first))
			tmpnode->par->left = tmpnode;
		else {
			if (tmpnode->par != NULL)
				tmpnode->par->right = tmpnode;
		}

		root = tmpnode;

		UpdateHeight(root->left);
		UpdateHeight(root->right);
		UpdateHeight(root);
		UpdateHeight(root->par);

		return root;
	}

	node_type* right_right (node_type* root)
	{

		node_type* tmpnode = root->right;

		root->right = tmpnode->left;

		if (tmpnode->left != NULL)
			tmpnode->left->par = root;


		tmpnode->left = root;


		tmpnode->par = root->par;


		root->par = tmpnode;


		if (tmpnode->par != NULL && _comp(root->pair->first, tmpnode->par->pair->first)) 
			tmpnode->par->left = tmpnode;
		else {
			if (tmpnode->par != NULL)
				tmpnode->par->right = tmpnode;
		}

		root = tmpnode;

		UpdateHeight(root->left);
		UpdateHeight(root->right);
		UpdateHeight(root);
		UpdateHeight(root->par);

		return root;
	}

	node_type* left_right(node_type* root)
	{
		root->left = right_right(root->left);
		return left_left(root);
	}

	node_type* right_left(node_type* root)
	{
		root->right = left_left(root->right);
		return right_right(root);
	}


	node_type *find(node_type *my_node, Key key)const
	{
		if (my_node == nullptr)
			return nullptr;
		if (!_comp(my_node->pair->first, key) && !_comp(key, my_node->pair->first))
			return my_node;
		else if (_comp(my_node->pair->first , key))
			return (find(my_node->right, key));
		else if (_comp(key, my_node->pair->first))
			return(find(my_node->left, key));
		return my_node; 
	}


	void UpdateHeight(node_type* root)
	{
		if (root != NULL) 
		{
			int val = 1;
			if (root->left != NULL)
				val = root->left->height + 1;

			if (root->right != NULL)
				val = max(val, root->right->height + 1);
			root->height = val;
		}
	}

	node_type* Balance(node_type* root)
	{

		int LeftHeight = 0;
		int RightHeight = 0;

		if (root->left != NULL)
			LeftHeight = root->left->height;

		if (root->right != NULL)
			RightHeight = root->right->height;

		if ((LeftHeight - RightHeight) == -2) 
		{
			int rightheight1 = 0;
			int rightheight2 = 0;
			if (root->right->right != NULL)
				rightheight2 = root->right->right->height;
			if (root->right->left != NULL)
				rightheight1 = root->right->left->height;
			if (rightheight1 > rightheight2) {
				root = right_left(root);
			}
			else 
				root = right_right(root);
		}
		else if ((LeftHeight - RightHeight) == 2)
		{

			int leftheight1 = 0;
			int leftheight2 = 0;
			if (root->left->right != NULL)
				leftheight2 = root->left->right->height;
			if (root->left->left != NULL)
				leftheight1 = root->left->left->height;
			if (leftheight1 > leftheight2) 
				root = left_left(root);
			else
				root = left_right(root);
		}
		return root;
	}


	node_type *lowerBound(node_type *root, const Key &k) const
			{
				node_type *r = NULL;
				while(root != nullptr)
				{
					if (!_comp(root->pair->first, k))
					{
						r = root;
						root = root->left;
					}
					else
						root = root->right;
				}
				return r;
			}
			node_type *upperbound(node_type *root, const Key &k)const
			{
				node_type *r = NULL;
				while(root != nullptr)
				{
					if (_comp(k,root->pair->first))
					{
						r = root;
						root = root->left;
					}
					else
						root = root->right;
				}
				return r;
			}
	node_type *findmin(node_type *root)
	{
		if (root == NULL)
			return NULL;
		if (root->left != NULL)
			root = root->left;
		return root;
	}
	node_type *findmax(node_type *root)
	{
		if (root == NULL)
			return NULL;
		if (root->right != NULL)
			root = root->right;
		return root;
	}


	void printpreorder(node_type* root)
	{
		// Print the my_node's value along
		// with its parent value


		if (root->par != NULL)
			std::cout << root->par->pair->first << std::endl;
		else
			std::cout << "NULL" << std::endl;

		// Recur to the left subtree
		if (root->left != NULL) {
			printpreorder(root->left);
		}

		// Recur to the right subtree
		if (root->right != NULL) {
			printpreorder(root->right);
		}
	}
	node_type *treeSuccessor(node_type *x)const
		{
			if (x == NULL)
				return x;
			if (x->right != NULL)
				return treemin(x->right);
			node_type *y = x->par;
			while(y!= NULL && (x == y->right ))
			{
				x = y;
				y = y->par;
			}
				return y;
		}
			node_type *treepredecessor(node_type *x)const
			{
				if (x == NULL)
					return x;
				if (x->left != NULL)
					return findmax(x->left);
				node_type *y = x->par;
				while(y!= NULL && (x == y->left))
				{
					x =y;
					y = y->par;
				}
				return y;
			}
};
}