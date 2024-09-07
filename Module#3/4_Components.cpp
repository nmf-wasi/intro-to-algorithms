#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>Lia[N];
bool visitArray[N];
void dfs (int src)
{
    cout<<src<<" ";
    visitArray[src] = true;
    // for (int i = 0; i < Lia[src].size();i++)
    // {
    //     int child = Lia[src][i];
    //     if (visitArray[child] == false)
    //     {
    //         dfs(child);
    //     }
    // }
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
    int component = 0;
    for (int i = 0; i < node; i++)
    {
        if (!visitArray[i])
        {
            component++;
            dfs(i);
        }
    }

    cout << endl
         << "Component: " << component << endl;
    return 0;
}