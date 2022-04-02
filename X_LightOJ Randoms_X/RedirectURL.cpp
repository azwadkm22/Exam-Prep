#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        string var;
        cin>>var;
        string s = var.substr(4);
        printf("Case %d: ", t);
        if(s[0] != 's')
        {
            cout<<"https" + s<<endl;
        }
        else
        {
            cout<<var<<endl;
        }
    }

}
