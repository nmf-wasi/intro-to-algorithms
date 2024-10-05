#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for (int i = 0; i < n;i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n;i++)
    {
        cin >> value[i];
    }
    int totalWeight;
    cin>> totalWeight;
    int knap[n+1][totalWeight+1];
    //0 number e taka nai, or weigght nai, taile to kisui hobe na, tai ek ghor beshi ney
    for (int i = 0; i <= n;i++)
    {
        for (int j = 0;j<=totalWeight;j++)
        {
            if(weight[i-1]<=j)
            {
                int op1 = knap[i - 1][j - weight[i - 1] + value[i - 1]];
                int op2 = knap[i - 1][j];
                knap[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = knap[i - 1][j];
                knap[i][j] = op2;
            }
        }
    }
    cout << knap[n][totalWeight];
    return 0;
}