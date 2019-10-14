#include<iostream>
#include<conio.h>
#include "queue.h"
using namespace std;
int main()
{
	queue<int> a;
	int n;
	cout<<"Enter size of Queue: ";
	cin>>n;
	a.setSize(n);
	while(true)
	{
		cout<<"1. En-queue\n";
		cout<<"2. De-queue\n";
		cout<<"3. Reset\n";
		cout<<"4. Exit\n";
		switch(getch()-48)
		{	
			case 1:
				{
					if(!a.isfull())
					{
						int v;
						cout<<"Enter value: ";
						cin>>v;
						a.enqueue(v);
						cout<<"Queued "<<v<<endl<<endl;	
					}
					else{
						cout<<"\n\nQueue full\n\n";
					}
					break;
				}
			case 2:
				{
					if(!a.isempty())
					{
						int b = a.dequeue();
						cout<<"\n\nDequeued "<<b<<endl<<endl;
					}
					else{
						cout<<"\n\nQueue empty\n\n";
					}
					break;
				}
			case 3:
				{
					int v;
					cout<<"Enter size: ";
					cin>>v;
					a.setSize(v);
					break;
				}
			case 4:
				return 0;
			
		}
	}
	getch();
	return 0;
}
