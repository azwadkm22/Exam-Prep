#include<bits/stdc++.h>
using namespace std;

int dp[60][60][60] = {0};

string s1, s2, s3;


int LCS(int m, int n, int p)
{
    if(m == 0 || n == 0 || p == 0)
    {
        return 0;
    }

    if(dp[m][n][p] != -1)
        return dp[m][n][p];

    if(s1[m] == s2[n] && s2[n] == s3[p])
    {
        // cout<<"."<<s1[m]<<s2[n]<<s3[p]<<"."<<endl;
        dp[m-1][n-1][p-1] = LCS(m-1, n-1, p-1);
        dp[m][n][p] = 1 + dp[m-1][n-1][p-1];
    }
    else
    {
        dp[m][n][p-1] = LCS(m, n, p-1);
        dp[m][n-1][p] = LCS(m, n-1, p);
        dp[m][n-1][p-1] = LCS(m, n-1, p-1);
        dp[m-1][n][p] = LCS(m-1, n, p);
        dp[m-1][n][p-1] = LCS(m-1, n, p-1);
        dp[m-1][n-1][p] = LCS(m-1, n-1, p);
        dp[m-1][n-1][p-1] = LCS(m-1, n-1, p-1);

        dp[m][n][p] = max(dp[m][n][p-1], max(dp[m][n-1][p], max(dp[m][n-1][p-1], max(dp[m-1][n][p], max(dp[m-1][n][p-1], max(dp[m-1][n-1][p], dp[m-1][n-1][p-1]))))));
    }
    return dp[m][n][p];
}

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            for(int k=0; k<=n; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

}


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        s1 = "x";
        s2 = "y";
        s3 = "z";
        string x1, x2, x3;
        cin>>x1>>x2>>x3;
        // scanf("%s %s %s", x1, x2, x3);
        s1 += x1;
        s2 += x2;
        s3 += x3;
        int n = max(s1.size(), max(s2.size(), s3.size()));
        init(n);
        int i1, i2, i3;
        i1 = s1.size()-1;
        i2 = s2.size()-1;
        i3 = s3.size()-1;

        // cout<<i1<<" "<<i2<<" "<<i3<<endl;
        // cout<<"'"<<s1<<"'"<<s2<<"'"<<s3<<endl;
        int ans = LCS(i1, i2, i3);
        printf("Case %d: %d\n", t, ans);
    }

}
