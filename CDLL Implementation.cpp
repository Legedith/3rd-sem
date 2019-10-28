#include<iostream>
#include<conio.h>
#include"CDLL.h"
using namespace std;
template <class N>
void menu(CDLL<N> &L)
{
	int n;
	char ch;
	N x;
	cout<<"Select CDLL operation"<<endl;
	cout<<"1.Insert"<<endl;
	cout<<"2.Reverse CDLL"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.Delete"<<endl;
	cout<<"5.Search value by index"<<endl;
	cout<<"6.Search index by value"<<endl;
	cout<<"7.Display alternate elements"<<endl;
	cout<<"8.Display options"<<endl;
	do 
	{
		switch (getch()-48)
		{
			case 1:
			{
				cout<<"0=Beginning -1=End Else any position: ";
				cin>>n;
				cout<<"Enter data: ";
				cin>>x;
				L.insert(n,x);
				L.display();
				break;
			}
			case 2:
			{
				L.reverse();
				L.display();
				break;
			}
			case 3:
			{
				L.display();
				break;
			}
			case 4:
			{
				cout<<"0=Beginning -1=End Else any position";
				cin>>n;
				L.del(n);
				L.display();
				break;
			}
			case 5:
			{
				cout<<"Enter index: ";
				cin>>n;
				if(n>L.length())
				{
					cout<<"Index not found"<<endl;
				}
				else
				{
					cout<<L.svbi(n)<<endl;
				}
				break;
			}
			case 6:
			{
				cout<<"Enter value:";
				cin>>n;
				n=L.sibv(n);
				if(n>=1)
				{
					cout<<"Value found at node: "<<n<<endl;
				}
				else if(n==0)
				{
					cout<<"List is empty"<<endl;
				}
				else if(n==-1)
				{
					cout<<"Value not found"<<endl;
				}
				break;
			}
			case 7:
			{
				L.displayalt();
				break;
			}
			case 8:
			{
				cout<<"Select CDLL operation"<<endl;
				cout<<"1.Insert"<<endl;
				cout<<"2.Reverse CDLL"<<endl;
				cout<<"3.Display"<<endl;
				cout<<"4.Delete"<<endl;
				cout<<"5.Search value by index"<<endl;
				cout<<"6.Search index by value"<<endl;
				cout<<"7.Display alternate elements"<<endl;
				cout<<"8.Display options"<<endl;
				break;
			}
			default:
			{
				cout<<"Invalid option"<<endl;
			}
		}
		cout<<"Enter y to continue else end \r";
		ch=(char)getch();
		cout<<"                                               \r"<<"\b";
	}
	while (ch=='y' or ch=='Y');
}
int main()
{
	CDLL<int> L[3];
	do 
	{
		cout<<"1. List 1"<<endl;
		cout<<"2. List 2"<<endl;
		cout<<"3. Concatenate both lists"<<endl;
		cout<<"4. Exit"<<endl;
		switch (getch()-48)
		{
			case 1:
			{
				menu(L[0]);
				break;
			}
			case 2:
			{
				menu(L[1]);
				break;
			}
			case 3:
			{
				L[2]=(L[0]+L[1]);
				L[2].display();
				break;
			}
		
			case 4:
			{
				return 0;
			}
		}
	}
	while(true);
	getch();
}
