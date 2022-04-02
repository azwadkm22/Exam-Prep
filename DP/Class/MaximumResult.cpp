#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
string str;

int f(int st, int end)
{
    if(st==end)
    {
        return str[st] - '0' ;
    }

    if(dp[st][end] != -1)
        return dp[st][end];
    int ans, a, b, tmp;
    a = b = ans = tmp = 0;
    ans = str[st] - '0';
    for(int i=st; i<end; i+=2)
    {
        a = f(st, i);
        b = f(i+2, end);
        cout<<"A: "<<a<<" B: "<<b<<endl;
        if (str[i+1] == '+')
            tmp = a+b;
        else tmp = a*b;
        ans = max(ans, tmp);
    }

    dp[st][end] = ans;
    return dp[st][end];
}

int main()
{
    str = "2";
    int n= str.length();
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    }
    cout<<f(0, n-1)<<endl;

}
