//we will be given a source node and a destination node, we have to print the path using that
//usually bfs gives the shortest path, so no need to worry if it's shortest or not

#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1005];
bool visitArray[1005];
int level[1005];
int parentofThisNode[1005];

void bfsPathPrinting(int source)
{
    queue<int>Yuna;
    Yuna.push(source);
    while(!Yuna.empty())
    {
        int parent = Yuna.front();
        Yuna.pop();
        visitArray[parent] = true;
        // ber korlam

        //kaj nai kono

        ///child rakhi
        for(int child:Lia[parent])
        {
            if (!visitArray[child])
            {
                Yuna.push(child);
                visitArray[child] = true;
                level[child] = level[parent] + 1;
                parentofThisNode[child] = parent;
            }
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int source,destination;
    cin>>source>>destination;
    memset(visitArray, false, sizeof(visitArray));
    memset(level, -1, sizeof(level));
    memset(parentofThisNode, -1, sizeof(parentofThisNode));
    bfsPathPrinting(source);
    int x = destination;
    vector<int> path;
    while(x!=-1)
    {
        path.push_back(x);
        x = parentofThisNode[x];
    }
    reverse(path.begin(),path.end());
    for(int i:path)
    {
        cout << i << " ";
    }
        return 0;
}