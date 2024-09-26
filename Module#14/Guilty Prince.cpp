#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char grid[N][N];
bool vis[N][N];
int row, col;
int si, sj;
int cnt;
vector<pair<int, int>> dif = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int ci, int cj)
{
    return (ci > 0 && ci <= row && cj > 0 && cj <= col);
}
void dfs(int si,int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4;i++)
    {
        int ci = si + dif[i].first;
        int cj = sj + dif[i].second;
        if(isValid(ci,cj) && !vis[ci][cj]  && grid[ci][cj]=='.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    int cs=1;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> col >> row; // ques e ulta
        for(int i=0;i<row;i<col)
        {
            for (int j = 0; j < col;j++)
            {
                cin >> grid[i][j];
                if(grid[i][j]=='@')
                {
                    si=i;
                    sj=j;
                }
            }
        }
        cnt = 0;
        memset(vis, false, sizeof(vis));
        dfs(si,sj);
        cout << "Case " << cs++ << ": " << cnt << endl;
        // ++cs means will increase then rpint 
        // cs++ means will print then increase for next time
    }
    return 0;
}