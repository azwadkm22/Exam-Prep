#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int A[] = {10, 30 , 5, 60}; //Dimensions of the matrices, M0 = A0-A1, M1 = A1, A2, M2 = A2, A3

int minMatrixMultiplication(int st, int end)
{
    if(st==end)
    {
        return 0;
    }

    if(dp[st][end] != -1)
        return dp[st][end];

    int ans, a, b, c;
    a = b = ans = c = 10000000;
    for(int i=st; i<end; i++)
    {
        a = minMatrixMultiplication(st, i);
        b = minMatrixMultiplication(i+1, end);
        c = A[st]*A[i+1]*A[end+1];
        ans = min(ans, a+b+c);
    }
    dp[st][end] = ans;
    return dp[st][end];
}

int main()
{
    int n=4;
    // cin>>n;
    // for(int i=0; i<n; i++) cin>>A[i];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    }
    cout<< minMatrixMultiplication(0, n-1)<<endl;

}
