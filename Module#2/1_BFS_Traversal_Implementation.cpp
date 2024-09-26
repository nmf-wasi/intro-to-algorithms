#include <bits/stdc++.h>
using namespace std;
vector<int>Lia[1001];
bool visit_array[1001];
//size will be given in ques
void bfs(int source)
{
    queue<int>Yuna; //queue er size lage na
    Yuna.push(source);
    visit_array[source] = true;
    while(!Yuna.empty())
    {
        //ber kora
        int parent = Yuna.front();
        Yuna.pop();


        //kaj kora
        cout << parent << endl;
        for (int i = 0; i < Lia[parent].size(); i++)
        {
            int child = Lia[parent][i];
            cout << child << " ";
        }
        cout << endl;

        // children rakha
        for (int i = 0; i < Lia[parent].size();i++)
        {
            if(visit_array[Lia[parent][i]]==false)
            {
                Yuna.push(Lia[parent][i]);
                visit_array[Lia[parent][i]] = true;
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
        int a,b;
        cin>>a>>b;
        Lia[a].push_back(b);
        Lia[b].push_back(a);
    }
    int source; //they will give a node as input which will be source as well
    cin >> source;
    bfs(source);
    return 0;
}