#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
void dsu_initialize(int N)
{
    for(int i=0;i<N;i++)
    {
        parent[i] = -1;
    }
    parent[1]=2;
    parent[2]=3;
    parent[5]=6;
    parent[6]=7;
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
int main()
{
    dsu_initialize(8);
    cout << dsu_find_leader(0) << endl;
    cout << dsu_find_leader(1) << endl;
    cout << dsu_find_leader(2) << endl;
    cout << dsu_find_leader(3) << endl;
    cout << dsu_find_leader(5) << endl;
    cout << dsu_find_leader(6) << endl;
    cout << dsu_find_leader(7) << endl;
    dsu_union(1, 5);
    cout << dsu_find_leader(0) << endl;
    cout << dsu_find_leader(1) << endl;
    cout << dsu_find_leader(2) << endl;
    cout << dsu_find_leader(3) << endl;
    cout << dsu_find_leader(5) << endl;
    cout << dsu_find_leader(6) << endl;
    cout << dsu_find_leader(7) << endl;
    return 0;
}