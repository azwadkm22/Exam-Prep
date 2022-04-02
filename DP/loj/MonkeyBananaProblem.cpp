#include<bits/stdc++.h>
using namespace std;

long long dp[51][51][51] = {0};
long long bananas[200][200] = {0};

void makeField(int n)
{
    for(int i=1; i<=2*n-1; i++)
    {
        int x =0;
        if(i <= n)
        {
            for(int j=1; j<=i; j++)
            {
                cin>>x;
                bananas[i][j] = x;
            }
        }
        else {
            for(int j=1; j<=2*n-i; j++)
            {
                cin>>x;
                bananas[i][j] = x;
            }
        }
    }
}
void showField(int n)
{
    for(int i=1; i<=2*n-1; i++)
    {
        if(i <= n)
        {
            for(int j=0; j<=i+1; j++)
            {
                cout<<i<<" "<<j<<" v:"<<bananas[i][j]<<" ";
            }
        }
        else {
            for(int j=0; j<=2*n-i+1; j++)
            {
                cout<<i<<" "<<j<<" v:"<<bananas[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void init(int n)
{
    for(int i=0; i<=2*n-1; i++)
    {
        for(int j=0; j<=2*n-1; j++)
        {
            dp[i][j] = 0;
            bananas[i][j] = 0;
        }
    }

}

long long f(int i, int j, int n)
{
    if(i > 2*n-1)
    {
        return 0;
    }

    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }

    long long x, y;
    x=y=0;

    if(i < n )
    {
        if(bananas[i+1][j])
        x = f(i+1, j, n);
        if(bananas[i+1][j+1])
        y = f(i+1, j+1, n);
    }
    else {
        if(bananas[i+1][j])
        x = f(i+1, j, n);
        if(bananas[i+1][j-1])
        y = f(i+1, j-1, n);
    }

    dp[i][j] = bananas[i][j] + max(x, y);
    return dp[i][j];
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        init(n);
        makeField(n);
        // showField(n);
        long long ans = f(1, 1, n);
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}
