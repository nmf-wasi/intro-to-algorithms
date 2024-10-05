#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
//boolen cant keep anything else except true or false
// therefore, we cant say if an index is saved or not so we are using boolean
//true=1, flase =0., int can keep both 
int subset_sum(int n,int a[], int s)
{
    if(n==0)
    {
        if(s==0)
            return 1;
        else
            return 0;
    }
    if(dp[n][s]!=-1)
        return dp[n][s];
    if(a[n-1]<=s)
    {
        int op1 = subset_sum(n - 1, a, s - a[n - 1]); // array starts from 0, inputs start from 1
        int op2 = subset_sum(n - 1, a, s);
        dp[n][s] = op1 + op2;
        return op1 + op2;
    }
    else
    {
        return dp[n][s] =subset_sum(n - 1, a, s);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j <= sum;j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0]=1;
    for (int i = 1; i <= n;i++)
    {
        dp[0][i] = 0;
        //first row fill up
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0;j<=sum;j++)
        {
            if(a[i-1]<=j)
            {
                bool op1 = dp[i - 1][j - a[i - 1]];
                bool op2 = dp[i - 1][j];
                dp[i][j] = op1 + op2;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j <= sum;j++)
        {
            cout << dp[i][j];
        }
        cout<<endl;
    }
    return 0;
}