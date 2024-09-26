#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
using namespace std;
const int N=1e5+5;
vector<pi>adjacencyList[N];
ll distanceArray[N];
ll parentArray[N];

class cmp
{
    public:
        bool operator()(pi a, pi b)
        {
            return (a.second > b.second);
        }
};

void dijstra(ll src)
{
    priority_queue<pi, vector<pi>, cmp> Yuna;
    Yuna.push({src, 0});
    distanceArray[src] = 0;
    while(!Yuna.empty())
    {
        pi parent = Yuna.top();
        Yuna.pop();
        ll parentNode = parent.first;
        ll parentCost = parent.second;
        for (pi child : adjacencyList[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if((parentCost+childCost)<distanceArray[childNode])
            {
                distanceArray[childNode] = parentCost + childCost;
                Yuna.push({childNode, distanceArray[childNode]});
                parentArray[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    ll node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adjacencyList[a].push_back({b, c});
        adjacencyList[b].push_back({a, c});
    }
    for (int i = 0; i < node;i++)
    {
        parentArray[i] = -1;
        distanceArray[i] = 1e18;
    }
    
    dijstra(1);
    if(distanceArray[node]==1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        ll x = node;
        vector<ll> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parentArray[x];
        }
        reverse(path.begin(), path.end());
        for (ll val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}