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
    cin>>node>>edge;
    cin>>node>>edge;
    vector<pair<int, int>> adjacencyList[node];
    while(edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjacencyList[a].push_back({b, c});
        // adjacencyList[b].push_back({a, c});
    }
    vector<Edge> EdgeList;
    for(int i=0;i<node;i++)
    {
        for(pair<int, int> child: adjacencyList[i])
        {
            int childNode=child.first;
            int childCost=child.second;
            EdgeList.push_back(Edge(i, childNode, childCost));
        }
    }
    for (Edge ed : EdgeList)
    {
        cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }
    return 0;
}