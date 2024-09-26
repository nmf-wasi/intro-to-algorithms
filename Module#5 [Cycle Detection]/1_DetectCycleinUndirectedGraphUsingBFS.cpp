#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adjacencyList[N];
bool visitArray[N];
int parentArray[N];
bool cycle = false;
void bfs(int src)
{
    queue<int> Yuna;
    Yuna.push(src);
    visitArray[src] = true;
    while(!Yuna.empty())
    {
        int parent=Yuna.front();
        Yuna.pop();
        //ber kora done
        cout<<parent<<" ";
        // kaj done
        for (int child : adjacencyList[parent])
        {
            if(visitArray[child] && parentArray[parent]!=child)
            {
                cycle=true;
            }
            if(!visitArray[child])
            {
                Yuna.push(child);
                visitArray[child] = true;
                parentArray[child] = parent;
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
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    memset(visitArray, false, sizeof(visitArray));
    memset(parentArray, -1, sizeof(parentArray));
    for (int i = 0; i < node;i++)
    {
        if(!visitArray[i])
            bfs(i);
    }
    if(cycle)
        cout << "CYCLE DETECTED!" << endl;
    else
        cout << "NO CYCLE FOUND!" << endl;
        return 0;
}