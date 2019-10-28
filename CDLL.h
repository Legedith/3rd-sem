#include<iostream>
#include<conio.h>
using namespace std;
template <class N>
struct node
{
	N info;
	node *next=NULL;
	node *prev=NULL;
};
template <class N>
class CDLL
{
	private:
		int l;
		node<N>* head=NULL;
	public:
		CDLL();
		node<N>* headptr();
		bool isempty();
		int length();
		void insert(int val, N info);
		void display();
		void reverse();
		void del(int);
		N svbi(int);
		int sibv(N);
		void displayalt();
		CDLL operator+(CDLL &L);
};
template <class N>
node<N>* CDLL<N>::headptr()
{
	return head;
}
template <class N>
CDLL<N>::CDLL()
{
	l=0;
	head=NULL;
}
template <class N>
bool CDLL<N>::isempty()
{
	if (head==NULL)
		return true;
	else
		return false;
}
template <class N>
int CDLL<N>::length()
{
	return l;
}
template <class N>
void CDLL<N>::insert(int pos,N inf)
{
	node<N> *n=new node<N>;
	n->info=inf;
	n->next=NULL;
	n->prev=NULL;
	if(pos == 0 or l==0)
	{
		if(head == NULL)
		{
			head = n;
			head->next = head;
			head->prev = head;
				
		}
		else
		{
			n->next = head;
			n->prev = head->prev;
			head->prev->next = n;
			head->prev = n;
			head = n;
		}
		l++;
		return;
	}
	node<N>* p=head;
	if(pos == -1 or pos>l)
		pos = l;
	for(int i=1; i<pos; i++)
	{
		p = p->next;
	}
	n->next = p->next;
	n->prev = p;
	n->next->prev =n;
	p->next = n; 
	p = NULL;
	l++;
	delete p;
	
}
template <class N>
void CDLL<N> :: display()
{
	if(l == 0)
		return;
	node<N>* p=NULL;
	p=head;
	cout<<"<->";
	do
	{
		cout<<"["<<p->info<<"]<->";
		p=p->next;
		if(p==head)
			break;
	}while(true);
	cout<<endl;
}
template <class N>
void CDLL<N> ::displayalt()
{
	if(l == 0)
		return;
	node<N>* p=new node<N>;
	p=head;
	do
	{
		cout<<"["<<p->info<<"] ";
		if(p==head or p->next==head)
			break;
		p=p->next->next;
	}while(true);
	cout<<endl;
}
template <class N>
void CDLL<N>::del(int pos)
{
	if(pos>=l or pos == -1)
		pos = l-1;
	if(isempty())
		cout<<"List is empty"<<endl;
	else if(head->next==head)
	{
		head->next=NULL;
		head->prev=NULL;
		head=NULL;
		l--;
		return;
	}
	else
	{
		node<N>* p;
		p=head;
		if(pos==0)
		{
			head= head->next;
			head ->prev = p->prev;
			p->prev->next = head;
			p->prev = NULL;
			p->next = NULL;
			delete p;
			l--;
		}
		else 
		{
			for(int i=1; i<pos; i++)
			{
				p = p->next;
			}
			node<N>* t = p->next;
			p->next = t->next;
			t->next->prev = p;
			t->next = NULL;
			t->prev = NULL;
			delete t;
			l--;
		}
	
	}
}

template <class N>
void CDLL<N>::reverse()
{
	if(isempty())
	{
		cout<<"List is empty"<<endl;
	}
	else
	{	
		node<N>* n=head;
		node<N>* p=head->next;
		do{
			n->next = n->prev;
			n->prev=p;
			n = n->prev;
			p = p->next;
		}while(n!=head);
		p = NULL;
		n = NULL;
		delete p;
		delete n;
		head=head->next;
	}
}
template <class N>
int CDLL<N>::sibv(N val)
{
	if(isempty())
	{
		return 0;
	}
	else
	{
		int ind=1;
		node<N>* p;
		p=head;
		do
		{
			if(p->info==val)
			{
				return ind;
			}
			else
			{
				ind++;
			}
			p=p->next;
		}while(p!=head);
		return -1;
	}
}
template <class N>
N CDLL<N>::svbi(int pos)
{
	if(isempty())
	{
		cout<<"List is empty"<<endl;
	//	return NULL;
	}
	else
	{
		N val;
		if(pos==1 or pos==0)
		{
			val=head->info;
			return val;
		}
		else if(pos==-1 or pos>l)
		{
			val=head->prev->info;
			return val;
		}
		else if(pos<=l)
		{
			N val;
			node<N>* p;
			p=head;
			for(int i=1;i<pos;i++)
			{
				p=p->next;
			}
			val=p->info;
			delete p;
			return val;
		}
	}
}
template <class N>
CDLL<N> CDLL<N>:: operator+ (CDLL<N> &L)
{
	CDLL<int>res;
	node<N>*p;
	p=head;
	do
	{
		res.insert(-1,p->info);
		p=p->next;
	}while(p!=NULL and p!=head);
	p=L.headptr();
	do
	{
		res.insert(-1,p->info);
		p=p->next;
	}while(p!=NULL and p!=L.headptr());
	delete p;
	return res; 	
}
