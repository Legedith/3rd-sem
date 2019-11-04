#include<iostream>
#include<conio.h>
using namespace std;
template <class N>
struct node
{
	N data;
	node *left=NULL;
	node *right=NULL;
};
template <class N>
class BST
{
	private:
		node<N>* root=NULL;
		int l;
	public:
		BST();
		int insert(node<N>* r,N data);
}
BST::BST()
{
	root=NULL;
	root->left=root->right=NULL;
	int l=0;
}
int BST::insert(node<N>* r,N val)
{
	node<N>* n=new node<N>;
	n->data=val;
	if(r==NULL)
	{
		r=n;
		return 1;
	}
	else
	{
		if(val<r->data)
		{
			insert(r->left,val);
		}
		else if(val>r->data)
		{
			insert(r->right,val);
		}
	}
}


