#include <iostream>
#include <conio.h>
using namespace std;
class meh{
//make an array of memory chunks
//make an array for processes
	int n,m;
	int *p, *l;
	public:
		meh(int n, int m);
		void first();
		void best();
		void worst();
		
};
meh::meh(int a, int b)
{
	n = a;
	m = b;
	p = new int[n];
	l = new int[m];
	cout<<"Enter processes: ";
	for(int i=0; i<n;i++)
	{
		cin>>p[i];
	}
	cout<<"Enter Memory chunks: ";
	for(int i=0; i<m;i++)
	{
		cin>>l[i];
	}
	cout<<"Processes: ";
	for(int i=0; i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	cout<<"Memory chunks: ";
	for(int i=0; i<m;i++)
	{
		cout<<l[i]<<" ";
	}
	cout<<endl;
}
void meh::best()
{
// Make a copy of memory chunk
	int *t = new int[m];
	for(int i=0; i<m; i++)
		t[i] = l[i];
//	loop over processes:
	int min;
	for(int i=0; i<n; i++)
	{
//		min=-1
		min = -1;
//		loop over memory:					
		for(int j=0; j<m; j++)
		{
//			if(min == -1 and memory>process)
			if(min == -1 and t[j]>=p[i])
			{
//				min = index of memory
				min = j;
			}
//			elif(momory[min]>memory[current])
			else if(t[min]>t[j] and t[j]>=p[i])
			{
//				min = current
				min = j;
			}	
		}
//		if(min == -1)
		if(min == -1)
		{
//			priint could not assign
			cout<<"Could not assign to process no. "<<i+1<<endl;
		}
		else
		{
//			memory[min]-=process
			t[min] -=p[i];
//			print process i assigned memory min	
			cout<<"Process no. "<<i+1<<" was assigned memory chunk no. "<<min+1<<endl;
			cout<<"Memory size assigned was of size "<<l[min]<<" For a requirement of "<<p[i]<<endl;
		}
	}
}
void meh::worst()
{
// Make a copy of memory chunk
	int *t = new int[m];
	for(int i=0; i<m; i++)
		t[i] = l[i];
//	loop over processes
	int max = 0;
	for(int i=0; i<n; i++)
	{
//		max = 0
		max = -1;
//		loop over memory:
		for(int j=0; j<m; j++)
		{
			if(max == -1 and t[j]>=p[i])
				max = j;			
			else if(max != -1 and t[j]>t[max])
				max = j;
		}
		if(max == -1)
		{
			cout<<"Could not assign to process no. "<<i+1<<endl;
		}
		else
		{
			t[max] -= p[i];
			cout<<"Process no. "<<i+1<<" was assigned memory chunk no. "<<max+1<<endl;
			cout<<"Memory size assigned was of size "<<l[max]<<" For a requirement of "<<p[i]<<endl;
		}
		
			
	}
}

void meh::first()
{
	int *t = new int[m];
	for(int i=0; i<m; i++)
		t[i] = l[i];
	bool flag = false;
//	loop over processes:
	for(int i =0; i<n; i++)
	{
		flag = false;
		
//		loop over memory:
		for(int j =0; j<m; j++)
		{		
//			if first chunk>=process gets assigned
			if(t[j]>=p[i])
			{
//				decrement memory chunk and print memory number
				t[j]-=p[i];
				flag = true;
				cout<<"Assigned memory chunk size: "<<p[i]<<" to process "<<i+1<<endl;
				cout<<"Original size of chunk was "<<l[j]<<endl;
				break;
			}
			
		}
		if(!flag)
		{
//			print process could not be assigned
			cout<<"Could not assign a block to process: \n"<<i+1<<endl;
				
		}
	}
				
}
	
int main()
{
	int m,a;
	cout<<"Enter no. of processes and memory no. :";
	cin>>a;
	cin>>m;
	meh n(a,m);
	while(true)
	{
		cout<<"Menu\n 1. first\n 2. best \n 3. worst\n";
		switch(getch()-48)
		{
			case 1:
				n.first();
				break;
			case 2:
				n.best();
				break;
			case 3:
				n.worst();
				break;
			default:
				cout<<"Choose correct option\n";
		}
	}
	getch();
	return 0;
}
	
//
//best fit():
//	loop over processes:
//		min=-1
//		loop over memory:					
//			if(min == -1 and memory>process)
//				min = index of memory
//			elif(momory[min]>memory[current])
//				min = current
//		if(min == -1)
//			priint could not assign
//		else
//			memory[min]-=process
//			print process i assigned memory min
//			
//worst fit():
//	loop over processes
//		max = 0
//		loop over memory:
//			if(memory[current]>memory[max])
//				max= current
//		if(max == 0 and process<memory[max])
//			cout<<"could not assign\n";
//		else
//		{
//			cout<<assigned memeory chunk max to process i;
//		}
