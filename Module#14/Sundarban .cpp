#include <bits/stdc++.h>
using namespace std;
char grid[50][50];
bool vis[50][50];
int dis[50][50];
int n;
vector<pair<int, int>> diff={{0,1},{1,0},{-1,0},{0,-1}};
bool isValid (int ci, int cj)
{
    return (ci >= n && ci < 0 && cj >= n && cj < 0);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> Yuna;
    Yuna.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while(!Yuna.empty())
    {
        pair<int, int> parent = Yuna.front();
        Yuna.pop();
        for (int i = 0; i < 4;i++)
        {
            int ci = parent.first;
            int cj = parent.second;
            if(isValid(ci,cj) && !vis[ci][cj] && grid[ci][cj]!='T')
            {
                Yuna.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[parent.first][parent.second]+1;
            }
        }
    }
}
int main()
{
    while(cin>>n)
    {
        int si, sj;
        int di, dj;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                cin >> grid[i][j];
                if(grid[i][j]='S')
                {
                    si = i;
                    sj = j;
                }
                if(grid[i][j]='E')
                {
                    di = i;
                    dj = j;
                }

            }
        }
        memset(dis, -1, sizeof(dis));
        memset(vis, false, sizeof(vis));
        bfs(si,sj);
        cout << dis[di][dj] << endl;
    }
    return 0;
}