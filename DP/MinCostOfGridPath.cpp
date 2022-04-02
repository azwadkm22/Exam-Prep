#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int dp[100][100] = {-1};


int f(int m, int n, int i, int j)
{
    cout<<"here"<<endl;
    if(i == m-1 && j == n-1)
    {
        return graph[i][j];
    }

    if(i >= m || j>= n)
    {
        return INT_MIN;
    }

    if(dp[i][j] != -1 )
        return dp[i][j];

    int x = f(m, n, i+1, j);
    int y = f(m, n, i, j+1);
    int z = f(m, n, i+1, j+1);

    dp[i][j] = max(x, max(y, z)) + (graph[i][j]%2 == 0 ?  0 : graph[i][j]); 
    cout<<dp[i][j]<<endl;
    return dp[i][j];

}


// 4 4
// 2 3 4 5
// 1 2 3 7
// 0 2 10 2
// 0 1 1 10

int main()
{
    int m, n;
    cin>>m>>n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = -1;
            cin>>graph[i][j];
        }
    }


    cout<<f(m, n, 0, 0)<<endl;
}
