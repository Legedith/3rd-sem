#include <iostream>
#include <conio.h>
#include<stdio.h>
using namespace std;

class process{
	public:
	int n;
	int **p;
	process();
	void input();
	void display();
	void Sort(int j);
	void fcfs();
};
process::process()
{
	cout<<"Enter no. of processes: ";
	cin>>n;
	p = new int*[n];
	for(int i=0; i<n; i++)
		p[i] = new int[3];
		
}
void process::input()
{
	for(int i=0; i<n; i++)
	{
		cout<<"Enter arrival, burst and priorty: ";
		for(int j=0; j<3; j++)
		{
			cin>>p[i][j];
		}
	}
}
void process::display()
{
	for(int i=0; i<n; i++)
	{
		cout<<"Process "<<i<<": ";
		for(int j=0; j<3; j++)
		{
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}
void fcfs()
{
	
}
void process::Sort(int a)
{
	bool flag = false;
	for(int i=0; i<n; i++,flag = false)
	{
		for(int j=0; j<n-i;j++)
		{
			if(p[j+1][a]<p[j][a])
			{
				flag = true;
				Swap(p[j],p[j+1]);
			}
		}
	}
}


int main()
{
	process ar;
	ar.input();
	ar.display();
	getch();
	return 0;
}
