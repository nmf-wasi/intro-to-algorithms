#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >>edge;
    vector<pair<int, int>> Lia;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        // Lia.push_back(make_pair(a, b));
        Lia.push_back({a,b});
    }
    for (int i = 0; i < Lia.size();i++)
    {
        // cout << Lia[i] << " ";//error Lia[i] is a pair and we cant print pair

        cout << Lia[i].first << " " << Lia[i].second <<endl;
    }
    cout << endl;
    for(pair<int,int> p :Lia)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    for(auto p :Lia)
    {
        cout << p.first << " " << p.second << endl;
    }

        return 0;
}