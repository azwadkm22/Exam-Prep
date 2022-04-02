#include <bits/stdc++.h>
using namespace std;

int dp[100];
int s1[] = {99, 1, 2, 3, 11, 22, 31, 32, 33};
int n = 8;

int lis(int idx)
{
    if(idx == n+1) return 0;
    if(dp[idx] != -1)
    {
        return dp[idx];
    }
    int a, ans, b;

    a = lis(idx+1);
    ans = max(1, a);
    for(int j=idx+1; j<=n; j++)
    {
        if(s1[idx] <= s1[j])
        {
            b = lis(j) + 1;
            ans = max(ans, b);
        }
    }
    dp[idx] = ans;
    return dp[idx];
}

int main()
{

    for(int i=0; i<=n; i++)
    {
        dp[i] = -1;
    }
    cout<<lis(1)<<endl;

}
