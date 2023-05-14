#include <bits/stdc++.h>
using namespace std;
SUM(string s,int IDEX)
{
    if(IDEX==0)
    {
        return s[IDEX] - 48;
    }
    return  s[IDEX] - 48 + SUM(s, IDEX - 1);
}
int main()
{
    string n;
    cin>>n;
    int len = n.length();
    cout<<SUM(n,len - 1);
    return 0;
}

