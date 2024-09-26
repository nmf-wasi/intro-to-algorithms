#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
bool pathVisit[N];
vector<int> adjacencyList[N];
bool cycle = false;
void dfs(int parent)
{
    vis[parent] = true;
    pathVisit[parent]=true;
    for(int child:adjacencyList[parent])
    {
        if(pathVisit[child])
            cycle = true;
        if(!vis[child])
            dfs(child)
    }
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
        // adjacencyList[b].push_back(a);
    }
    memset(pathVisit, false, sizeof(pathVisit));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < node; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    if(cycle)
        cout << "CYCLE DETECTED!" << endl;
    else
        cout << "NO CYCLE FOUND!" << endl;
    return 0;
}