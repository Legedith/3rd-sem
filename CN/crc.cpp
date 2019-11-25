#include <iostream>
using namespace std;

class A
{
public:
	int msg[20], key[20], m, k, msg1[20];
	void read()
	{
		cout << " Enter The number of bits of message\n";
		cin >> m;
		cout << " Enter Message\n";
		for (int i = 0; i < m; i++)
		{
			cin >> msg[i];
			msg1[i] = msg[i];
		}
		cout << " Enter the number of bits of crc generator\n";
		cin >> k;
		cout << " Enter Generator bits\n";
		for (int i = 0; i < k; i++)
			cin >> key[i];
	}
	void encode_and_decode()
	{
		for (int i = m; i < m + k - 1; i++)
		{
			msg[i] = 0;
		}
		int j, k1;
		cout << " Sender Side-------------->>>>>>>>>>>>>\n";
		cout << " New Data\n";
		for (int i = 0; i < m + k - 1; i++)
			cout << msg[i] << " ";
		cout << endl;
		for (int i = 0; i < m; i++)
		{
			j = 0;
			k1 = i;
			if (msg[k1] >= key[j])
			{
				for (j = 0, k1 = i; j < k; j++, k1++)
				{
					if (msg[k1] == key[j])
					{
						msg[k1] = 0;
					}
					else
					{
						msg[k1] = 1;
					}
				}
			}
		}
		int crc[20];
		for (int i = 0, j = m; i < k - 1; i++, j++)
			crc[i] = msg[j];
		cout << " CRC is\n";
		for (int i = 0; i < k - 1; i++)
			cout << crc[i];
		cout << endl;
		for (int i = m, j = 0; i < m + k - 1; i++)
		{
			msg1[i] = crc[j];
			j++;
		}
		cout << " Receiver Side------------------------->>>>>>>>>>>>>>>>>>>>>>>\n";
		cout << " After appending  the CRC\n";
		for (int i = 0; i < m + k - 1; i++)
			cout << msg1[i] << "  ";
		cout << endl;
		for (int i = 0; i < m; i++)
		{
			j = 0;
			k1 = i;

			if (msg1[k1] >= key[j])
			{
				for (j = 0, k1 = i; j < k; j++, k1++)
				{
					if (msg1[k1] == key[j])
					{
						msg1[k1] = 0;
					}
					else
					{
						msg1[k1] = 1;
					}
				}
			}
		}
		int rem[20];
		for (int i = 0, j = m; i < k - 1; i++, j++)
			rem[i] = msg1[j];
		cout << " Remainder is\n";
		for (int i = 0; i < k - 1; i++)
			cout << rem[i];
		cout << endl;
		int flag = 0;
		for (int i = 0; i < k - 1; i++)
		{
			if (rem[i] != 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			cout << " Error Detected\n";
		else
			cout << " There is no any error\n";
	}
};
int main()
{
	A ob;
	ob.read();
	ob.encode_and_decode();
}
