#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int>adjecen[N];
bool Visited[N];
void BFS(int src);
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adjecen[u].push_back(v);
        adjecen[v].push_back(u);
    }
    BFS(1);
    if(Visited[n])

    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}
void BFS(int src)
{
    Visited[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(auto j:adjecen[head])
        {
            if(Visited[j]==false)
            {
                Visited[j]=true;
                q.push(j);
            }
        }
    }
}
