#include <bits/stdc++.h>
using namespace std;
void convert(int node, vector<pair<int,int>> adj[]) // like you get on leet code
{
    int mat[node][node];
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            mat[i][j] = -1;
            if (i == j)
            {
                mat[i][j] = 1;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < node; i++)
    {
        for (pair<int,int> child : adj[i])
        {
            int childNode = child.first;
            int childCost = child.second;
            mat[i][childNode] = childCost;
        }
    }
    // to check result
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<pair<int, int>> Lia[node];
    while(edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Lia[u].push_back({v,w});
        Lia[v].push_back({u,w});
    }
    return 0;
}