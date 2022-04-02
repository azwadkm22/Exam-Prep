#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int n, p;
        scanf("%d %d", &n, &p);
        // cin>>n>>p;
        int flip = 0;
        int finalSum = 0, parSum = 0;
        for(int i=1; i<=n; i++)
        {
            parSum += i;
            if(i%p == 0)
            {
                if(flip == 0)
                parSum = parSum*-1;

                flip = flip == 0 ? 1 : 0;

                finalSum += parSum;
                parSum = 0;
            }
        }

        printf("Case %d: %d\n", t, finalSum);

        // cout<<"Case "<<t<<": "<<finalSum<<endl;
    }

}
