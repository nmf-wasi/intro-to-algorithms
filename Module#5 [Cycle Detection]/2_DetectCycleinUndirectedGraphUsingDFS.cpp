#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adjacencyList[N];
bool visitArray[N];
int parentArray[N];
bool ans = false;
void dfs(int parent)
{
    visitArray[parent]=true;
    for(int child:adjacencyList[parent])
    {
        if(visitArray[child]=true && parentArray[child]!=child)
            ans = true;
        if(!visitArray[child])
        {
            parentArray[child]=parent;
            dfs(child);
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    memset(visitArray, false, sizeof(visitArray));
    memset(parentArray, -1, sizeof(parentArray));
    for (int i = 0; i < node;i++)
    {
        if(!visitArray[i])
            dfs(i);
    }
    if (ans)
        cout << "Cycle Detected";
    else
        cout << "NO Cycle Found";
    return 0;
}