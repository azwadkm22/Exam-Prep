#include<bits/stdc++.h>
using namespace std;

long long dp[100000] = {0};

long long f(int h)
{
    if (h<=1) return 1;
    if(dp[h] != 0) return dp[h];
    int mod = int (pow(10, 9) + 7);

    long long x  = f(h-1);
    long long y = f(h-2);

    dp[h] = ( (x*x)%mod + (2*x*y)%mod )%mod;

    return dp[h];

}

int main()
{
    int h;
    cin>>h;

    cout<<f(h)<<endl;
}
