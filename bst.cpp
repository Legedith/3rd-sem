#include<iostream>
#include<conio.h>
using namespace std;
template <class N>
struct node
{
	N info;
	node *left=NULL;
	node *right=NULL;
};
template <class N>
class bst
{
	private:
		node<N>* root;
		int l;
		void inI(node<N>* r);
		void postI(node<N>* r);
		void preI(node<N>* r);
	public:
		void insertInternal(node<N>* ,N data);
		bst();
		~bst();
		void insert(N data);
		void pre();
		void in();
		void post();
};
template <class N>
bst<N>::bst()
{
	root = NULL;
	l = 0;
}
template <class N>
bst<N>::~bst()
{
	cout<<"Deleted\n";
}
template <class N>
void bst<N>::insert(N data)
{
	cout<<"Root is null: "<<(root==NULL)<<endl;
	insertInternal(root, data);
}
template <class N>
void bst<N>::insertInternal(node<N>* root, N data)
{
/*	cout<<"Root == r :  "<<(root==r)<<endl;
	if(r == NULL)
	{
		node<N>* leaf = new node<N>;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->info = data;
		r = leaf;
		cout<<"Inserted "<<r->info<<endl;
		cout<<"Root == r :  "<<(root==r)<<endl;
		getch();
		return;
	}
	if(r->left->info>=data)
	{
		insertInternal(r->left, data);
	}
	else
	{
		insertInternal(r->right, data);
	}*/
	node<N>* leaf = new node<N>;
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->info = data;
	if(root==NULL)
	{
		root=leaf;
	//	return;
		cout<<root->info<<endl;
		return;
	}
	else
	{
		if(root->info >data)
		{
			insertInternal(leaf->left,data);
		}
		else if(root->info<data)
		{
			insertInternal(leaf->left,data);
		}
	}
} 
template <class N>
void bst<N>::preI(node<N>* r)
{
	if(r == NULL)
	{
		return;
	}
	cout<<r->info<<" ";
	preI(r->left);
	preI(r->right);
}

template <class N>
void bst<N>::inI(node<N>* r)
{
	cout<<"In order";
	if(r == NULL)
	{
		return;
	}
	inI(r->left);
	cout<<r->info<<" ";
	inI(r->right);
}

template <class N>
void bst<N>::postI(node<N>* r)
{
	if(r == NULL)
	{
		return;
	}
	postI(r->left);
	postI(r->right);
	cout<<r->info<<" ";
}
template <class N>
void bst<N>::pre()
{
	preI(root);
}

template <class N>
void bst<N>::in()
{
	cout<<"Root->info: "<<root->info<<endl;
	inI(root);
}

template <class N>
void bst<N>::post()
{
	postI(root);
}


int main()
{
	bst<int> tree;
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	
	cout<<tree.root->info;
	getch();
//	tree.insert(4);
//	tree.insert(5);
//	tree.insert(6);
//	tree.insert(7);
//	tree.insert(8);
	tree.in();
	cout<<endl;
//	tree.pre();
//	cout<<endl;
//	tree.post();
//	cout<<endl;
	getch();
	return 0;	
}

