#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<int> Lia[node];
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int x;
    cin >> x;
    for (int i = 0; i < Lia[x].size(); i++)
    {
        cout << Lia[x][i] << " ";
    }
    return 0;
}