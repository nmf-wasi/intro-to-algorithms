#include <bits/stdc++.h>
using namespace std;
const long long int llg = 1e18;
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<vector<long long int>> Lia(n + 1, vector<long long int>(n + 1, llg));
    // vector module calss 2, initialize vector of N size and each eleemtns will be K
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Lia[i][j] = llg;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        Lia[i][i] = 0;
    }

    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        Lia[u][v] = min(Lia[u][v], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (Lia[i][k] != llg && Lia[k][j] != llg)
                {
                    Lia[i][j] = min(Lia[i][j], Lia[i][k] + Lia[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        long long int s, e;
        cin >> s >> e;
        if (Lia[s][e] == llg)
            cout << "-1\n";
        else
            cout << Lia[s][e] << "\n";
    }

    return 0;
}