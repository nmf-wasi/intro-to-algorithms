#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin>>node>>edge;
    vector<int> mat[node];
    while(edge--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int x;
    cin>>x;
    for (int i = 0; i < mat[x].size();i++) 
    //iterate on the array's x index's vector to find what values are stored there
    {
        cout << mat[x][i] << " ";;
    }
        return 0;
}