#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class gbn
{
public:
int flag,t,sq,ws,ctr,n;
gbn()
{
	flag=0;
	t=1;
	ctr=1;
	}	
void input()
{
	cout<<"\n Enter the number of bits in sequence number"<<endl;
	cin>>sq;
	ws=pow(2,sq)-1;
	cout<<"Window Size:"<<ws;
	cout<<"\n Enter the total number of frames";
	cin>>n;
}
void sender()
{
	if(flag==0)
	{
		for(int i=0;i<ws;i++)
		{
			cout<<"Frame"<<i+1<<"Sent";
			t++;
		}
	}
	while(ctr<=n)
	{
		int bk=rec();
		if(bk==1)
		{
			cout<<"\n Ack received"<<endl;
			cout<<"\n Frame "<<ctr<<"sent successfully";
			flag=1;
			if(flag==1&&t<=n)
			{
				cout<<"\n Window shifts --------";
				cout<<"\n Frame "<<t<<"sent";
				t++;
				flag=0;
			}
			else{
				cout<<"\n Ack not received";
				for(int i=ctr;i<t;i++)
				{
					cout<<"\n frame"<<i<<"needs to resend";
				}
			}
		}
	}
}
int rec()
{
	int num=rand()%2;
	getch();
	return num;
}
}obj;
int main()
{
	obj.input();
	obj.sender();
	getch();
	return 0;
}
