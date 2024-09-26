#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visitArray[N];
vector<int> adjacentList[N];
int parentArray[N];
bool ans = false;
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visitArray[src] = true;
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        Yuna.pop();
        cout << parent << " ";
        for (int child : adjacentList[parent])
        {
            if(visitArray[child]==true && parentArray[parent]!=child)
            {
                ans=true;
            }
            if (!visitArray[child])
            {
                visitArray[child] = true;
                parentArray[child] = parent;
                Yuna.push(child);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjacentList[a].push_back(b);
        adjacentList[b].push_back(a);
    }
    memset(visitArray, false, sizeof(visitArray));
    memset(parentArray, -1, sizeof(parentArray));
    for (int i = 0; i < n; i++)
    {
        if (!visitArray[i])
        {
            bfs(i);
        }
    }
    if(ans)
        cout<<"Cycle Detected";
    else
        cout << "NO Cycle Found";
    return 0;
}
