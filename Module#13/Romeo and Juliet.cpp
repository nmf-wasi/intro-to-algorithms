#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adjacencyList[N];
bool visitArray[N];
int distanceArray[N];
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visitArray[src] = true;
    distanceArray[src] = 0;
    while(!Yuna.empty())
    {
        int parent=Yuna.front();
        Yuna.pop();
        for(int child :adjacencyList[parent])
        {
            if(!visitArray[child])
            {
                visitArray[child] = true;
                Yuna.push(child);
                distanceArray[child] = distanceArray[parent] + 1;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    memset(visitArray, false, sizeof(visitArray));
    memset(distanceArray, -1, sizeof(distanceArray));
    int src, des, k;
    cin >> src >> des >> k;
    bfs(src);
    if(distanceArray[des]!=-1 && distanceArray[des]<=k*2)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
    return 0;
}