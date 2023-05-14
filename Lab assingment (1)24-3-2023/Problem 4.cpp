#include<bits/stdc++.h>
using namespace std;
const int N =1000;
int color[N];
vector<int>ad_lis[N];
bool bfs(int src);
int main()
{
    for(int i =0; i<N; i++)
    {
        color[i]=0;
    }
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
    bool x;
    for(int i=0; i<vertex; i++)
    {
        if(color[i]==0) x=bfs(i);
        if(x==false)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
bool bfs(int src)
{
    queue<int>q;
    q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int child: ad_lis[head])
        {
            if(color[child]==0)
            {
                if(color[head]==1)color[child]=2;
                else color[child]=1;
                q.push(child);
            }
            else if(color[child]==color[head])
            {
                return false;
            }
        }
    }
    return true;
}
