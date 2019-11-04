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
		void insertInternal(node<N>* ,N data);
	public:
		bst();
		~bst();
		void insert(N data);
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
void bst<N>::insertInternal(node<N>* r, N data)
{
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
	}
} 

int main()
{
	bst<int> tree;
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	getch();
	return 0;	
}

