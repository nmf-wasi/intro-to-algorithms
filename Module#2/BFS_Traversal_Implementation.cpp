#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1001];
// check from question what will be the size
bool visit_array[1001];
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visit_array[src] = true;
    while (!Yuna.empty())
    {
        int parent = Yuna.front();
        Yuna.pop();
        // ber korlam

        cout << parent << endl;
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
    bfs(src);
    return 0;
}