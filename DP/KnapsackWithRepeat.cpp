#include<bits/stdc++.h>
using namespace std;

int weight[] = {5, 1, 8, 9, 2};
int value[] = {4, 10, 2, 3, 1};

int knapsack(int w, int n, int i)
{
    if(i>=n || w<=0 )
    {
        return 0;
    }
    if(weight[i] > w)
    {
        return knapsack(i++, w, n);
    }

    int x, y;
    x = -1;
    y = -1;

    x = value[i] + knapsack(w-weight[i], n, i+1);

    y = knapsack(w, n, i+1);

    return max(x, y);
}


int dp[100][100];

//used for memoization
int knapsack(int w, int n)
{
    if( n<0 || w<=0 )
    {
        return 0;
    }

    if(dp[w][n] != -1)
    {
        return dp[w][n];
    }

    if(weight[n] > w)
    {
        //Can't take because weight exceeds maxWeight
        dp[w][n] = knapsack(w, n-1);
    }
    else
    {
        //let's pick this one
        int x = value[n] + knapsack(w-weight[n], n-1);

        //Let's not pick this one
        int y = knapsack(w, n-1);

        int z = value[n] + knapsack(w-weight[n], n);

        dp[w][n] = max(x, max(y, z));
    }

    return dp[w][n];
}


//Used in vid Example
int knapsack(int *weight, int *value, int n, int maxWeight)
{
        if(n==0 || maxWeight ==0)
        {
            return 0;
        }

        if(weight[0] > maxWeight)
        {
            return knapsack(weight+1, value+1, n-1, maxWeight);
        }

        int x = knapsack(weight+1, value+1, n-1, maxWeight - weight[0]) + value[0];
        int y = knapsack(weight+1, value+1, n-1, maxWeight);

        return max(x, y);
}

int main()
{
    int w = 30;
    int n = 4;
    for(int i=0; i<=w; i++)
    {
        for(int j=0; j<=n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<knapsack(w, n)<<endl;

}
