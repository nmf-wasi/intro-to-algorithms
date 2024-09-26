#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<pair<int,int>> adjacencyList[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j]==1 && i!=j)
            {
                adjacencyList[i].push_back({j,mat[i][j]});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> child : adjacencyList[i])
        {
            cout << "{" << child.first<<", "<<child.second << "} ";
        }
        cout << endl;
    }


    return 0;
}