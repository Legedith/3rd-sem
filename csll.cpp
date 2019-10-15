#include <iostream>
#include <conio.h>
using namespace std;

template <class type>
struct node{
	type info;
	node* next;
};

template <class type>
class csll{
	public:
		int l;
		node<type>* tail =NULL;
		csll();
		~csll();
		csll(const csll<type> &list);
		void insertIndex(type info, int n=l);		
		void insertStart(type info);
		void insertEnd(type info);
		void delIndex(int n=l);		
		void delStart();
		void delEnd();
		void reverse();
		bool isEmpty();
		void display();
		void displayalt();
		int search(type n);
		type searchInd(int n);
		void rev();
		csll concat(csll const &list);
		csll operator + (csll const &list);
		int length();
		//search overload conhcat alternate 
		
		
};


template <class type>
csll<type>::csll()
{
	tail = NULL;
	l =0 ;
}

template <class type>
csll<type>::~csll()
{
	cout<<"!!! Destroying the List !!!\n";	
}
template <class type>
csll<type> csll<type>::concat(const csll<type> &list)
{
	csll<type> res = *this;
	return res+list;
}
template <class type>
csll<type>::csll(const csll<type> &list)
{
	l = 0;
	tail = NULL;
	if (list.l == 0)
		return;
	node<type>* temp = list.tail;
	do
	{
		insert(temp->info);
		temp = temp->next;
		
	}while(temp!=list.tail);
}

template <class type>
bool csll<type>::isEmpty()
{
	if(l==0)
		return true;
	return false;
}

template <class type>
void csll<type>::delIndex(int n)
{

}

template <class type>
void csll<type>::insertIndex(type info, int n)
{
	
}

template <class type>
void csll<type>::display()
{

}

template <class type>
void csll<type>::displayalt()
{

}

template <class type>
int csll<type>::length()
{
	return l;
}

template <class type>
void csll<type>::delStart()
{
	delIndex();
}

template <class type>
csll<type> csll<type>::operator + (csll const &list)
{
	
}

template <class type>
void csll<type>::delEnd()
{
	delIndex(l);
}
template <class type>
int csll<type>::search(type n)
{

}

template <class type>
type csll<type>::searchInd(int n)
{
	
}


template <class type>
void csll<type>::insertStart(type info)
{
	insertIndex(info);
}

template <class type>
void csll<type>::insertEnd(type info)
{
	insertIndex(info , l);
}
template <class type>
void csll<type>::rev()
{
	if(l==0)
		return;
	node<type>* t1 = NULL;
	node<type>* t2 = tail;
	node<type>* t3 = tail->next;
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
	tail = t1;
	/* better one
	else
	{
		node<N>* t;
		node<N>* p;
		t=tail;
		p=tail->next;
		while(tail->next!=NULL)
		{
			tail->next=p->next;
			p->next=t;
			t=p;
			p=tail->next;
		}
		tail=t;
	}
	*/
}
int main()
{

	csll<int> b;
	b.insertIndex(1);
	getch();b.display();
	b.insertIndex(2);
	getch();b.display();
	b.insertIndex(3,1);
	getch();b.display();
	b.insertIndex(7,2);
getch();b.display();
	b.insertIndex(8,4);
	getch();b.display();
	b.insertStart(9);
	getch();b.display();
	b.insertEnd(9);
	b.display();
	cout<<endl;
	getch();
//	cout<<"Deleting start\n";
//	b.delStart();
//	b.delEnd();
//	b.display();
//	cout<<"\nlength: ";
//	cout<<b.l<<endl;
//	b.insertIndex(4,9);
//	b.display();
//	b.delIndex();
//	cout<<endl;
//	cout<<"Deleting start\n";
//	b.display();
//	cout<<"\nlength: ";
//	cout<<b.l<<endl;
//	b.delIndex(3);
//	cout<<endl;
//	b.display();
    csll<int> a = b;
    cout<<a.length();
    cout<<"here";
    getch();
    b.delStart();
    cout<<endl;
    a.display();
    cout<<endl;
	b.display();
getch();
	csll<int> c = a+b;
	cout<<endl;
	csll<int> d = a.concat(b);
	c.display();
	cout<<endl;
	d.display();
	cout<<endl;
	cout<<d.search(8)<<" "<<d.search(6)<<" "<<d.search(3)<<" "<<endl;
	d.rev();
	cout<<endl;
	d.display();
	getch();
		getch();
	return 0;
}

