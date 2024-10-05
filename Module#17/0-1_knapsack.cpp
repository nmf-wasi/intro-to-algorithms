#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int weight[],int value[], int totalWeight)
{
    if (n == 0 || totalWeight==0)
        return 0;
    if (weight[n - 1] <= totalWeight)
    {
        //2ta option 
        // niye dekhba, na niye dekhba
        int option1 = knapsack(n - 1, weight, value, totalWeight - weight[n - 1] + value[n - 1]); // nile totalWieght kome
        int option2 = knapsack(n - 1, weight, value, totalWeight);//na nile totalWieght kome na
        return max(option1, option2);
    }
    else
    {
        //ekta option, niba na
        int option2 = knapsack(n - 1, weight, value, totalWeight); // na nile totalWieght kome na
        return option2;
    }
}
int main()
{
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int totalWeight;
    cin>>totalWeight;
    cout<<knapsack(n,weight,value,totalWeight);
    return 0;
}