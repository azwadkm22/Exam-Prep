#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        string number;
        ll divisor;
        bool divNeg = false, numNeg = false;
        ll remainder=0;
        cin>>number>>divisor;
        for(int i=0; i<number.length(); i++)
        {
            if(number[i] == '-')
            {
                continue;
            }
            remainder = remainder*10 + ( number[i] - '0');
            if(remainder >= divisor)
            {
                remainder = remainder%divisor;
            }
        }

        if(remainder == 0)
            printf("Case %d: divisible\n", t);
        else
            printf("Case %d: not divisible\n", t);

    }

}
