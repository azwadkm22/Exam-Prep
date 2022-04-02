#include <bits/stdc++.h>
using namespace std;
#define ll long long

double areaOfSector(double radius, double alpha)
{
    return .5*radius*radius*alpha;
}

double areaOfATriangle(double a, double b, double c)
{
    double s = (a+b+c)/2;
    return sqrt( s*(s-a)*(s-b)*(s-c) );
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        double r1, r2, r3;
        cin>>r1>>r2>>r3;
        double a = r1+r3;
        double b = r1+r2;
        double c = r2+r3;


        double A = acos((b*b + c*c - a*a)/(2*b*c));
        double B = acos((a*a - b*b + c*c)/(2*a*c));
        double C = acos((a*a + b*b - c*c)/(2*a*b));
        double area = areaOfATriangle(a, b, c);
        // double alpha = (r2+r3)

        double ans = area - ( areaOfSector(r2, A) + areaOfSector(r3, B) + areaOfSector(r1, C));
        printf("Case %d: %.10lf\n", t, ans);
    }

}
