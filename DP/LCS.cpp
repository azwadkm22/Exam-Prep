#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int LCS(string s1, string s2)
{
    if(s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }

    int m = s1.size();
    int n = s2.size();

    if(dp[m][n] != -1)
        return dp[m][n];

    if(s1[0] == s2[0])
    {
        dp[m-1][n-1] = LCS(s1.substr(1), s2.substr(1));
        dp[m][n] = 1 + dp[m-1][n-1];
    }
    else
    {
        dp[m][n-1] = LCS(s1, s2.substr(1));
        dp[m-1][n] = LCS(s1.substr(1), s2);
        dp[m-1][n-1] = LCS(s1.substr(1), s2.substr(1));

        dp[m][n] = max(dp[m-1][n], min(dp[m][n-1], dp[m-1][n-1]));
    }

    return dp[m][n];


}


int lcsJami(int ia, int ib)
{
    if(ia == 0 || ib == 0) return 0;

    if(dp[ia-1][ib-1] != -1)
        return dp[ia-1][ib-1];
    int a, b, c, ans;
    a = b = c = 0;
    if(s1[ia] == s2[ib])
    {
        a = lcsJami(ia-1, ib-1) +1;
        ans = a;
    }
    else
    {
        b = lcsJami(ia-1, ib);
        c = lcsJami(ia, ib-1);
        ans = max(b, c);
    }
    dp[ia-1][ib-1] = ans;
    return dp[ia-1][ib-1];
}


int NOTlcsJami(int ia, int ib)
{
    if(ia == 0 || ib == 0) return 0;

    if(dp[ia-1][ib-1] != -1)
        return dp[ia-1][ib-1];
    int a, b, c, ans;
    a = b = c = 0;
    if(s1[ia] == s2[ib])
    {
        a = lcsJami(ia-1, ib-1) +1;
        ans = a;
    }
    else
    {
        b = lcsJami(ia-1, ib);
        c = lcsJami(ia, ib-1);
        ans = max(b, c);
    }
    dp[ia-1][ib-1] = ans;
    return dp[ia-1][ib-1];
}


int LCSpoop(string s1, string s2)
{
    if(s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }

    // int m = s1.size();
    // int n = s2.size();

    // if(dp[m][n] != -1)
    //     return dp[m][n];

    if(s1[0] == s2[0])
    {
        return 1 + LCSpoop(s1.substr(1), s2.substr(1));
    }
    else
    {
        int x = LCSpoop(s1, s2.substr(1));
        int y = LCSpoop(s1.substr(1), s2);
        int z = LCSpoop(s1.substr(1), s2.substr(1));
        return max(x, y);
    }
}


int main()
{

    string s1 = "abcde";
    string s2 = "bcdef";
    cout<<s1.substr(1)<<endl;
    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s2.size(); j++)
        {
            dp[i][j] = -1;
        }
    }


    cout<<LCSpoop(s1, s2)<<endl;

    cout<<LCS(s1, s2)<<endl;

}
