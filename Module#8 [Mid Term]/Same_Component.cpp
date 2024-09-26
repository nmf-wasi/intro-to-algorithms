#include <bits/stdc++.h>
using namespace std;
char Lia[10005][10005];
int src_row, src_col;
int des_row, des_col;
bool visitArray[10005][10005];
int r,c;
vector<pair<int, int>> difference = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool ans=false;
bool valid(int childRow, int childCol)
{
    if (childRow < 0 || childRow >= r || childCol < 0 || childCol >= c)
        return false;
    return true;
}
void bfs(int src_row, int src_col)
{
    queue<pair<int,int>>Yuna;
    Yuna.push({src_row,src_col});
    while(!Yuna.empty())
    {
            pair<int,int>parent=Yuna.front();
            int parentRow = parent.first;
            int parentCol = parent.second;
            Yuna.pop();
            for (int i = 0; i < 4; i++)
            {
                int childRow = parentRow + difference[i].first;
                int childCol = parentCol + difference[i].second;
                if (valid(childRow, childCol) == true && visitArray[childRow][childCol] == false && Lia[childRow][childCol]=='.')
                {
                    if (childRow == des_row && childCol == des_col)
                    {
                        ans = true;
                    }
                    Yuna.push({childRow, childCol});
                    visitArray[childRow][childCol] = true;
                }
            }
    }
}

int main()
{

    cin>>r>>c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> Lia[i][j];
        }
    }
    memset(visitArray, false, sizeof(visitArray));
    
    cin >> src_row >> src_col;
    cin >> des_row >> des_col;
    bfs(src_row, src_col);
    if(ans)
        cout<<"YES"<<endl;
    else
        cout << "NO" << endl;
    return 0;
}