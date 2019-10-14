#include<iostream>
#include<conio.h>
#include "sll.h"
using namespace std;
int main()
{
	sll<int> a;
	while(true)
	{
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Peek\n";
		cout<<"4. Exit\n";
		switch(getch()-48)
		{	
			case 1:
				{
					int v;
					cout<<"Enter value: ";
					cin>>v;
					a.insertStart(v);
					cout<<"Pushed "<<v<<endl<<endl;	
					break;
				}
			case 2:
				{
					if(!a.isEmpty())
					{
						int b = a.searchInd(0);
						a.delStart();
						cout<<"Popped "<<b<<endl;	
					}
					else{
						cout<<"Empty\n";
					}
					
					break;
				}
			case 3:
				{
					if(!a.isEmpty())
					{
						int b = a.searchInd(0);
						cout<<"Peek "<<b<<endl;	
					}
					else{
						cout<<"Empty\n";
					}	
					break;
				}
			case 4:
				return 0;
			
		}
	}
	getch();
	return 0;
}
