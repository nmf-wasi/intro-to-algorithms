#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int parentArray[N];
vector<int> adjacencyList[N];
bool cycle = false;
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    vis[src] = true;

    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        Yuna.pop();

        for (int child : adjacencyList[parent])
        {
            if (vis[child] && parentArray[parent] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                Yuna.push(child);
                vis[child] = true;
                parentArray[child] = parent;
            }
        }
    }
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
        adjacencyList[b].push_back(a);
    }
    memset(parentArray, -1, sizeof(parentArray));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < node; i++)
    {
        if (!vis[i])
            bfs(i);
    }
    if(cycle)
        cout << "CYCLE DETECTED!" << endl;
    else
        cout << "NO CYCLE FOUND!" << endl;
    return 0;
}