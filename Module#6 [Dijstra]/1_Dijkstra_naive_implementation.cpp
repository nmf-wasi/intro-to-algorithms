#include <bits/stdc++.h>
using namespace std;
const int N=100+5;
vector<pair<int, int>> adjacencyList[N];
int distanceArray[N];
void dijkstra(int src)
{
    queue<pair<int,int>>Yuna;
    Yuna.push({src,0});
    distanceArray[src] = 0;
    while(!Yuna.empty())
    {
        pair<int,int>parent=Yuna.front();
        Yuna.pop();
        int parentValue=parent.first;
        int parentCost = parent.second;
        // for (int i = 0; i < sizeof(adjacencyList[parentValue]);i++)
        // {
        //     pair<int, int> child = adjacencyList[parentValue][i];
        // }

        for(pair<int,int> child:adjacencyList[parentValue])
        {
            int childValue=child.first;
            int childCost = child.second;
            if (parentCost + childCost < distanceArray[childValue])
            {
                // path relax
                distanceArray[childValue] = parentCost + childCost;
                Yuna.push({childValue, parentCost + childCost});
                // //for safety
                // even if You accidentally push the cost and node first, it will work
                // if you push childValue & distanceArray[childValue] 
                // before writing distanceArray[childValue] = parentCost + childCost it wouldn't work
            }
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adjacencyList[a].push_back({b,c});
        adjacencyList[b].push_back({a,c});
    }
    // memset(distanceArray,INT_MAX,sizeof(distanceArray));
    // memset dont work properly with large values
    for (int i = 0; i < node;i++)
    {
        distanceArray[i] = INT_MAX;
    }
    int src;
    cin>>src;
    dijkstra(src);
    for (int i = 0; i < node;i++)
    {
        cout << i << " ->" << distanceArray[i] << endl;
    }
        return 0;
}