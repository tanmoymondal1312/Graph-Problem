#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[26];
    for(int i=0; i<26; i++)ara[i]=0;
    string s;
    cin>>s;
    int  l= s.length();
    for(int i=0; i<l; i++)
    {
        ara[ s[i]-97]++;
    }
    int odd_letter = 0;
    for(int i=0; i<26; i++)
    {
        if(ara[i]== 1 || ara[i]%2 == 1)
        {
            odd_letter++;
        }
        if(odd_letter>1)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}

