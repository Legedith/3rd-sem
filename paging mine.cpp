#include <iostream>
#include <conio.h>
using namespace std;
struct process{
	int *fr;
	int size;
	int fra;
	int start;
};
class page{
	int *frame;
	process* prs;
	int n, m, p, nop,full;
	public:
		page();
		void deallocate();
		void display();
};
page::page()
{
	cout<<"Enter memory size: ";
	cin>>m;
	cout<<"Enter page size: ";
	cin>>p;
	n = m/p;
	if(m%p!=0)
		n++;
	full = 0;
	frame = new int[n];
	for(int i=0; i<n; i++)
	{
		frame[i] = 0;
	}
	cout<<"Enter no of processes: ";
	cin>>nop;
	prs = new process[nop];
	for(int i=0; i<nop;i++)
	{
		cout<<"Enter size of process "<<i<<" : ";
		cin>>prs[i].size;
		prs[i].fra = prs[i].size/p;
		if(prs[i].size%p!=0)
			prs[i].fra++;
		prs[i].fr = new int[prs[i].fra];
		if(n-full >= prs[i].fra)
		{
			cout<<"Allocating these frames to process "<<i<<" : ";
			for(int j=0; j<prs[i].fra; j++)
			{
				while(frame[full+j]!=0 and full<n)
					full++;
				cout<<full+j<<" ";
				frame[full+j] = 1;
			}
			prs[i].start = full;
			full+=prs[i].fra;
//			cout<<"\nFrames full till: "<<full<<endl;
		}
		else
		{
			cout<<"\nNot enpough frames, could not allocate\n\n ";
				prs[i].start = 0;
				prs[i].fra = 0;
		}
		cout<<endl;
	}
}
void page::deallocate()
{
	int num;
	cout<<"Enter process no: ";
	cin>>num;
	for(int i=prs[num].start; i<prs[num].start+prs[num].fra; i++)
	{
		cout<<"Deallocated frame "<<i<<endl;
		frame[i] = 0;
	}
	cout<<"\n\n";
	prs[num].start = 0;
	prs[num].fra = 0;
}
void page::display()
{
	int num;
	cout<<"Enter process no: ";
	cin>>num;
	cout<<"Page table: ";
	for(int i=prs[num].start; i<prs[num].start+prs[num].fra; i++)
	{
		cout<<i<<" ";
	}
	cout<<"\n\n";
}
int main()
{
	page p;
	while(true)
	{
		cout<<"\n\nChoose:\n1.Display\n2.Deallocate\n\n";
		switch(getch()-48)
		{
			case 1:
				p.display();
				break;
			case 2:
				p.deallocate();
				break;
		}
	}
	getch();
	return 0;
}
