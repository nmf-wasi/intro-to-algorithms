//bfs works on the shortest way possible
// using bfs, one can get the shortest path from one node to another. 
// on the other hand, dfs just traverse through each nodes. 
// for shortest path, use BFS and for normal works, use dfs, dfs implementation is wayy easier than bfs
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>Lia[N];
bool visitArray[N];
void dfs (int src)
{
    cout<<src<<" ";
    visitArray[src] = true;
    for (int child: Lia[src])
    {
        if (visitArray[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while(edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    memset(visitArray, false, sizeof(visitArray));

    dfs(0);
    //asuming that source is 0
    return 0;
}