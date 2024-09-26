#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> Lia[1005];
long long int costArray[1005];
class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
vector<Edge> edgeList;
int main()
{
    long long int node, edge;
    cin >> node >> edge;
    for (long long int i = 1; i <= node; i++)
    {
        costArray[i] = INT_MAX;
    }
    while (edge--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
        // Lia[b].push_back({a, c});
    }
    long long int x;
    cin >> x;
    // dijkstra(x);
    costArray[x] = 0;
    for (int i = 1; i <= node - 1; i++)
    {
        for (Edge ed : edgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (costArray[u] < INT_MAX && costArray[u] + c < costArray[v])
            {
                costArray[v] = costArray[u] + c;
            }
        }
    }
    for (Edge ed : edgeList)
    {
        long long int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (costArray[u] < INT_MAX && costArray[u] + c < costArray[v])
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }
    long long int testcase;
    cin >> testcase;
    for (int t = 0; t < testcase; t++)
    {
        long long int node;
        cin >> node;
        if (costArray[node] != INT_MAX)
        {
            cout << costArray[node] << "\n";
            continue;
        }
        else
        {
            cout << "Not Possible" << "\n";
            continue;
        }
    }
    return 0;
}