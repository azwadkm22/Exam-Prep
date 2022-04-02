#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string s1, s2;


int lps(string s1, int ia, int ib)
{
    if(ia > ib) return 0;
    if(ia == ib) return 1;

    if(dp[ia][ib] != -1)
        return dp[ia][ib];
    int a, b, c, ans;
    a = b = c = 0;

    if(s1[ia] == s1[ib])
    {
        a = lps(s1, ia+1, ib-1) +2;
        ans = a;
    }
    else
    {
        b = lps(s1, ia+1, ib);
        c = lps(s1, ia, ib-1);
        ans = max(b, c);
    }
    dp[ia][ib] = ans;
    return dp[ia][ib];
}

int main()
{

    s1 = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
    s2 = "bcdef";
    // cout<<s1.substr(1)<<endl;
    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s1.size(); j++)
        {
            dp[i][j] = -1;
        }
    }
    int m = s1.size();
    // int n = s2.size();
    cout<<lps(s1, 0, m-1)<<endl;
    // cout<<lcsJami(m, n)<<endl;

}
