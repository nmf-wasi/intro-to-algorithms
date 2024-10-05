#include <bits/stdc++.h>
using namespace std;
int r, c;
char grid[10005][10005];
bool vis[10005][10005];
vector<pair<int, int>> difference = {{0,1},{0,-1},{1,0},{-1,0}};
bool valid(int childRow, int childCol)
{
    if (childRow < 0 || childRow >= r || childCol < 0 || childCol >= c)
        return false;
    return true;
}
int sz;
int bfs(int sr, int sc)
{
    queue<pair<int, int>> Yuna;
    Yuna.push({sr, sc});
    while (!Yuna.empty())
    {
        sz++;
        pair<int, int> parent = Yuna.front();
        int parentRow = parent.first;
        int parentCol = parent.second;
        Yuna.pop();
        for (int i = 0; i < 4; i++)
        {
            int childRow = parentRow + difference[i].first;
            int childCol = parentCol + difference[i].second;
            if (valid(childRow, childCol) == true && vis[childRow][childCol] == false && grid[childRow][childCol]=='.')
            {
                Yuna.push({childRow, childCol});
                vis[childRow][childCol] = true;
            }
        }
    }
    if(sz>1)
        return sz-1;
    else
        return sz;
}
int main()
{
    cin>>r>>c;
    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j < c;j++)
        {
            cin>>grid[i][j];
        }
    }
    int mn = INT_MAX;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c;j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                sz = 0;
                mn = min(bfs(i, j), mn);
            }
        }
    }
    if(mn!=INT_MAX)
        cout << mn << endl;
    else
        cout << -1 << endl;
    return 0;
}