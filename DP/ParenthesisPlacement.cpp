//Place parenthesis in such a way that you get the maximum value
#include <bits/stdc++.h>
using namespace std;

int dp[100];

int f(int n)
{
    if(n%2 != 0) return 0;
    if(n==0) return 1;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    for(int i=1; i<=n; i+=2)
    {
        ans += f(i-1) * f(n-1-i);
    }

    dp[n] = ans;
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    for(int i=0; i<=n; i++) dp[i] = -1;

    cout<<f(n)<<endl;

}
