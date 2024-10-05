#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll fibo[N];
ll fibonacci(ll n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(fibo[n]!=-1)
    {
        return fibo[n];
        //it doesnt allow the function to call for the same number multipole times, that's why its more optimized
    }
    ll ans=fibonacci(n-1)+fibonacci(n-2);
    fibo[n]=ans;
    //this stores the fibonacci numbers for every number in an array and when the same number is called again, it simply returns value from the array instead of calling the function
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    memset(fibo, -1, sizeof(fibo));
    cout << fibonacci(n) << endl;
}