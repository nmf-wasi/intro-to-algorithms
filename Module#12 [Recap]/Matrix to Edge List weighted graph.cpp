#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u,v,w;
        Edge(int u,int v,int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
int main()
{
    int node,edge;
    cin >> node >> edge;
    int mat[node][node];
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            cin >> mat [i][j];
        }
    }
    vector<Edge> edgeList;
    for (int i = 0; i < node;i++)
    {
        for (int j = 0; j < node;j++)
        {
            if(mat[i][j]>0)
            {
                edgeList.push_back(Edge(i,j,mat[i][j]));
            }
        }
    }
    for(Edge ed:edgeList)
    {
        cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }
        return 0;
}