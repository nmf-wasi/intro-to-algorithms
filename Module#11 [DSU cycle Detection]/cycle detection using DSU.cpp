#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int group_sz[N];
void dsu_initialize(int n)
{
    for(int i=0;i<n;i++)
    {
      parent[i]  =-1;
      group_sz[i]=1;
    }
}
int dsu_find_leader(int node)
{
    if(parent[node]==-1) return node;
    int leader = dsu_find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_by_size(int node1, int node2)
{
    int leader1=dsu_find_leader(node1);
    int leader2=dsu_find_leader(node2);
    if (group_sz[leader1] > group_sz[leader2])
    {
        parent[leader2] = leader1;
        group_sz[leader1] += group_sz[leader2];
    }
    if (group_sz[leader1] > group_sz[leader2])
    {
        parent[leader1] = leader2;
        group_sz[leader2] += group_sz[leader1];
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    dsu_initialize(n);
    bool cycle = false;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA=dsu_find_leader(a);
        int leaderB=dsu_find_leader(b);
        if(leaderA==leaderB)
        {
            cycle=true;
            // dont use break!!
            // we are taking inputs, if we break input, it will not work properly
        }
        else
        {
            union_by_size(a, b);
        }
    }
    if(cycle)
        cout<<"CYCLE FOUND!"<<endl;
    else
        cout << "NO CYCLE DETECTED" << endl;
    return 0;
}