#include <bits/stdc++.h>
using namespace std;

#define ll long long
double calculateDistance(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

double areaOfATriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return .5* abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

        cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;

        Dx = Ax - Bx + Cx;
        Dy = Cy - By + Ay;



        int area = areaOfATriangle(Ax, Ay, Bx, By, Cx, Cy) + areaOfATriangle(Ax, Ay, Dx, Dy, Cx, Cy);
        printf("Case %d: %d %d %d\n", t, Dx, Dy, area);
    }

}
