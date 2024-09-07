#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1001];
// check from question what will be the size
bool visit_array[1001];
int level[1001];
int prnt[1001];
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visit_array[src] = true;
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        Yuna.pop();
        level[src] = 0;
        // ber korlam

        cout << parent << " ";
        cout << "Level: " << level[parent] << endl;
        
        // kaj korlam
        for (int child : Lia[parent])
        {
            if (visit_array[child] == false)
            {
                Yuna.push(child);
                visit_array[child] = true;
                level[child]=level[parent]+1;
                prnt[child] = parent;
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
    int src,destination;
    cin >> src>>destination;
    memset(visit_array, false, sizeof(visit_array));
    memset(level, -1, sizeof(level));
    memset(prnt, -1, sizeof(prnt));
    bfs(src);
    int x=destination;
    vector<int> path;
    while(x!=-1)
    {
        path.push_back(x);
        x = prnt[x];
    }
    reverse(path.begin(),path.end());
    for(int val:path)
    {
        cout << val << " ";
    }
        return 0;
}