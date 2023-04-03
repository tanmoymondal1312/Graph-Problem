#include<bits/stdc++.h>
using namespace std;

int sumVector(vector<int> v, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return v[n-1] + sumVector(v, n-1);
    }
}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int sum = sumVector(v, n);
    cout << "Sum of vector: " << sum << endl;
    return 0;
}
