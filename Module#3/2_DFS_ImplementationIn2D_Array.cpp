// in 2d array, instead of giving the edges[connections between nodes] we will be given a whole matrix and instead of a source, we will be given the row and collum of the source
// then, we have to use 2D array's i & j to find other nodes from it
// to go up add -1 with i and 0 with j
// to go down add 1 with i and 0 with j
// to go left add 0 with i and -1 with j
// to go right add 0 with i and 1 with j
#include <bits/stdc++.h>
using namespace std;
int row, col;
//declairingin ow and collum globally so that we dont have to apss these on every function while working
// char array [row][col];
//instead of having variable, just declare a size
char Lia[20][20];
bool visitArray[20][20];
vector<pair<int, int>> difference_for_traversal = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid_index(int child_row, int child_col)
{
    if(child_row < 0 || child_row >=row || child_col < 0 || child_col >= col)
        return false;
    else
        return true;
}

void dfs_for_2d(int source_row, int source_col)
{

    cout << source_row <<" "<< source_col << endl;
    visitArray[source_row][source_col] = true; 
    for(int i=0;i<4;i++)
    {
        int child_row = source_row + difference_for_traversal[i].first;
        int child_col = source_col + difference_for_traversal[i].second;
        if(valid_index(child_row,child_col)==true && visitArray[child_row][child_col])
        {
            dfs_for_2d(child_row, child_col);
        }
    }

}
int main()
{

    cin >> row >>col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col;j++)
        {
            cin >> Lia[i][j];
        }
    }
    int source_row, source_col;
    cin >> source_row >> source_col;
    dfs_for_2d(source_row, source_col);
    return 0;
}