#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adjacencyList[N];
bool visitArray[N];
int distanceArray[N];
int parentArray[N];
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
                parentArray[child] = parent;
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
    memset(parentArray, -1, sizeof(parentArray));
    bfs(1);
    if(distanceArray[n]==-1)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        int x = n;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parentArray[x];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(), path.end());
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}