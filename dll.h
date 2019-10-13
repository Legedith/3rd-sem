#include <iostream>
#include <conio.h>
using namespace std;

template <class type>
struct node{
	type info;
	node* next;
	node* prev;

};

template <class type>
class dll{
	public:
		int l;
		node<type>* head =NULL;
		dll();
		~dll();
		dll(const dll<type> &list);
		void insertIndex(type info, int n=0);		
		void insertStart(type info);
		void insertEnd(type info);
		void delIndex(int n=0);		
		void delStart();
		void delEnd();
		void reverse();
		void display();
		void displayalt();
		int search(type n);
		type searchInd(int n);
		void rev();
		dll concat(dll const &list);
		dll operator + (dll const &list);
		int length();
		//search overload conhcat alternate 
		
		
};


template <class type>
dll<type>::dll()
{
	head = NULL;
	l =0 ;
}

template <class type>
dll<type>::~dll()
{
	cout<<"!!! Destroying the List !!!\n";	
}
template <class type>
dll<type> dll<type>::concat(const dll<type> &list)
{
	dll<type> res = *this;
	return res+list;
}
template <class type>
dll<type>::dll(const dll<type> &list)
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
void dll<type>::delIndex(int n)
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
	if(n>=l)
		n = l-1;
	for(int i = 0; i<n-1; i++)
		temp = temp->next;
	node<type>* temp2 = temp->next;
	temp->next = temp->next->next;
	if (n!=l-1)
		temp2->next->prev = temp;
	temp2->next = NULL;
	temp2->prev = NULL;
	l--;
	delete temp2;
	temp = NULL;
	delete temp;
}

template <class type>
void dll<type>::insertIndex(type info, int n)
{
	node<type>* p = new node<type>;
	p->info = info;
	p->next = NULL;
	p->prev = NULL; 
	if(n>length() or n<0)
		n = length();
	if(n==0)
	{
		p->next = head;
		if(l != 0)
			head->prev = p;
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
	if(n != l)
		p->next->prev = p;
	temp->next = p;
	p->prev = temp;
	l++;
	temp = NULL;
	delete temp;
}

template <class type>
void dll<type>::display()
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
void dll<type>::displayalt()
{
	node<type>* temp =head;
	while(temp != NULL)
	{
		cout<<"["<<temp->info<<"] ";
		if(temp->next==NULL)
			break;
		temp = temp->next->next;
	}
	cout<<endl;
}

template <class type>
int dll<type>::length()
{
	return l;
}

template <class type>
void dll<type>::delStart()
{
	delIndex();
}

template <class type>
dll<type> dll<type>::operator + (dll const &list)
{
	dll<type> res = *this;
	node<type>* temp = list.head;
	while(temp != NULL)
	{
		res.insertEnd(temp->info);
		temp = temp->next;
	}
	return res;
}

template <class type>
void dll<type>::delEnd()
{
	delIndex(l);
}
template <class type>
int dll<type>::search(type n)
{
	if(l!=0)
	{
		int n=0;
		node<type>* temp = head;
		while(temp != NULL)
		{
			if(temp->info == n)
				return n;
			temp= temp->next;
			n++;
		}
	}
	return -1;
}

template <class type>
type dll<type>::searchInd(int n)
{
	if(l!=0 and n<l)
	{
		int i = 0;
		node<type>* temp = head;
		while(temp != NULL)
		{
			if(i == n)
				return temp->info;
			temp= temp->next;
			i++;
		}
	}
	return -1;
}

template <class type>
void dll<type>::insertStart(type info)
{
	insertIndex(info);
}

template <class type>
void dll<type>::insertEnd(type info)
{
	insertIndex(info , l);
}
template <class type>
void dll<type>::rev()
{
	if(l==0)
		return;
	node<type>* p = head->next;
	for(int i=0; i<l;i++)
	{
		head->next = head->prev;
		head->prev = p;
		if(i!=l-1)
		{
			head = head->prev;
			p = p->next;
		}
	}
	delete p;
}
