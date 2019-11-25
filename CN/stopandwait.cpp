#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;
class stopandwait
{
	long int frame[20];
	int n,sq,ack,z;
	public:
		stopandwait()
		{
			sq=0;
			z=1;
		}
		void input()
		{
			cout<<"\n Enter total no. of frames to be send: ";
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cout<<"Enter data in frame "<<i<<" : ";
				cin>>frame[i];
			}
			sender(0);
		}
		void sender(int timer)
		{
			cout<<"\n\nSender : \n\n";
			if(timer==-1)
				cout<<"Timer stopped: Acknowledgement not recieved";
			cout<<"\n Frame sent to reciever is : "<<z<<" And data in frame is : "<<frame[z];
			cout<<"\nSequence no. is : "<<sq;
			getch();
			if(z>n)
			{}
			else
				reciever(z,sq);
		}
		void reciever(int y,int sq)
		{
			int r=(rand()%3)+1;
			cout<<"\n\n Reciever :\n\n";
			switch(r)
			{
				case 1:{cout<<"\nFrame "<<y<<" recieved with Data : "<<frame[y];
					cout<<"Sequence no. is : "<<sq<<"\nPACKET RECIEVED SUCCESSFULLY";
					z+=1;
					sq=(sq+1)%2;
					sender(0);
					break;
				}
				case 2:{cout<<"\nFrame "<<y<<" recieved with Data : "<<frame[y];
					cout<<"Sequence no. is : "<<sq<<"\nPACKET RECIEVED SUCCESSFULLY";
					cout<<"\nAcknowledgement Sent";
					sender(-1);
					break;
				}
				case 3:{cout<<"\nFrame LOST\nSequence no. is : "<<sq;
					cout<<"\nNegative Acknowledgement send";
					sender(0);
					break;
				}
			}
		}
}obj;
int main()
{
	obj.input();
	getch();
	return 0;
}
