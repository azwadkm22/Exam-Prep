#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    double lo, hi, mid;
    scanf("%lld", &n);
    lo = 1;
    hi = n;
    for(int i=0; i<100; i++)
    {
        mid = (lo + hi)/2;
        if(mid*mid > n) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }

    printf("%.8lf\n", lo);
    return 0;
}
