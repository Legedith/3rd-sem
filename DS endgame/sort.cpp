#include <iostream>
#include <conio.h>
using namespace std;
class sort{
	int *p;
	int n;
	public:
		sort();
		void bubble();
		void insert();
		void selection();
		void merge();
		void quick();
		void display();
};
sort::sort()
{
	cout<<"Enter no. of elements: ";
	cin>>n;
	p = new int[n];
	cout<<"Enter elements: ";
	for(int i=0; i<n; i++)
		cin>>p[i];
}
void sort::bubble()
{
	int t;
	bool flag;
	for(int i=0; i<n; i++, flag = false)
	{
		for(int j=0; j<n-1-i; j++ )
		{
			if(p[j]>p[j+1])
			{
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
				flag = true;
			}
		}
		if(flag == false)
		{
			break;
		}
	}
	display();
}
void sort::insert()
{
	int j,temp;
	for(int i=1; i<n; i++)
	{
		j = i-1;
		temp = p[i];
		while(p[j]>temp and j>=0)
		{
			p[j+1] = p[j];
			j--;
			display();
		}
		p[j+1] = temp;
	}
}
void sort::selection()
{
	int min,t;
	for(int i=0; i<n-1; i++)
	{
		min = i;
		for(int j=i; j<n; j++)
		{
			if(p[min]>p[j])
			{
				min = j;
			}
		}
		t = p[i];
		p[i] = p[min];
		p[min] = t;
	}
	display();
}
void sort::quick()
{
	
}
void sort::display()
{
	for(int i=0; i<n; i++)
	{
		cout<<p[i]<<"	";
	}
	cout<<endl;
}
int main()
{
	sort a;
	a.insert();
	getch();
	return 0;
}
