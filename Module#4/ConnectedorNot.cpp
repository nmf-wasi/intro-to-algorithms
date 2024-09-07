#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1005];
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia[a].push_back(b);
    }

    int querry;
    cin >> querry;
    for (int i = 0; i < querry; i++)
    {
        int a, b;
        bool found = false;
        cin >> a >> b;
        if(a!=b)
        {
            for (int i = 0; i < Lia[a].size(); i++)
            {
                if (Lia[a][i] == b)
                {
                    found = true;
                    break;
                }
            }
            if (found == true)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}