#include <bits/stdc++.h>
#define ll long long int
// always define berfore using namespace
using namespace std;
int main()
{
    ll node, edge;
    cin >> node >> edge;
    ll adjacencyMatrix[node][node];
    // we will be cecking the additions of INT_MAX s so, if we take int, it will surpress the limit
    while (edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjacencyMatrix[a][b];
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            adjacencyMatrix[i][j] = INT_MAX;
            if (i == j)
                adjacencyMatrix[i][j] = 0;
        }
    }

    for (int k = 0; k < node; k++)
    {
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                if (adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j])
                {
                    adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                }
            }
        }
    }
    // cout << "AFTER" << endl;
    // for (int i = 0; i < node; i++)
    // {
    //     for (int j = 0; j < node; j++)
    //     {
    //         if (adjacencyMatrix[i][j] == INT_MAX)
    //             cout << "INF ";
    //         else
    //             cout << adjacencyMatrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int i = 0; i < node; i++)
    {
        if (adjacencyMatrix[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            break;
        }
    }
    return 0;
}