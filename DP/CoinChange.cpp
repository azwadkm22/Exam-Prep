#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int dp[100];
int numOfCoins[] = [3, 2, 1];
int coin[] = {1, 2, 5};
int size = 3;


int minNumberOfCoins(int n)
{
    if(n == 0)
        return 0;

    if(n < 0)
        return 1000;

    int x, y, z;
    x = inf;

    if(dp[n] != -1)
        return dp[n];

    for(int i=0; i<size; i++)
    {
        x = min(x, 1 + minNumberOfCoins(n - coin[i]));
    }

    dp[n] = x;

    return dp[n];

}



int numberOfWays(int n)
{
    if(n == 0)
        return 1;

    if(n < 0)
        return 0;

    int x, y, z;
    x = 0;

    if(dp[n] != -1)
        return dp[n];

    for(int i=0; i<size; i++)
    {
        x +=  numberOfWays(n - coin[i]);
    }

    dp[n] = x;

    return dp[n];

}

int main()
{
    for(int i=0; i<100; i++)
    {
        dp[i] = -1  ;
    }
    cout<<coin[0]<<" "<<coin[1]<<" "<<coin[2]<<endl;
    cout<<numberOfWays(5)<<endl;

}
