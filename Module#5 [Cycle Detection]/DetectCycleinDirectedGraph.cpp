#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visitArray[N];
vector<int> adjacentList[N];
int parentArray[N];
bool ans = false;
void dfs(int parent)
{
    visitArray[parent] = true;
    for (int child : adjacentList[parent])
    {
        if (visitArray[child] = true && parentArray[parent] != child)
        {
            ans = true;
        }
        // cout << parent << " ";
        if (!visitArray[child])
        {
            parentArray[child] = parent;
            dfs(child);
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
    }
    memset(visitArray, false, sizeof(visitArray));
    memset(parentArray, -1, sizeof(parentArray));
    for (int i = 0; i < n; i++)
    {
        if (!visitArray[i])
        {
            dfs(i);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << parentArray[i] << endl;
    // }
    if (ans)
        cout << "Cycle Detected";
    else
        cout << "NO Cycle Found";
    return 0;
}
