#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adjacencyList[N];
bool visitArray[N];
int parentArray[N];
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visitArray[src] = true;
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
    memset(parentArray, -1, sizeof(parentArray));
    bfs(1);
    int x = n;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parentArray[x];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(), path.end());
        if(path.size()==1)
            cout<<"IMPOSSIBLE"<<endl;
        else   
        {
            cout << path.size() << endl;
            for(int val:path)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    return 0;
}