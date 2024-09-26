#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool visitArray[N];
int levelArray[N];
void levelTrack(int src)
{
    queue<pair<int, int>> Yuna;
    visitArray[src] = true;
    Yuna.push({src, 0});
    while (!Yuna.empty())
    {
        pair<int, int> parent = Yuna.front();
        Yuna.pop();
        int value = parent.first;
        int level = parent.second;
        levelArray[value] = level;
        for (int child : adjacencyList[value])
        {
            if (!visitArray[child])
            {
                Yuna.push({child, level + 1});
                visitArray[child] = true;
            }
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    memset(visitArray, false, sizeof(visitArray));
    memset(levelArray, -1, sizeof(levelArray));
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a); // unwieghted
    }
    int src;
    src = 0; // given
    levelTrack(0);
    vector<int> Yuna;
    int lvl;
    cin >> lvl;
    for (int i = 0; i < node; i++)
    {
        if (levelArray[i] == lvl)
            Yuna.push_back(i);
    }
    reverse(Yuna.begin(), Yuna.end());
    for (int i : Yuna)
    {
        cout << i << " ";
    }
    return 0;
}