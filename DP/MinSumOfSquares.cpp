#include<bits/stdc++.h>
using namespace std;

int dp[60000] = {0};
int f(int n)
{
    if(n<=1) return 1;
    if(dp[n] != 0) return dp[n];
    int rt = floor( sqrt(n) );
    int min = INT_MAX;

    if(rt*rt == n)
    {
        dp[n] = 1;
    }

    else
    {
        for(int i=1; i<=rt; i++)
        {
            if(dp[n- i*i] == 0)
            dp[n-i*i] = f(n - i*i);
            if( dp[n-i*i] < min )
            {
                min = dp[n-i*i];
            }
        }
        dp[n] = 1 + min;
    }

    return dp[n];
}

int main()
{
    int x;
    cin>>x;
    cout<<f(x)<<endl;
}
