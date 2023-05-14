#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> adjList[N];
bool visited[N];

bool dfs(int node, int parent)
{
    visited[node] = true;
    for(int i = 0; i < adjList[node].size(); i++)
    {
        int v = adjList[node][i];
        if(!visited[v])
        {
            if(dfs(v, node)) return true;
        }
        else if(v != parent) return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool cycle = false;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cycle = cycle || dfs(i, -1);
        }
    }

    if(cycle) cout << "Cycle Exist\n";
    else cout << "No Cycle\n";

    return 0;
}
