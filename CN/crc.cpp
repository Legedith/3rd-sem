#include <iostream>
#include <conio.h>
using namespace std;
void divi(int p[], int g[], int n, int m)
{
	for(int i=0; i<n; i++)
	{
		if(p[i]==g[0])
		{
			for(int j=0, k=i;j<m;j++,k++)
			{
				p[k] = p[k]^g[j];
			}
		}
	}
}
int main()
{
	int n,m;
	cout<<"Enter no. of message bits: ";
	cin>>n;
	cout<<"Enter no. of key bits: ";
	cin>>m;
	int M[n], k[m], p[m+n-1];
	cout<<"Enter message: ";
	for(int i=0; i<n; i++)
	{
		cin>>M[i];
		p[i] = M[i];
		}	
	cout<<"Enter key: ";
	for(int i=0; i<m; i++)
		cin>>k[i];
	for(int i=n;i<n+m-1;i++)
	{
		p[i] = 0;
	}
	divi(p, k, n, m);
	for(int i=0; i<m+n-1; i++)
		cout<<p[i];	
	getch();
	return 0;
}
//
//get bits
//get key
//bit(size) += key-1
//divide bit by key xor
//append remainder to original data
//on receiver side
//	divide received data by key
//	if remainder ==0
//	 	correct
//	else 
//		false 
