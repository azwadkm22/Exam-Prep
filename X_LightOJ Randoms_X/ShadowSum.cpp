#include <bits/stdc++.h>
using namespace std;

#define ll long long

int setShadow[20001] = {0};
int sign[20001] = {0};

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        setShadow[i] = 0;
        sign[i] = 0;
    }
}

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        ll ans =0;
        int n;
        int maxx = -100000;
        cin>>n;
        init(20000);
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            maxx = max(abs(x), maxx);
            setShadow[abs(x)]++;
            if(x<0)
            {
                sign[abs(x)] = -1;
            }
            else
            {
                sign[x] = 1;
            }
        }


        for(int i=0; i<=maxx; i++)
        {
            if(setShadow[i])
            {;
                ans += i*sign[i];
            }
        }


        printf("Case %d: %lld\n", t, ans);
    }

}
