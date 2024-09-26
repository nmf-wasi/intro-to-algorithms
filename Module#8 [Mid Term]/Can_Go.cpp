#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>>Lia[1005];
long long int costArray[1005];
class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(long long int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> Yuna;
    Yuna.push({src, 0});
    costArray[src] = 0;
    while(!Yuna.empty())
    {
        pair<long long int, long long int> parent = Yuna.top();
        Yuna.pop();
        long long int node=parent.first;
        long long int cost=parent.second;
        for (pair<long long int, long long int> child : Lia[node])
        {
            long long int childNode = child.first;
            long long int childCost = child.second;
            if (cost + childCost < costArray[childNode])
            {
                costArray[childNode] = cost + childCost;
                Yuna.push({childNode, costArray[childNode]});
            }
        }
    }
}
int main()
{
    long long int node,edge;
    cin>>node>>edge;
    for (long long int i = 1; i <= node; i++)
    {
        costArray[i] = INT_MAX;
    }
    while(edge--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        Lia[a].push_back({b, c});
        // Lia[b].push_back({a, c});
    }
    long long int x;
    cin >> x;
    dijkstra(x);
    long long int testcase;
    cin >> testcase;
    for (long long int t = 0; t < testcase;t++)
    {
        long long int node, cost;
        cin >> node >> cost;
        if(node==x)
        {
            cout << "YES" << "\n";
            continue;
        }
        if (costArray[node] != INT_MAX && costArray[node] <= cost)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
        return 0;
}