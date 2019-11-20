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
		void mgsort(int l, int h);
		void quick();
		void merge(int l, int m, int r);
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
void sort::mgsort(int l, int h)
{
	if(l<h)
	{
		int mid = (l+h)/2;
		mgsort(l,mid);
		mgsort(mid+1,h);
		merge(l,mid,h);
	}
}
void sort::merge(int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int* a = new int[m-l+1];
	int* b = new int[r-m];
	for(int i=0; i<n1; i++ )
	{
		a[i] = p[l+i];
	}
	for(int i=0; i<n2; i++ )
	{
		b[i] = p[m+1+i];
	}	
	int i,j,k;
	i = j = k = 0;
	while(i<n1 and j<n2)
	{
		if(a[i]<b[j])
		{
				p[l+k] = a[i];
				i++;
		}
		else
		{
			p[l+k] = b[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		p[l+k] = a[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		p[l+k] = b[j];
		j++;
		k++;
	}
	display();
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
	a.mgsort(0,7);
	getch();
	return 0;
}
