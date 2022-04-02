#include <bits/stdc++.h>
using namespace std;

#define ll long long
double calculateDistance(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        ll oX, oY, aX, aY, bX, bY;
        cin>>oX>>oY>>aX>>aY>>bX>>bY;
        double radius = calculateDistance(oX, oY, aX, aY);
        double dis = calculateDistance(aX, aY, bX, bY);
        double theta = acos(1 - (dis*dis)/ (2*radius*radius) );

        double length = radius*theta;
        printf("Case %d: %.5lf\n", t, length);
        // cout<<"Case "<<t<<": "<<length<<endl;
    }

}
