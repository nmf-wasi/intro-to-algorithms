#include <bits/stdc++.h>
using namespace std;
int row, col;
char Lia[1005][1005];
bool visitArray[1005][1005];
vector<pair<int, int>> differeceForTraversal = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int cr, int cc)
{
    if (cr < 0 || cr >= row || cc < 0 || cc >= col)
        return false;
    else
        return true;
}

int dfsToFindApt(int start_row, int start_col)
{
    if (Lia[start_row][start_col] == '#')
        return 0;
    // cout << Lia[start_row][start_col] << " ";
    visitArray[start_row][start_col] = true;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        int cr = start_row + differeceForTraversal[i].first;
        int cc = start_col + differeceForTraversal[i].second;
        if (isValid(cr, cc) && !visitArray[cr][cc] && Lia[cr][cc] != '#')
            count += dfsToFindApt(cr, cc);
    }
    return count;
}
int main()
{
    cin >> row >> col;
    bool isHash = false;
    memset(visitArray, false, sizeof(visitArray));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> Lia[i][j];
            if (Lia[i][j] == '.')
                isHash = true;
        }
    }
    vector<int> ajaira;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (Lia[i][j] == '.' && !visitArray[i][j])
            {
                int count = dfsToFindApt(i, j);
                ajaira.push_back(count);
            }
        }
    }
    if (!isHash)
    {
        cout << "0";
        return 0;
    }
    sort(ajaira.begin(), ajaira.end());
    for (int x : ajaira)
    {
        cout << x << " ";
    }
    return 0;
}