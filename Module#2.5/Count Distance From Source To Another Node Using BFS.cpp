#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool visitArray[N];
int levelTrack[N];
int findDesUsingBFS(int src, int des)
{
    queue<pair<int,int>> Yuna;
    visitArray[src] = true;
    Yuna.push({src,0});
    while (!Yuna.empty())
    {
        pair<int,int> parent = Yuna.front();
        int value = parent.first;
        int level = parent.second;
        Yuna.pop();
        if (value == des)
            return level;
        else
        {
            for (int child : adjacencyList[value])
            {
                if (!visitArray[child])
                {
                    Yuna.push({child,level+1});
                    visitArray[child] = true;
                }
            }
        }
    }
    return -1;
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
    int q;
    cin >> q;
    while (q--)
    {
        memset(visitArray, false, sizeof(visitArray));
        int src, des;
        cin >> src >> des;
        int ans = findDesUsingBFS(src, des) ;
        if (ans == -1)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}