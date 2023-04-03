#include<bits/stdc++.h>
using namespace std;
const int N=1000;
vector<int>adja_list[N];
int level[N];
bool visited[N];
void level_counter(int src)
{
    visited[src]=true;
    level[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int child:adja_list[head])
        {
            if(visited[child]==false)
            {
                visited[child]=true;
                level[child]=level[head]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int vertex;
    int edge;
    cout<<"enter the number of vertex>>";
    cin>>vertex;
    cout<<"enter the number of edge>>";
    cin>>edge;
    cout<<"enter all the  edges>>\n";
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }
    level_counter(0);
    for(int i=0; i<vertex; i++)
    {
        cout<<i<<" -> level:"<<level[i]<<"\n";
    }
    return 0;
}
