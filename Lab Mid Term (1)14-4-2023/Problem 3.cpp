#include<bits/stdc++.h>
using namespace std;
const int N=505;
const long long int infinity = 1e18;
int n,m,q;
long long int adjm[N][N];
void fw();
int main()
{
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            adjm[i][j] = infinity;
        }
    }
    for(int i = 1; i<=n; i++)  adjm[i][i] = 0;
    for(int i =1; i<=m; i++)
    {
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        adjm[u][v] = min(w, adjm[u][v]);
        adjm[v][u] = min(w,adjm[v][u]);
    }
    fw();
    for(int i=1; i<=q; i++)
    {
        int u,v;
        cin>>u>>v;
        if(adjm[u][v]==infinity)
            cout<<-1<<endl;
        else
            cout<<adjm[u][v]<<endl;
    }
    return 0;
}
void fw()
{
    for(int k=1; k<=n; k++)
    {
        for( int u=1; u<=n; u++)
        {
            for( int v=1; v<=n; v++)
            {
                if(adjm[u][v]>adjm[u][k]+adjm[k][v])
                    adjm[u][v] = adjm[u][k]+adjm[k][v];
            }
        }
    }

}
