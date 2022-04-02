#include <bits/stdc++.h>
using namespace std;
#define ll long long

double dp[1000001];


int main()
{
    dp[0] = 0;
    for(int i=1; i<=1000000; i++)
    {
        dp[i] = dp[i-1] + log(i);
    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        ll digits;
        int n, base;
        scanf("%d %d",&n, &base );

        digits = ( dp[n]/log(base) ) + 1;
        printf("Case %d: %llu\n", t, digits);

    }

}
