#include <iostream>
#include <string.h>
using namespace std;

void check(string);
int main()
{
    cout << "Enter the address" << endl;
    string s;
    cin >> s;
    check(s);
    return 0;
}

void check(string a)
{
    int x = 0;
    for (int i = 0; i < 3; i++)
    {
        x = (x * 10) + (a[i] - 48);
        if (x >= 0 && x <= 127)
            cout << "class A" << endl;
        else if (x >= 128 && x <= 191)
            cout << "class B" << endl;
        else if (x >= 192 && x <= 223)
            cout << "class C" << endl;
        else if (x >= 224 && x <= 239)
            cout << "class D" << endl;
        else
            cout << "class E" << endl;
    }
}