#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <math.h>
#include <time.h>
using namespace std;

int cf = 0;
class gbn
{
public:
	int flag, t, sq, ws, ctr, n;
	gbn()
	{
		flag = 0;
		t = 1;
		ctr = 1;
	}
	void input()
	{
		cout << "enter number of bits in sequence number";
		cin >> sq;
		ws = pow(2, sq) - 1;
		cout << "window size" << ws;
		cout << "enter the total number of frames" << endl;
		cin >> n;
	}
	void sender()
	{
		if (flag == 0)
		{
			for (int i = 0; i < ws; i++)
			{
				cout << "frame" << i + 1 << "sent" << endl;
				t++;
			}
		}
		while (ctr <= n)
		{
			int bk = rec();
			if (bk == 1)
			{
				cout << "acknowledgement received" << endl;
				cout << "frame" << ctr << "sent successfully";
				flag = 1;
				ctr++;
			}
			if (flag == 1 && t <= n)
			{
				cout << "window shifts............" << endl;
				cout << "frame" << t << "sent" << endl;
				t++;
				flag = 0;
			}
			else
			{
				cout << "ack not received" << endl;
				for (int i = ctr; i < t; i++)
				{
					cout << "frame" << i << "need to resent" << endl;
				}
			}
		}
	}
	int rec()
	{
		int num = rand() % 2;
		getch();
		return num;
	}
} ob;
int main()
{
	ob.input();
	ob.sender();
	getch();
}
