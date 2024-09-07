#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1001];
// check from question what will be the size
bool visit_array[1001];
int level[1001];
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visit_array[src] = true;
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        level[src] = 0;
        Yuna.pop();
        
        // ber korlam

        cout << parent << " ";
        cout << "Level: " << level[parent] << endl;
        
        // kaj korlam
        //  for (int i = 0; i < Lia[parent].size();i++)
        //  {
        //      int child = Lia[parent][i];
        //      cout << child << " ";
        //  }
        for (int child : Lia[parent])
        {
            if (visit_array[child] == false)
            {
                Yuna.push(child);
                visit_array[child] = true;
                level[child]=level[parent]+1;
            }
        }
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
    memset(visit_array, false, sizeof(visit_array));
    // suppose there are nodes which aren't connected with anyother nodes. Then we can't access them using level order and their level will be shown a garbage value. therefore, we should set all levels to -1 at first so that we can find out from the outhputs which are on level -1, and those nodes are separated from others
    memset(level, -1, sizeof(level));
    bfs(src);
    for (int i = 0; i < node;i++)
    {
        cout << i << " " << level[i] << endl;
    }
        return 0;
}