#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
int level[N];
void dsu_initialize(int N)
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find_leader(int node)
{
    if (parent[node] == -1)
        return node;
    return dsu_find_leader(parent[node]);
}
void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find_leader(node1);
    int leaderB = dsu_find_leader(node2);
    parent[leaderA] = leaderB;
}
void dsu_union_by_size(int node1, int node2)
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
void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find_leader(node1);
    int leaderB = dsu_find_leader(node2);
    if (level[leaderA] > level[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderB] = leaderA;
        level[leaderA]++;
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    dsu_initialize(node);
    while(edge--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find_leader(a);
        int leaderB = dsu_find_leader(b);
        if(leaderA!=leaderB)
        {
            dsu_union_by_size(a, b);
        }
    }
    vector<int> leader;
    for (int i = 0; i < node;i++)
    {
        leader.push_back(dsu_find_leader(i));
    }
    sort(leader.begin(), leader.end());
    leader.erase(unique(leader.begin(), leader.end()),leader.end());
    cout << leader.size()-1;
    for (int i = 0; i < leader.size() - 1;i++)
    {
        cout << leader[i] << " " << leader[i + 1] << endl;
    }
        return 0;
}