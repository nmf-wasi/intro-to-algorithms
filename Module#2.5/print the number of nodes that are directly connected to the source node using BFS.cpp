#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool visitArray[N];
int ans = 0;

int main()
{
    int node, edge;
    cin >> node >> edge;
    memset(visitArray, false, sizeof(visitArray));
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    int src;
    cin >> src;
    // for(int i: adjacencyList[src])
    // {
    //     ans++;
    // }
    cout << adjacencyList[src].size() << endl;
    return 0;
}