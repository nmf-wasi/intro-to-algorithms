//find the shortest distance of a node from source
#include <bits/stdc++.h>
using namespace std;
char Lia[20][20];//2d array
bool visitArray[20][20];
int distanceArray[20][20];
vector<pair<int, int>> difference_for_traversal = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int row, col;
bool isValid(int child_row, int child_col)
{
    if (child_row < 0 || child_row >= row || child_col < 0 || child_col >= col)
        return false;
    else
        return true;
}
void bfsOn2D(int src_row, int src_col)
{
    queue<pair<int,int>>Yuna;
    Yuna.push({src_row, src_col});
    visitArray[src_row][src_col] = true;
    distanceArray[src_row][src_col] = 0;
    while(!Yuna.empty())
    {
        int parent_row = Yuna.front().first;
        int parent_col = Yuna.front().second;
        Yuna.pop();

        //cout << "parent's row " << parent_row << " " << "parent's col " << parent_col << endl;

        for(int i=0;i<4;i++)
        {
            int child_row = parent_row + difference_for_traversal[i].first;
            int child_col = parent_col + difference_for_traversal[i].second;
            if(isValid(child_row,child_col)==true && visitArray[child_row][child_col]==false)
            {
                Yuna.push({child_row, child_col});
                visitArray[child_row][child_col] = true;
                distanceArray[child_row][child_col] = distanceArray[parent_row][parent_col] + 1;
            }
        }
        
    }
}
int main()
{
    cin >>row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> Lia[i][j];
        }
    }
    
    int source_row, source_col;
    cin >> source_row >> source_col;
    memset(visitArray, false, sizeof(visitArray));
    memset(distanceArray, -1, sizeof(distanceArray));
    bfsOn2D(source_row, source_col);

    //check distance of a node from src

    int x,y;
    cin>>x>>y;
    cout<<distanceArray[x][y]<<endl;

    
    return 0;
}