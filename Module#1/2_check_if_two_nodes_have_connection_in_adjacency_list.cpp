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

    
    int con_a,con_b;
    cin >> con_a >> con_b;
    if (Lia[con_a][con_b] == 1)
        cout << "connection ache" << endl;
    else
        cout << "connection nai" << endl;
    return 0;
}