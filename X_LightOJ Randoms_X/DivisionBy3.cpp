#include <bits/stdc++.h>
using namespace std;
#define ll long long


int f(int x)
{
    if(x==0) return 0;

    int subs = 0;
    if(x%3 == 0)
    {
        subs = x/3;
    }
    else
    {
        subs = x/3 + 1;
    }
    return x - subs;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int x, y;
        cin>>x>>y;
        int ans = f(y) - f(x-1);
        printf("Case %d: %d\n", t, ans);
    }

}
