#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin >> node >> edge;
    vector < pair<int, int>> adjacencyList[node];
    while(edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjacencyList[a].push_back({b,c});
        adjacencyList[b].push_back({a,c});
    }
    //to check
    for (int i = 0; i < node; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> child : adjacencyList[i])
        {
            cout << "{" << child.first << ", " << child.second << "} ";
        }
        cout << endl;
    }
    return 0;
}