#include<bits/stdc++.h>
using namespace std;


int dp[100000] = {0};


int minStepsTo1New(int n)
{
    // cout<<n<<endl;
    if(n==1) return 0;
    if(dp[n] != 0) return dp[n];

    int y, z;
    y = z = INT_MAX;

    if(dp[n-1] != 0)
        dp[n-1] = minStepsTo1New(n-1);

    if( n % 2 == 0)
    {
        if(dp[n/2] != 0)
            dp[n/2] = minStepsTo1New(n/2);

        y = dp[n/2];

    }

    if( n % 3 == 0 )
    {
        if(dp[n/3] != 0)
            dp[n/3] = minStepsTo1New(n/3);

        z = dp[n/3];
    }

    dp[n] = 1 + min(dp[n-1], min(z, y));
    return dp[n];
}


int minStepsTo1(int n)
{
    if(n==1) return 0;
    if(dp[n] != 0) return dp[n];

    int x, y, z;
    x = y = z = INT_MAX;
    x = minStepsTo1(n-1);

    if( n % 2 == 0)
    y = minStepsTo1(n/2);

    if( n % 3 == 0 )
    z = minStepsTo1(n/3);


    dp[n] = 1 + min(min(x, y), z);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<minStepsTo1(n)<<endl;
    cout<<minStepsTo1New(n)<<endl;
}
