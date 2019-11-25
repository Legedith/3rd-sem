#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int CalculateR(int d_size)
{
	int r = 0;
	while (true)
	{
		if (pow(2, r) >= d_size + r + 1)
			break;
		else
			r++;
	}
	return r;
}

void binary(int i, int *p)
{
	int k = 0;
	while (i > 0)
	{
		p[k++] = i % 2;
		i = i / 2;
	}
}
int decimal(int ab[], int r)
{
	int temp = 0;
	for (int i = 0; i < r; i++)
	{
		temp += pow(2, i) * ab[i];
	}
	return temp;
}

void CreateCodeword(char *m_code, char data_code[], int d_size, int r)
{
	int k = d_size - 1;
	int i1 = 0, j = 0;

	for (int i = d_size + r - 1; i >= 0; i--)
	{

		if (i1 == pow(2, j) - 1)
		{
			j++;
			m_code[i] = 'a';
		}
		else
		{
			m_code[i] = data_code[k];
			k--;
		}
		i1++;
	}
}

int main()
{
	string a;
	int d_size = 0;
	cout << "Enter Data\n";
	cin >> a;
	d_size = a.length();
	char data_code[d_size];
	strcpy(data_code, a.c_str());

	int r = CalculateR(d_size);

	char m_code[d_size + r];

	CreateCodeword(m_code, data_code, d_size, r);

	int count[r] = {0};
	cout << "The New Data is\n";
	for (int i = 0; i < d_size + r; i++)
		cout << m_code[i] << "   ";
	cout << endl;
	int i1 = 0;
	int j = 0;
	int ab[r];
	int *bin = new int[r];
	for (int i = d_size + r - 1; i >= 0; i--)
	{
		binary(i1 + 1, bin);

		for (int i2 = 0; i2 < r; i2++)
		{
			if (bin[i2] == 1 && m_code[i] == '1')
			{
				count[i2]++;
			}
		}
		i1++;
	}
	cout << " Count----------->>>>>>>>>>>>>>>\n";
	for (int i = 0; i < r; i++)
		cout << count[i] << endl;
	i1 = 0;
	j = 0;
	for (int i = d_size + r - 1; i >= 0; i--)
	{
		if (i1 == pow(2, j) - 1)
		{
			if (count[j] % 2 == 0)
			{
				m_code[i] = '0';
			}
			else
			{
				m_code[i] = '1';
			}
			j++;
		}
		i1++;
	}
	cout << "The New Data is sent by Sender  is\n";
	for (int i = 0; i < d_size + r; i++)
		cout << m_code[i] << "   ";

	cout << endl;
	i1 = 0;
	for (int i = 0; i < r; i++)
		count[i] = 0;
	int *bin2 = new int[r];
	for (int i = d_size + r - 1; i >= 0; i--)
	{
		binary(i1 + 1, bin2);
		for (int i2 = 0; i2 < r; i2++)
		{

			if (bin2[i2] == 1 && m_code[i] == '1')
			{
				count[i2]++;
			}
		}
		i1++;
	}

	cout << " Second Counted Values are\n";
	for (int i = 0; i < r; i++)
	{
		cout << count[i] << endl;
	}
	i1 = 0;
	j = 0;
	for (int i = d_size + r - 1; i >= 0; i--)
	{
		if (i1 == pow(2, j) - 1)
		{
			if (count[j] % 2 == 0)
			{
				m_code[i] = '0';
				ab[j] = 0;
			}
			else
			{
				m_code[i] = '1';
				ab[j] = 1;
			}
			j++;
		}
		i1++;
	}
	for (int i = r - 1; i >= 0; i--)
		cout << ab[i] << " ,  ";
	cout << endl;
	int value = decimal(ab, r);
	char data[d_size];
	int l = d_size - 1;
	if (value == 0)
	{
		cout << " There is no any error\n";
		cout << " Data Received By Receiver Successfully\n";
		i1 = 0;
		j = 0;
		for (int i = d_size + r - 1; i >= 0; i--)
		{
			if (i1 == pow(2, j) - 1)
			{
				j++;
			}
			else
			{
				data[l] = m_code[i];
				l--;
			}
			i1++;
		}

		cout << " Data is\n";
		for (int i3 = 0; i3 < d_size; i3++)
			cout << data[i3] << "  ";
		cout << endl;
	}
	else
	{
		cout << " There is error at position " << value << endl;
		i1 = 0;
		j = 0;
		for (int i = d_size + r - 1; i >= 0; i--)
		{
			if (i1 == value - 1)
			{
				if (m_code[i] == '0')
					m_code[i] = '1';
				else
					m_code[i] = '0';
				break;
			}
			i1++;
		}

		cout << "After modification\n";
		for (int i = 0; i < d_size + r; i++)
			cout << m_code[i] << "   ";
		cout << endl;
	}
	exit(100);
}