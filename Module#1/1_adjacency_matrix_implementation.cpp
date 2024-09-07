#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    int Lia[node][node];
    memset(Lia, 0, sizeof(Lia));
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia[a][b] = 1;
        Lia[b][a] = 1;
    }

    
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << Lia[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}