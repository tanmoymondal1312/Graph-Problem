#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex;
    cin>>vertex;
    int adja_matrix[vertex][vertex];
    vector<int>adja_list[vertex];
/*
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 1 1
0 1 0 1 0 0
0 0 1 1 0 0


*/

    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            adja_matrix[i][j]=0;
            cin>>adja_matrix[i][j];
            if(adja_matrix[i][j]!=0)
                adja_list[i].push_back(j);
        }
    }

    cout<<"\n";
    for(int i=0; i<vertex; i++)
    {
        cout<<i<<": ";
        for(int j:adja_list[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
