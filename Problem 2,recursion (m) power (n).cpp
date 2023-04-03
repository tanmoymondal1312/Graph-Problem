#include <bits/stdc++.h>
using namespace std;

int power(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        return n * power(n, m-1);
    }
}

int main()
{
    int n, m;
    cout << "Enter the base number (n): ";
    cin >> n;
    cout << "Enter the exponent (m): ";
    cin >> m;
    cout << n << " To the power of " << m << " is: " << power(n, m) <<"\n";
    return 0;
}
