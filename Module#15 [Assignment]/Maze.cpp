#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parentTrack[1005][1005];
int row, col, si, sj, di, dj;

bool isValid(int childRow, int childCol)
{
    return (childRow >= 0 && childRow < row && childCol >= 0 && childCol < col);
}

bool flag = false;
vector<pair<int, int>> dif = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int si, int sj)
{
    vis[si][sj] = true;
    queue<pair<int, int>> Yuna;
    Yuna.push({si, sj});

    while (!Yuna.empty())
    {
        pair<int, int> parent = Yuna.front();
        int pi = parent.first;
        int pj = parent.second;
        Yuna.pop();

        for (int i = 0; i < 4; i++)
        {
            int childRow = pi + dif[i].first;
            int childCol = pj + dif[i].second;

            if (childRow == di && childCol == dj)
            {
                parentTrack[di][dj] = {pi, pj};
                flag = true;
                return;
            }

            if (isValid(childRow, childCol) && !vis[childRow][childCol] && grid[childRow][childCol] != '#')
            {
                Yuna.push({childRow, childCol});
                vis[childRow][childCol] = true;
                parentTrack[childRow][childCol] = {pi, pj};
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(parentTrack, -1, sizeof(parentTrack));

    bfs(si, sj);

    if (flag)
    {
        int r1 = di;
        int c1 = dj;
        while (r1 != si || c1 != sj)
        {
            grid[r1][c1] = 'X';
            pair<int, int> par = parentTrack[r1][c1];
            r1 = par.first;
            c1 = par.second;
        }
        grid[si][sj] = 'X';
    }
    grid[si][sj] = 'R';
    grid[di][dj] = 'D';
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
