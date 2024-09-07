//we will be keeping levvel of the nodes as pair with the node in the BFS func queue



#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1001];
int visitArray[1001];
void bfs_LevelTracking_as_Pair(int source)
{
    queue<pair<int,int>>Yuna;//one int for number and another for the level
    Yuna.push({source,0});
    visitArray[source] = true;
    while(!Yuna.empty())
    {
        pair<int,int> parent = Yuna.front();
        int parent_value = parent.first;
        int parent_level = parent.second;
        Yuna.pop();
        // ber korlam

        cout << parent_value << " Level : " << parent_level << endl;
        //kaj sesh

        for (int child : Lia[parent_value])
        {
            if(!visitArray[child])
            {
                Yuna.push({child, parent_level + 1});
                visitArray[child] = true;
            }
        }
    }
}
int main()
{
    int node,edge;
    cin >> node >> edge;
    while(edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int src;
    cin>>src;
    memset(visitArray, false, sizeof(visitArray));
    bfs_LevelTracking_as_Pair(src);
    return 0;
}