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
	if(pos == 0)
	{
		if(head == NULL)
		{
			head = n;	
		}
		else
		{
			n->next = head;
			n->prev = head->prev;
			head->prev = n;
		}
		return;
	}
	node<N>* p=head;
	pos = pos%l;
	for(int i=0; i<pos; i++)
	{
		p = p->next;
	}
	n->next = p->next;
	n->prev = p;
	n->next->prev =n;
	p->next = n; 
	p = NULL;
	delete p;
	
}
template <class N>
void CDLL<N> :: display()
{
	node<N>* p=NULL;
	p=head;
	int c=1;
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
	if(isempty())
		cout<<"List is empty"<<endl;
	else if(head->next==head)
		{
			head->next=NULL;
			head->prev=NULL;
			head=NULL;
			return;
		}
	else
	{
		if(pos==1 or pos==0)
		{
			node<N>* p;
			p=head;
			head->next->prev=head->prev;
			head=head->next;
			p->prev->next=head->next;
			head->prev=NULL;
			p->next=NULL;
			p->prev=NULL;
			p=NULL;
			delete p;
		}
		else if(pos==-1)
		{
			node<N>* p=new node<int>;
			node<N>* t=new node<int>;
			p=head->prev;
			p->next=NULL;
			p->prev->next=head;
			head->prev=p->prev;
			p->prev=NULL;
			p=NULL;
			delete p;
		}
		else
		{
			node<N>* p=new node<N>;
			node<N>* t=new node<N>;
			p=head;
			for(int i=1;i<pos and p->next!=NULL;i++)
			{
				t=p;
				p=p->next;
			}
			p->next->prev=t;
			t->next=p->next;
			p->next=NULL;
			p->prev=NULL;
			p=t=NULL;
			delete p;
			delete t;
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
		node<N>* p=NULL;
		node<N>* t=NULL;
		p=head;
		while(true)
		{
			t=p->next;
			p->next=p->prev;
			p->prev=t;
			p=p->prev;
			if(p==head)
			{
				break;
			}
		}
		head=head->prev;
	p=NULL;
	delete p;
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
