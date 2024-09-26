// sometimes we might need a matrix to find result of a problem but we might be given adjacency list , here's how to convert them 
#include <bits/stdc++.h>
using namespace std;
void convert(int node, vector<int>adj[])//like you get on leet code
{
    int mat[node][node];
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            mat[i][j]=0;
            if(i==j)
            {
                mat[i][j] = 1;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < node;i++)
    {
        for(int child:adj[i])
        {
            mat[i][child] = 1;
        }
    }
    // to check result
    for (int i = 0; i < node;i++)
    {
        for (int j = 0; j < node;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    vector<int>adjacencyList[node];
    while(edge--)
    {
        int a,b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    convert(node,adjacencyList);
    return 0;
}