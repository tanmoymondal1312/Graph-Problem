#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<pair<int,int>>adj[N];
bool visited[N];
long long dist[N];
int parent[N];
const long long int INF=1e18;
void dijkstra(pair<int,int>src);


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        dist[i]=INF;
    }
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int src=1;
    dist[src]=0;
    pair<int,int>src_node= {0,src};
    dijkstra(src_node);
    if(visited[n]==false)
    {
        cout<<-1;
        return 0;
    }
    stack<int>st;
    st.push(n);
    queue<int>q;
    q.push(parent[st.top()]);
    while(q.front()!=1)
    {
        st.push(q.front());
        q.push(parent[st.top()]);
        q.pop();
    }
    cout<<1<<" ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
void dijkstra(pair<int,int>src)
{
    priority_queue<pair<int,int>>pq;
    int f=(-1)*src.first;
    int s=src.second;
    pair<int,int>now= {f,s};
    pq.push(now);
    while(!pq.empty())
    {
        pair<int,int>head= {(-1)*pq.top().first,pq.top().second};
        pq.pop();
        if(visited[head.second]==true)continue;
        visited[head.second]=true;
        for(auto j:adj[head.second])
        {
            if(dist[head.second]+j.first<dist[j.second])
            {
                dist[j.second]= dist[head.second]+j.first;
                int ff=(-1)* dist[j.second];
                int ss=j.second;
                parent[ss]=head.second;
                pair<int,int>wiilpushe= {ff,ss};
                pq.push(wiilpushe);
            }
        }
    }
}

