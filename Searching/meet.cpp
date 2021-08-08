#include<bits/stdc++.h>
using namespace std;

int main()
{
    int jack = 100;
    int rose = 150;
    int dis = 2000;
    double hi = 0;
    double lo = dis;
    double mid;
    double t1 = (double)dis/jack;
    double t2 = 0;
    double prev = -1;
    for(int i=0; i<100; i++)
    {
        mid = (hi+lo)/2;
        // cout<<mid<<endl;
        t1 = mid/jack;
        t2 = (dis-mid)/rose;
        if(t1 < t2)
        {
            hi = mid;
        }
        else lo = mid;

        if(t1 == t2) break;
        if((int)mid == (int)prev) break;
        else{
            prev = mid;
        }
    }
    t1 = mid/jack;

    t2 = (dis-mid)/rose;

    cout<<t1<<" :times: "<<t2<<endl;
    cout<<(int)mid<<endl;
}
