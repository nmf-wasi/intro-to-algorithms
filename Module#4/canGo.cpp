#include <bits/stdc++.h>
using namespace std;
int row, col;
char Lia[1005][1005];
bool visitArray[1005][1005];
vector<pair<int, int>> differeceForTraversal = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int child_row, int child_col)
{
    if (child_row < 0 || child_row >= row || child_col < 0 || child_col >= col)
        return false;
    else
        return true;
}
bool dfsConnection(int start_row, int start_col)
{
    if (Lia[start_row][start_col] == 'B')
        return true;
    visitArray[start_row][start_col] = true;
    for (int i = 0; i < 4; i++) // 4dikei jawa jabe
    {
        int child_row = start_row + differeceForTraversal[i].first;
        int child_col = start_col + differeceForTraversal[i].second;
        if (isValid(child_row, child_col) && !visitArray[child_row][child_col] && Lia[child_row][child_col] != '#')
        {
            if (dfsConnection(child_row, child_col))
                return true;
        }
    }
    return false;
}

int main()
{

    cin >> row >> col;
    int start_row = -1;
    int start_col = -1;
    int end_row = -1;
    int end_col = -1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> Lia[i][j];
            if (Lia[i][j] == 'A')
            {
                start_row = i;
                start_col = j;
            }
            else if (Lia[i][j] == 'B')
            {
                end_row = i;
                end_col = j;
            }
        }
    }
    if (start_row == -1 || start_col == -1 || end_row == -1 || end_col == -1)
    {
        cout << "NO" << endl;
        return 0;
    }
        memset(visitArray, false, sizeof(visitArray));
    if (dfsConnection(start_row, start_col))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}