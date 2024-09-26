#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u,v,c;
        Edge(int u, int v, int c)
        {
            this->u=u;
            this->v=v;
            this->c=c;
        }
};
const int N=1e5+5;
int distanceArray[N];
int main()
{
    int node,edge;
    vector<Edge>EdgeList;
    cin>>node>>edge;
    while(edge--)
    {
        int u,v,c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u,v,c));
                EdgeList.push_back(Edge(v,u,c));     //for undirected graph

    }
    for(int i=0;i<node;i++)
    {
        distanceArray[i] = INT_MAX;
    }
    distanceArray[0] = 0;
    for (int i = 1; i < node-1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (distanceArray[u] < INT_MAX && distanceArray[u] + c < distanceArray[v])
            {
                distanceArray[v] = distanceArray[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (distanceArray[u] < INT_MAX && distanceArray[u] + c < distanceArray[v])
            {
                cycle=true;
                break;
            }
        }
    if(cycle)
        cout << "CYCLE FOUND, No answer possible";
    else
    {
        for (int i = 0; i < node;i++)
        {
            cout << i << " -> " << distanceArray[i] << endl;
        }
    }
        return 0;
}