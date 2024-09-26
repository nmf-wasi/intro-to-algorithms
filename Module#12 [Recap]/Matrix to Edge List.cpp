#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin >> node >> edge;
    int mat[node][node];
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            cin >> mat [i][j];
        }
    }
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < node;i++)
    {
        for (int j = 0; j < node;j++)
        {
            if(mat[i][j]==1 && i!=j)
            {
                edgeList.push_back({i, j});
            }
        }
    }
    for(pair<int,int>edge:edgeList)
    {
        cout << edge.first << " " << edge.second << endl;
    }
        return 0;
}