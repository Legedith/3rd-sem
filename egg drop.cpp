#include<iostream>
#include<conio.h>
#include<math.h>
#include<cstdlib>
int k;
int N;
int c=0;
int steps=0;
using namespace  std;
bool broken(int f)
{
	if(f<=c)
		return false;
	else
		return true;
}
int drop(int n,int low,int up)
{
	if(low == up )
	{
		return low;
	}
	cout<<n<<" "<<low<<" "<<up<<endl;
	if(n==1)
	{
		cout<<"Here nigga\n";
		for(int i=low;n>0 and i<up;i++)
		{
			cout<<"Dropping from floor: "<<i<<endl;
			steps++;
			if(broken(i))
			{
				cout<<" Broken";
				steps++;
				cout<<"Broke here: "<<i<<endl;
				return i+1;
			}
			cout<<" Not Broken"<<endl;
		}
	}
	else if(n>=2)
	{
		cout<<"Dropping from foor: "<<(low+up)/2;
		if(broken((low+up)/2))
		{
			cout<<" Broken"<<endl;
			n--;
			steps++;
			return drop(n,low,(low+up)/2-1);
		}
		else
		{
			cout<<" Not Broken"<<endl;
			steps++;
			return drop(n,(low+up)/2+1,up);
		}
	}
}
int main()
{
	for(int i=1; i<15; i++)
	{
		for(int j=2; j<)
	}
	th=drop(N,1,k);
	cout<<"Breaking floor is: "<<th<<endl;
	cout<<"Steps to reach critical floor: "<<steps<<endl;
	getch();
	
}
