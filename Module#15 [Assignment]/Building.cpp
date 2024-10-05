#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int group_size[N];
int componenet = 0;
void dsu_initialize(int N)
{
    for(int i=1;i<=N;i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
        componenet++;
    }
}
int dsu_find_leader(int node)
{
    if(parent[node]==-1)
        return node;
    return dsu_find_leader(parent[node]);
}
void dsu_union(int node1 , int node2)
{
    int leaderA = dsu_find_leader(node1);
    int leaderB = dsu_find_leader(node2);
    parent[leaderA] = leaderB;
}
void dsu_union_by_size(int node1 , int node2)
{
    int leaderA = dsu_find_leader(node1);
    int leaderB = dsu_find_leader(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }

}
class Edge
{
    public:
        int u,v;
        long long int w;
        Edge(int u, int v, long long int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
bool cmp(Edge a, Edge b)
{
    return (a.w < b.w);
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    dsu_initialize(node);
    vector<Edge> edgeList;
    while(edge--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back(Edge(u, v, w));
    }
    long long int totalCost = 0;
    sort(edgeList.begin(), edgeList.end(), cmp);
    for(Edge ed:edgeList)
    {
        int leaderU = dsu_find_leader(ed.u);
        int leaderV = dsu_find_leader(ed.v);
        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
            componenet--;
        }
    }
    if(componenet==1)
        cout << totalCost << endl;
    else
        cout << -1 << endl;
    return 0;
}