#include <bits/stdc++.h>
using namespace std;
vector<int> Lia[1005];

int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int q;
    cin >> q;
    // memset(Lia, -1, sizeof(Lia));
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        if(Lia[x].empty())
            cout << "-1" << endl;
        else
        {
            sort(Lia[x].begin(), Lia[x].end(), greater<int>());
            for(int output:Lia[x])
            {
                cout << output << " ";
            }
            cout << endl;
        }
    }
    return 0;
}