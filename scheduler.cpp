#include <iostream>
#include <conio.h>
#include<stdio.h>
using namespace std;
struct process
{
	int arrival;
	int burst;
	int priority;
	int wait;
	int complete;
	int turn_around;
}
class schedule{
	private:
		int n;
		process* p;
	public:
		schedule();
		void input();
		void fcfs();
		void sjf();
		void srjf();
		void rr();
		void display();
		void sort_by_arr();
		void sort_by_brst();
		void sort_by_pri();
	
	
};
schedule::schedule()
{
	n=0;
	p = new process[0];
}
void schedule::input()
{
	cout<<"Enter no. of processes: ";
	cin>>n;
	p = new process[n];
	cout<<"Enter 1 if you wanna enter priority: ";
	int a; 
	cin>>a;
	cout<<"Enter arrival of all processes: ";
	for(int i=0; i<n; i++)
	{
		cin>>p[i].arrival;
	}
	cout<<"Enter burst of all processes: ";
	for(int i=0; i<n; i++)
	{
		cin>>p[i].burst;
	}	
	for(int i=0; i<n; i++)
	{
		p[i].wait = 0;
		p[i].complete = 0;
		p[i].priority = 0;
		p[i].turn_around = 0;
	}
	if(a == 1)
	{
		cout<<"Enter burst of all processes: ";
		for(int i=0; i<n; i++)
		{
			cin>>p[i].priority;
		}	
	}
	
}
void fcfs()
{
	sort_by_arr();
	display();	
}
void sjf()
{
	sort_by_brst();
	sort_by_arr();
	display();
}
void srjf();
void rr();
void display();
void sort_by_arr();
void sort_by_brst();
void sort_by_pri();
int main()
{
	
	getch();
	return 0;
}
