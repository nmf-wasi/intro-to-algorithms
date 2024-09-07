#include <bits/stdc++.h>
using namespace std;
vector<int>Lia[1005];
int levelArray[1005];
bool visitArray[1005];
void findDestination(int source,int destination)
{
    queue<int>Yuna;
    Yuna.push(source);
    bool found=false;
    while(!Yuna.empty())
    {
        int parent=Yuna.front();
        visitArray[parent] = true;
        levelArray[source] = 0;
        if(parent==destination)
        {
            cout<<"Destination found"<<endl;
            found=true;
            break;
        }
        Yuna.pop();
        for(int child:Lia[parent])
        {
            if(!visitArray[child])
            {
                Yuna.push(child);
                visitArray[child]=true;
                levelArray[child] = levelArray[parent] + 1;
            }
        }
    }
    if(found==false)
        cout << "NOT FOUND" << endl;
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int source,destination;
    cin>>source>>destination;
    memset(levelArray,-1,sizeof(levelArray));
    memset(visitArray,false,sizeof(visitArray));
    findDestination(source, destination);
    return 0;
}