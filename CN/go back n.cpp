#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include <math.h>
struct frame{
	int data;
	int seqno;
};
using namespace std;
class gbn{
	public:
		int t, cur, ws, sq, n, rec;
		frame* p;
		bool flag;
void input()
{
	cout<<"Enter no of sequence bit.: ";
	cin>>sq;
	ws = pow(2,sq)-1;
	cout<<"Window size: "<<ws<<endl;
	cout<<"Enter no of frames: ";
	cin>>n;
	cur = 0;
	t = 0;
	rec = 0;
	cout<<"Enter data: ";
	p = new frame[n];
	for(int i =0; i<n; i++)
	{
		cin>>p[i].data;
		p[i].seqno = i%ws;
	}
}
void sender()
{
	for(int i=0; i<ws and i<n; i++)
	{
		cout<<"Sent frame "<<i<<endl;
		t++;
	}
	while(cur<n)
	{
		rec = receiver(p[cur]);
		if(rec == 1)
		{
			cout<<"\nFrame "<<cur<<" sent sucessfully. \n Window shifting forward! "<<endl;
			if(t<=n)
				cout<<"Sending frame "<<t<<endl<<endl;
			cur++;
			t++;
			
		}
		if(rec == 0)
		{
			cout<<"Frame "<<cur<<" lost!"<<endl<<endl;
			for(int i=cur; i<t and i<n; i++)
			{
				cout<<"Frame "<<i<<" resent!"<<endl;
			}
			cout<<endl<<endl;
		}
		
	}
	
}
int receiver(frame f)
{
	getch();
	int r = rand()%2;
	if(r == 1)
	{
		cout<<"\n--------------------------\nReceived frame "<<f.seqno<<" with data "<<f.data<<"\n----------------------------\n";
	}
	return r;	
}	
};
int main()
{
	gbn c;
	c.input();
	c.sender();
	getch();
	return 0;
}
