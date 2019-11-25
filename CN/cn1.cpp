#include <iostream>
#include <string.h>
using namespace std;

class CRC
{
    char d[30], k[10], fd[30], c[10];
    int dl, kl, tl;

public:
    void input();
    void output();
    void remainder();
    void xorFunction();
};

void CRC::input()
{
    int i;
    cout << "Enter the data part here : ";
    cin >> d;
    cout << "Enter the key part here : ";
    cin >> k;
    cout << "Your data is : " << d << endl;
    cout << "Your key is : " << k << endl;
    dl = strlen(d);
    kl = strlen(k);
    tl = dl + kl;
    for (i = 0; i < dl; i++)
        fd[i] = d[i];
    for (i; i < tl - 1; i++)
        fd[i] = '0';
    cout << "Data after appending zeroes is : " << fd << endl;
}

void CRC::remainder()
{
    int i, j;
    for (i = 0; i < kl; i++)
        c[i] = fd[i];
    do
    {
        if (c[0] == '1')
            xorFunction();
        for (j = 0; j < kl; j++)
            c[j] = c[j + 1];
        c[j] = fd[i++];
    } while (i < tl);
}

void CRC::xorFunction()
{
    for (int i = 1; i < kl; i++)
    {
        if (c[i] == k[i])
            c[i] = 0;
        else
        {
            c[i] = '1';
        }
    }
}

void CRC::output()
{
    int count = 0;
    for (int i = dl; i < tl - 1; i++)
        fd[i] = c[i - dl];
    cout << "Remainder is : " << c << endl;
    for (int i = 0; i < kl; i++)
    {
        if (c[i] == 0)
            count++;
        else
            break;
    }
    if (count == kl)
        cout << "Data is correct...\n";
    else
    {
        cout << "Data contains some errors\n";
        cout << "Final data to be sent is :" << fd << endl;
    }
    remainder();
    cout << "Remainder now is : " << c << endl;
}

int main()
{
    CRC c;
    c.input();
    c.remainder();
    c.output();
    return 0;
}