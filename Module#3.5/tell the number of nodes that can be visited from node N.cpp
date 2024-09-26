#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool visitArray[N];
int cnt;
void bfs(int src)
{
    visitArray[src] = true;
    queue<int> Yuna;
    Yuna.push(src);
    while (!Yuna.empty())
    {
        cnt++;
        int parent = Yuna.front();
        Yuna.pop();
        for (int child : adjacencyList[parent])
        {
            if (!visitArray[child])
            {
                visitArray[child] = true;
                Yuna.push(child);
            }
        }
    }
}
int main()
{
    cnt = 0;
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    int src;
    cin >> src;
    bfs(src);
    cout << cnt << endl;
    return 0;
}
