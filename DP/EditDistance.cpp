#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int editDistance(string s1, string s2)
{
    if(s1.size() == 0 || s2.size() == 0)
    {
        return max(s1.size(), s2.size());
    }


    int m = s1.size();
    int n = s2.size();

    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }


    if(s1[0] == s2[0])
    {
        dp[m][n] = editDistance(s1.substr(1), s2.substr(1));
    }

    else
    {

        //insert
        int x = 1 + editDistance(s1.substr(1), s2);
        //remove
        int y = 1 + editDistance(s1, s2.substr(1));
        //
        int z = 1 + editDistance(s1.substr(1), s2.substr(1));

        dp[m][n] = min(x, min(y, z));


    }

    return dp[m][n];
}

int main()
{

    string s1 = "aeeeeeeeeeaaaaaaaaaaaaaaaaaaaaaaaaebc";
    string s2 = "abasdjnasldkasldkasnldknasldknasldkansldkasnlkc";
    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s2.size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<editDistance(s1, s2)<<endl;


}
