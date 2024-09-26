#include <bits/stdc++.h>
using namespace std;
char Lia[10005][10005];
int knight_row, knight_col;
int queen_row, queen_col;
bool visitArray[10005][10005];
int r, c;
vector<pair<int, int>> difference = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {-2, 1}, {2, -1}, {-1, 2}, {1, -2}};
bool ans = false;
bool valid(int childRow, int childCol)
{
    if (childRow < 0 || childRow >= r || childCol < 0 || childCol >= c)
        return false;
    return true;
}
int bfs(int knight_row, int knight_col)
{
    queue<pair<pair<int, int>, int>> Yuna;
    Yuna.push({{knight_row, knight_col}, 0});
    while (!Yuna.empty())
    {
        pair<pair<int, int>, int> parent = Yuna.front();
        int parentRow = parent.first.first;
        int parentCol = parent.first.second;
        int steps = parent.second;
        Yuna.pop();
        for (int i = 0; i < 8; i++)
        {
            int childRow = parentRow + difference[i].first;
            int childCol = parentCol + difference[i].second;
            if (valid(childRow, childCol) == true && visitArray[childRow][childCol] == false)
            {
                if (childRow == queen_row && childCol == queen_col)
                {
                    ans = true;
                    return steps + 1;
                }
                Yuna.push({{childRow, childCol}, steps + 1});
                visitArray[childRow][childCol] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(visitArray, false, sizeof(visitArray));
        cin >> r >> c;
        cin >> knight_row >> knight_col;
        cin >> queen_row >> queen_col;
        if (knight_row == queen_row && knight_col == queen_col)
        {
            cout << "0" << endl;
            continue;
        }
            int ans = bfs(knight_row, knight_col);
        cout << ans << endl;
    }

    return 0;
}