#include<bits/stdc++.h>
using namespace std;
const int N=1000;
vector<int>adja_list[N];
int  visited[N];
bool yes_cycel=false;
void cycle_detector(int src);
int main()
{
    for(int i=0; i<N; i++)
    {
        visited[i]=0;
    }
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
    }
    cycle_detector(0);
    if(yes_cycel==true)cout<<"YES";
    else cout<<"NO";
    return 0;
}
void cycle_detector(int src)
{
    visited[src]=1;
    for(int child:adja_list[src])
    {
        if(visited[child]==0)cycle_detector(child);
        if(visited[child]==1)
        {
            yes_cycel=true;
            return;
        }
    }
    visited[src]=2;
}
