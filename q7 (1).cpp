#include<iostream>
#include <conio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
using namespace std;
int sum=0;
void* runner(void* b);
int main()
{
	
	pthread_t t;
	int a;
	cout<<"Enter number till which sum is found : ";
	cin>>a;
	int d=pthread_create(&t,NULL,runner,&a);
	pthread_join(t,NULL);
	if(d==0)
	{
		cout<<"Thread is created"<<endl;
		cout<<"Sum is "<<sum<<endl;
	}
	getch();
	return 0;
}
void* runner(void* b)
{
	int a=*(int*)b;
	for(int i=1;i<=a;i++)
	sum+=i;
}
