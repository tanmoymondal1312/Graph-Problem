#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e1;

int Gri[N][N];
bool visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int level[N][N];

bool InsG (pair<int,int>src);
bool Blocked(pair<int,int>src);
bool bfs(pair<int,int>src,pair<int,int>dst);

void PathP();

pair<int,int> srcc;
pair<int,int>parent[N][N];
queue<pair<int,int>>DST;

void BorderFinder(int n,int m);
void PathP(pair<int,int>dst);

int main()

{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {

            Gri[i][j]=1;
        }
    }
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        string a;
        cin>>a;
        for(int j=0; j<m; j++)
        {
            if(a[j]=='.')Gri[i][j]=0;
            else if(a[j]=='A')
            {
                Gri[i][j]=0;
                srcc= {i,j};
            }
        }
    }
    bool ok=false;
    int x,y;

    BorderFinder(n,m);
    while(!DST.empty())
    {
        x=DST.front().first;
        y=DST.front().second;
        DST.pop();
        ok=bfs(srcc, {x,y});
        if(ok==true)
        {
            cout<<"YES"<<"\n";
            cout<<level[x][y]<<"\n";
            PathP({x,y});
            return 0;
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                visited[i][j]=false;
                level[i][j]=0;
                parent[i][j]= {0,0};
            }
        }

    }
    cout<<"NO";

    return 0;
}
bool bfs(pair<int,int>src,pair<int,int>dst)
{
    visited[src.first][src.second]=true;
    queue<pair<int,int>>q;
    q.push(src);
    level [src.first][src.second]=0;
    while(!q.empty())
    {
        pair<int,int>head;
        head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0; i<4; i++)
        {
            pair<int,int> newnode= {x+dx[i],y+dy[i]};
            if(InsG(newnode)&&Blocked(newnode)&&visited[newnode.first][newnode.second]==false)
            {
                level[newnode.first][newnode.second]=level[x][y]+1;
                visited[newnode.first][newnode.second]=true;
                parent[newnode.first][newnode.second]= {x,y};
                q.push(newnode);
                if(newnode==dst)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool InsG (pair<int,int>src)
{
    if(src.first<n&&src.first>=0&&src.second<m&&src.second>=0)
    {
        return true;
    }
    return false;
}
bool Blocked(pair<int,int>src)
{
    if(Gri[src.first][src.second]!=1)
    {
        return true;
    }
    return false;
}
void PathP(pair<int,int>dst)
{
    queue<pair<int,int>>q;
    stack<char>st;
    q.push(dst);
    while(q.front()!=srcc)
    {
        pair<int,int>head=q.front();

        q.pop();
        if(head.first-parent[head.first][head.second].first==-1&&head.second-parent[head.first][head.second].second==0)
        {
            st.push('U');
        }
        else if(head.first-parent[head.first][head.second].first==1&&head.second-parent[head.first][head.second].second==0)
        {
            st.push('D');
        }
        else if(head.first-parent[head.first][head.second].first==0&&head.second-parent[head.first][head.second].second==1)
        {
            st.push('R');
        }
        else if(head.first-parent[head.first][head.second].first==0 &&head.second-parent[head.first][head.second].second==-1)
        {
            st.push('L');
        }
        q.push(parent[head.first][head.second]);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
void BorderFinder(int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)

        {
            if(i==0||i==n-1||j==0||j==m-1)
            {
                if(Gri[i][j]==0)
                {
                    DST.push({i,j});
                }
            }
        }
    }
}
