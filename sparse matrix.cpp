#include <iostream>
#include <conio.h>
using namespace std;
class matrix{
	int* p;
	int n,m;
	public:
		void diagonal();
		void lower();
		void upper();
		void symmetric();
};
void matrix::diagonal()
{
	cout<<"Enter size of matrix: ";
	cin>>n;
	p = new int[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter element "<<i<<" , "<<i<<" :";
		cin>>p[i]; 
	}
	cout<<"The matrix formed is : \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
			{
				cout<<p[i]<<"   ";
			}
			else
			{
				cout<<"0   ";
			}
		}
		cout<<endl;
	}
}
void matrix::lower()
{
	cout<<"Enter size of matrix: ";
	cin>>n;
	m = (n*(n+1))/2;
	p = new int[m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j>i)
				continue;
			cout<<"Enter element "<<i<<" , "<<j<<" : ";
			cin>>p[((i*(i+1))/2) + j];
		}
	}
	cout<<"The matrix formed is : \n";
//	for(int i=0; i<m; i++)
//	{
//		cout<<p[i]<<" ";
//	}
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j>i)
			{
				cout<<"0   ";
			}
			else
			{
				cout<<p[((i*(i+1))/2) + j]<<"   ";
			}
		}
		cout<<endl;
	}
}
void matrix::upper()
{
	cout<<"Enter size of matrix: ";
	cin>>n;
	m = (n*(n+1))/2;
	p = new int[m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>j)
				continue;
			cout<<"Enter element "<<i<<" , "<<j<<" : ";
			cin>>p[((j*(j+1))/2) + i];
		}
	}
	cout<<"The matrix formed is : \n";
//	for(int i=0; i<m; i++)
//	{
//		cout<<p[i]<<" ";
//	}
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>j)
			{
				cout<<"0   ";
			}
			else
			{
				cout<<p[((j*(j+1))/2) + i]<<"   ";
			}
		}
		cout<<endl;
	}
}
void matrix::symmetric()
{
	cout<<"Enter size of matrix: ";
	cin>>n;
	m = (n*(n+1))/2;
	p = new int[m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>j)
				continue;
			cout<<"Enter element "<<i<<" , "<<j<<" : ";
			cin>>p[((j*(j+1))/2) + i];
		}
	}
	cout<<"The matrix formed is : \n";
//	for(int i=0; i<m; i++)
//	{
//		cout<<p[i]<<" ";
//	}
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>j)
			{
				cout<<p[((i*(i+1))/2) + j]<<"   ";
			}
			else
			{
				cout<<p[((j*(j+1))/2) + i]<<"   ";
			}
		}
		cout<<endl;
	}
}
int main()
{
	matrix m;
	cout<<"Menu: \n1. Diagonal\n2. Lower\n3. Upper\n4. Symmetric\n"
	m.symmetric();
	getch();
	return 0;
}
