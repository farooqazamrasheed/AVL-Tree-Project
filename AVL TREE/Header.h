#pragma once
#include <iostream>
using namespace std;

template <class T1>
class node
{
public:
	T1 data;
	node<T1>* left;
	node<T1>* right;
	int height;
	node()
	{
		data = 0;
		left = NULL;
		right = NULL;
		height = 0;
	}
	node(T1 val)
	{
		data = val;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

template <class T>
class AVL
{
	node<T>* root;
public:
	AVL()
	{
		root = NULL;
	}
	int max(T a, T b)

	{
		if (a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
	node<T>* rightrotate(node<T>* x)
	{
		node<T>* y = x->left;
		node<T>* T2 = y->right;

		y->right = x;
		x->left = T2;

		x->height = max(Height(x->left), Height(x->right)) + 1;
		y->height = max(Height(y->left), Height(y->right)) + 1;

		return y;
	}
	node<T>* leftrotate(node<T>* x)
	{
		node<T>* y = x->right;
		node<T>* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(Height(x->left), Height(x->right)) + 1;
		y->height = max(Height(y->left), Height(y->right)) + 1;

		return y;
	}
	int balancefactor(node<T>* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		return Height(temp->left) - Height(temp->right);

	}


	int getheight()
	{
		return Height(root);
	}
	int Height(node<T>* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		//return max(Height(temp->left), Height(temp->right)) + 1;
		return temp->height;
	}



	node<T>* InsertNode(node<T>* temp, T input)
	{
		if (temp == NULL)
		{

			temp = new node<T>(input);
			return temp;
		}
		else
		{
			if (temp->data > input)
			{
				temp->left = InsertNode(temp->left, input);
			}
			else if (temp->data < input)
			{
				temp->right = InsertNode(temp->right, input);
			}
			else
			{
				return temp;
			}
		}

		temp->height = max(Height(temp->left), Height(temp->right)) + 1;

		int bf = balancefactor(temp);

		//case 0
		if (bf == 0 || bf == -1 || bf == 1)
		{
			return temp;
		}

		//cases 1
		//Left side problem So Left Left Imbalance rotation So rotate right side
		else if (bf > 1 && input < temp->left->data)
		{
			temp = rightrotate(temp);
			return temp;
		}
		//case 2
		//Right side problem So Right Right Imbalance rotation So rotate left side
		else if (bf<-1 && input>temp->right->data)
		{
			temp = leftrotate(temp);
			return temp;
		}
		//case 3
		// Left side problem So Left Right Imbalance rotation So first rotate left then right rotation apply
		else if (bf > 1 && input > temp->left->data)
		{
			temp->left = leftrotate(temp->left);      ////
			temp = rightrotate(temp);
			return temp;
		}
		//case 4
		//Right side problem So Right Left Imbalance Rotation So first rotate right then left rotation apply
		else if (bf < -1 && input < temp->right->data)
		{

			temp->right = rightrotate(temp->right);      ////
			temp = leftrotate(temp);
			return temp;
		}
		return temp;
	}
	void InsertData(T input)
	{
		if (root == NULL)
		{
			root = InsertNode(root, input);
		}
		else
		{
			root = InsertNode(root, input);
		}
	}
	node<T>* Search(T input)
	{
		return SearchData(root, input);
	}
	node<T>* SearchData(node<T>* temp, T input)
	{
		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			if (temp->data == input)
			{
				return temp;
			}
			if (temp->data > input)
			{
				return SearchData(temp->left, input);
			}
			else
			{
				return SearchData(temp->right, input);
			}
		}
	}
	void Inorder()
	{
		Inorder(root);
	}
	void Inorder(node<T>* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			Inorder(temp->left);
			cout << temp->data << " ";
			Inorder(temp->right);
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void preorder(node<T>* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			cout << temp->data << " ";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
	void postorder()
	{
		postorder(root);
	}
	void postorder(node<T>* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			postorder(temp->left);
			postorder(temp->right);
			cout << temp->data << " ";
		}
	}
};
