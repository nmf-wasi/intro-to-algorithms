#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool vis[N];
int bfs(int src)
{
    vis[src] = true;
    queue<int> Yuna;
    Yuna.push(src);
    int number = 0;
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        number++;
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
    return number;
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
    vector<int> ans;
    for (int i = 0; i < node; i++)
    {
        if (!vis[i])
        {
            int number = bfs(i);
            ans.push_back(number);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}