#include <bits/stdc++.h>
using namespace std;
const int maxN=1000;
const int maxWeight=1000;
int knap[maxN][maxWeight];

int knapsack(int n, int weight[], int value[], int totalWeight)
{
    if (n == 0 || totalWeight == 0)
    {
        return 0;
    }
    if(knap[n][totalWeight]!=-1)
    {
        return knap[n][totalWeight];
    }
    if (weight[n - 1] <= totalWeight)
    {
        // 2 opts
        // nao
        int op1 = knapsack(n - 1, weight, value, totalWeight - weight[n - 1] + value[n - 1]);
        int op2 = knapsack( n-1,  weight,  value,  totalWeight);
        knap[n][totalWeight] = max(op1, op2);
        //ekta 2d array te save rakhlam, pore same node ar same weight niye ashle ferot dia dibo function call na kore
        return max(op1, op2);
    }
    else
    {
        //1tai option
        int op2 = knapsack(n - 1, weight, value, totalWeight);
        knap[n][totalWeight] = op2;
        return op2;
    }
}
int main()
{
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for(int i=0;i<n;i++)
    {
        cin >> weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >>value[i];
    }
    int totalWeight;
    cin >> totalWeight;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            knap[i][j] = -1;
        }
    }
    cout << knapsack(n, weight, value, totalWeight);
    return 0;
}