#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin >> edge >> edge;
    vector<pair<int, int>> Lia;
    while(edge--)
    {
        int a, b;
        cin >> a >> b;
        Lia.push_back({a, b});
    }
    for (int i = 0; i < Lia.size(); i++)
    {
        cout << Lia[i].first << " " << Lia[i].second << endl;
    }
    cout << endl;
    for (pair<int, int> p : Lia)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    for (auto p : Lia)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}