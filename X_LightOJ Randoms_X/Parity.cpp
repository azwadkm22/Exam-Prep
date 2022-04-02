#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        long long x;
        cin>>x;
        int par=0;
        while(x!=0)
        {
            if(x%2!=0) par++;
            x/=2;
        }

        if(par%2 == 0)
        {
            printf("Case %d: even\n", t);
        }
        else
        {
            printf("Case %d: odd\n", t);
        }
    }

}
