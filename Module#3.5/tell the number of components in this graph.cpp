#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool vis[N];
void bfs(int src)
{
    vis[src] = true;
    queue<int> Yuna;
    Yuna.push(src);
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        Yuna.pop();
        for (int child : adjacencyList[parent])
        {
            if (!vis[child])
            {
                vis[child] = true;
                Yuna.push(child);
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
    int ans = 0;
    for (int i = 0; i < node; i++)
    {
        if (!vis[i])
        {
            bfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}