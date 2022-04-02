#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct peep {
    int val;
    int pos;
};


void f(peep *divisor)
{
    for(int i=1; i<=1000; i++)
    {
        divisor[i].val = 0;
        divisor[i].pos = i;
        // int rt = sqrt(i);
        for(int j=1; j<=1000; j++)
        {
            if( i%j == 0 )
            {
                divisor[i].val += 1;
            }
        }
    }
    // divisor[1].val = 1;
}



bool comp(peep i, peep j)
{
    if(i.val != j.val)
        return i.val < j.val;
    return i.pos > j.pos;
}

int main()
{

    peep divisor[1001];
    int T;
    scanf("%d", &T);
    f(divisor);
    sort(divisor, divisor+1001, comp);
    for(int t=1; t<=T; t++)
    {
        int x;
        scanf("%d", &x);
        int ans = divisor[x].pos;
        printf("Case %d: %d\n", t, ans);
    }

}
