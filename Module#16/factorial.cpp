#include <bits/stdc++.h>
using namespace std;
// O(N)
int factorial(int n)
{
    if(n==0)
        return 1;
    int previousFactorial=factorial(n-1);
    return previousFactorial*n;
}
int main()
{
    int N;
    cin>>N;
    int ans=1;
    for(int i=0;i<N;i++)
    {
        ans*=i;
    } //O(N)
    cout<<ans<<endl;
    return 0;
}