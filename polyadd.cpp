#include <iostream>
#include <conio.h>
#include "sll.h"
using namespace std;
int main()
{
	sll<int> a,b;
	int n;
	int d;
	while(true)
	{	cout<<"Enter degree: ";
		cin>>d;
		cout<<"\n\nPoly 1:\n";
		for(int i=0;i<d;i++)
		{
			cout<<"X^"<<i<<": ";
			cin>>n;	
			a.insertEnd(n);
		}
		cout<<"\nPoly 2:\n";
		for(int i=0;i<d;i++)
		{
			cout<<"X^"<<i<<": ";
			cin>>n;	
			b.insertEnd(n);
		}
		cout<<"\nResult: ";
		for(int i=0;i<d;i++)
		{
			cout<<a.searchInd(-1)+b.searchInd(-1);
			cout<<"X^"<<d-1-i;
			if(i!=d-1)
				cout<<" + ";
			a.delEnd();
			b.delEnd();
		}	
		cout<<endl<<endl;
	}
	getch();
	return 0;
}
