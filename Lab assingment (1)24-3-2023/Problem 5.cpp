#include<bits/stdc++.h>
using namespace std;
const int N =1000;
vector<int>ad_lis[N];
int main()
{
    int edge;
    int vertex;
    cin>>vertex>>edge;
    for(int i=0; i<edge; i++)
    {
        int v,u;
        cin>>v>>u;
        ad_lis[v].push_back(u);
        ad_lis[u].push_back(v);
    }
    int connected=0;
    for(int i=0; i<edge; i++)
    {
        if(ad_lis[i].size()!=0)connected++;
    }
    cout<<connected;
    return 0;
}
