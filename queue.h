#include<iostream>
#include<conio.h>
using namespace std;
template <class type>
class queue
{
	private:
		int front,rear;
		type* Q;
		int l;
	public:
		int in();
		int out();
		queue();
		queue(int length);
		~queue();
		void setSize(int n);
		bool isfull();
		bool isempty();
		int dequeue();
		void enqueue(type val);
		
};
template <class type>
int queue<type>::in()
{
	return front;
}
template <class type>
int queue<type>::out()
{
	return rear;
}

template <class type>
queue<type>::~queue()
{
	cout<<"Destroying queue!"<<endl;
}

template <class type>
queue<type>::queue()
{
	front=-1;
	rear=-1;
	l=1;
	Q = new type[l];
}

template <class type>
void queue<type>::setSize(int n)
{
	front=-1;
	rear=-1;
	l=n;
	Q = new type[l];
}

template <class type>
queue<type>::queue(int length)
{
	front=-1;
	rear=-1;
	l=length;
	Q = new type[l];
}

template <class type>
bool queue<type>::isfull()
{
	if((rear+1)%l==front)
		return true;
	else
		return false;
}

template <class type>
bool queue<type>::isempty()
{
	if (front==-1 and rear==-1)
		return true;
	else
		return false;
}

template <class type>
void queue<type>::enqueue(type val)
{
	if(front==-1 and rear==-1)
	{
		front=rear=0;
		Q[rear]=val;
	}
	else
	{
		rear=(rear+1)%l;
		Q[rear]=val;
	}
}

template <class type>
int queue<type>::dequeue()
{
	
	type val=Q[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=(front+1)%l;
	}
	return val;
}
