#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool visitArray[N];
bool pathVisit[N];
bool ans = false;
void dfs(int parent)
{
    visitArray[parent] = true;
    pathVisit[parent] = true;
    for (int child : adjacencyList[parent])
    {
        if (pathVisit[child])
            ans = true;
        if (!visitArray[child])
            dfs(child);
    }
    // kaj sesh
    pathVisit[parent] = false;
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
    }
    memset(visitArray, false, sizeof(visitArray));
    memset(pathVisit, false, sizeof(pathVisit));
    for (int i = 0; i < node; i++)
    {
        if (!visitArray[i])
            dfs(i);
    }
    if (ans)
        cout << "Cycle Detected";
    else
        cout << "NO Cycle Found";
    return 0;
}