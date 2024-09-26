#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char grid[N][N];
bool vis[N][N];
int r, c;
int steps = 0;
vector<char> texts;
vector<pair<int, int>> dif = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isValid(int cr, int cc)
{
    return (cr < r && cr >= 0 && cc < c && cc >= 0);
}
bool flag = false;
void dfs(int sr,int sc)
{
    if(grid[sr][sc]=='B')
    {
        flag = true;
    }
    vis[sr][sc] = true;
    for (int i = 0; i < 4;i++)
    {
        int ci = sr + dif[i].first;
        int cj = sc + dif[i].second;
        if(isValid(ci,cj) && !vis[ci][cj] && grid[ci][cj])
        {
            if(i==0)
                texts.push_back('R');
            else if(i==1)
                texts.push_back('L');
            else if(i==2)
                texts.push_back('D');
            else if(i==3)
                texts.push_back('U');
            steps++;
            vis[ci][cj] = true;
            dfs(ci, cj);
        }
    }

}
int main()
{
    memset(vis,false,sizeof(vis));
    cin >> r >> c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]=='A')
            {
                dfs(i,j);
            }
        }
    }
    if(flag==true)
    {
        cout << "YES" << endl;
        cout << steps << endl;
        for (char i : texts)
        {
            cout << i;
        }
    }

        return 0;
}