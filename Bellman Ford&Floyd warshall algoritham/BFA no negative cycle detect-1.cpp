#include<bits/stdc++.h>
using namespace std;
int N=1e5+5;
int INF = 1e9;
vector<pair<int,int> >adjlist[N];
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        d[i] = INF;
    }
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
    }
    int src = 1;
    d[src]=0;

    for(int i=1;i<=n-1;i++)
    {
        for(int node = 1;node<=n;node++)
        {
            for(pair<int,int>adjnode:adjlist[node])
            {
                int u=node;
                int v= adjnode.first;
                int w= adjnode.second;

                if(d[u]+w<d[v])
                {
                    d[v]=d[u]+w;
                }
            }
        }
    }
    for (int i=0;i<=n;i++)
    {
        cout<<d[i];
    }
    cout<<"\n";
}
