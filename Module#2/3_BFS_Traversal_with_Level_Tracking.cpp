#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1001];
bool visitArray[1001];
int levelArray[1001];

void bfs_level_tracking(int source)
{
    queue<int> Yuna;
    Yuna.push(source);
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        levelArray[source] = 0;
        Yuna.pop();
        // ber kora sesh

        cout << parent << " " << "level :" << levelArray[parent] << endl;
        // kaj sesh

        // for (int i = 0; i < Lia[parent].size(); i++)
        // {
        //     int child = Lia[parent][i];
        //     if(!visitArray[child])
        //     {
        //         Yuna.push(child);
        //         visitArray[child] = true;
        //         levelArray[child] = levelArray[parent] + 1;
        //     }
        // }

        for(int child:Lia[parent])
        {
            if(!visitArray[child])
            {
                Yuna.push(child);
                visitArray[child] = true;
                levelArray[child] = levelArray[parent] + 1;
            }
        }
        //children rakha sesh
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(visitArray, false, sizeof(visitArray));
    memset(levelArray, -1, sizeof(levelArray));
    // if output shows level -1 means, it's not connected
    //  suppose there are nodes which aren't connected with anyother nodes. Then we can't access them using level order and their level will be shown a garbage value. therefore, we should set all levels to -1 at first so that we can find out from the outhputs which are on level -1, and those nodes are separated from others
    bfs_level_tracking(src);
    return 0;
}