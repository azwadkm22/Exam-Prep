#include<bits/stdc++.h>
using namespace std;


double getTriangleArea(double AB, double AC, double BC)
{
    double s = (AB+BC+AC)/2;

    return sqrt( ((s)*(s-AB)*(s-AC)*(s-BC)) );
}


double calculateRatio(double AD, double AB, double AC, double BC)
{
    double totalArea = getTriangleArea(AB, AC, BC);

    double AE = (AD/AB) * AC;

    double DE = (AD/AB) * BC;

    double smallTriangle = getTriangleArea(AD, AE, DE);

    double trapArea = totalArea - smallTriangle;

    return smallTriangle/trapArea;
}

int main()
{
    // freopen("out.txt", "w", stdout);

    int test;
    scanf("%d\n", &test);
    for(int t=1; t<=test; t++)
    {

        double AB, AC, BC, AD, ratio;

        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &ratio);

        double high, low, rat;

        high = AB;
        low = 0;

        for(int i=0; i<100; i++)
        {
            AD = (high+low)/2;

            rat = calculateRatio(AD, AB, AC, BC);
            if(rat > ratio)
            {
                high = AD;
            }
            else
            {
                low = AD;
            }
        }

        printf("Case %d: %.6lf\n", t, AD);

    }

    return 0;



}
