#include <iostream>
#include <conio.h>
using namespace std;

template <class type>
struct node{
	type info;
	node* next;

};

template <class type>
class sll{
	public:
		int l;
		node<type>* head =NULL;
		sll();
		~sll();
		sll(const sll<type> &list);
		void insertIndex(type info, int n=0);		
		void insertStart(type info);
		void insertEnd(type info);
		void delIndex(int n=0);		
		void delStart();
		void delEnd();
		void reverse();
		void display();
		void displayalt();
		bool search(type n);
		void rev();
		sll concat(sll const &list);
		sll operator + (sll const &list);
		int length();
		//search overload conhcat alternate 
		
		
};


template <class type>
sll<type>::sll()
{
	head = NULL;
	l =0 ;
}

template <class type>
sll<type>::~sll()
{
	cout<<"!!! Destroying the List !!!\n";	
}
template <class type>
sll<type> sll<type>::concat(const sll<type> &list)
{
	sll<type> res = *this;
	return res+list;
}
template <class type>
sll<type>::sll(const sll<type> &list)
{
	l = 0;
	head = NULL;
	if (list.l == 0)
		return;
	node<type>* temp = list.head;
	while(temp!=NULL)
	{
		insertEnd(temp->info);
		temp = temp->next;
		
	}
}

template <class type>
void sll<type>::delIndex(int n)
{
	node<type>* temp =head;
	if(n==0)
	{
		head = head->next;
		temp->next = NULL;
		delete temp;
		l--;
		return;
	}
	if(n==l)
		n--;
	for(int i = 0; i<n-1; i++)
		temp = temp->next;
	node<type>* temp2 = temp->next;
	temp->next = temp->next->next;
	temp2->next = NULL;
	l--;
	delete temp2;
	temp = NULL;
	delete temp;
}

template <class type>
void sll<type>::insertIndex(type info, int n)
{
	node<type>* p = new node<type>;
	p->info = info;
	p->next = NULL; 
	if(n>length())
		n = length();
	if(n==0)
	{
		p->next = head;
		head = p;
		p = NULL;
		delete p;
		l++;
		return;	
	}
	node<type>* temp = head;
	for(int i = 0; i<n-1; i++)
		temp = temp->next;	
	p->next = temp->next;
	temp->next = p;
	l++;
	temp = NULL;
	delete temp;
}

template <class type>
void sll<type>::display()
{
	node<type>* temp =head;
	while(temp != NULL)
	{
		cout<<"["<<temp->info<<"] ";
		temp = temp->next;
	}
	cout<<endl;
}

template <class type>
void sll<type>::displayalt()
{
	node<type>* temp =head;
	while(temp != NULL)
	{
		cout<<"["<<temp->info<<"] ";
		if(temp->next=NULL)
			break;
		temp = temp->next->next;
	}
	cout<<endl;
}

template <class type>
int sll<type>::length()
{
	return l;
}

template <class type>
void sll<type>::delStart()
{
	delIndex();
}

template <class type>
sll<type> sll<type>::operator + (sll const &list)
{
	sll<type> res = *this;
	node<type>* temp = list.head;
	while(temp != NULL)
	{
		res.insertEnd(temp->info);
		temp = temp->next;
	}
	return res;
}

template <class type>
void sll<type>::delEnd()
{
	delIndex(l);
}
template <class type>
bool sll<type>::search(type n)
{
	node<type>* temp = head;
	while(temp != NULL)
	{
		if(temp->info == n)
			return true;
		temp= temp->next;
	}
	return false;
}
template <class type>
void sll<type>::insertStart(type info)
{
	insertIndex(info);
}

template <class type>
void sll<type>::insertEnd(type info)
{
	insertIndex(info , l);
}
template <class type>
void sll<type>::rev()
{
	if(l==0)
		return;
	node<type>* t1 = NULL;
	node<type>* t2 = head;
	node<type>* t3 = head->next;
	while(t3 != NULL)
	{
		t2->next = t1;
		t1 = t2;
		t2 = t3;
		t3 = t3->next;
	}
	t2->next = t1;
	t1 = t2;
	t2 = t3;
	head = t1;
	/* better one
	else
	{
		node<N>* t;
		node<N>* p;
		t=head;
		p=head->next;
		while(head->next!=NULL)
		{
			head->next=p->next;
			p->next=t;
			t=p;
			p=head->next;
		}
		head=t;
	}
	*/
}
