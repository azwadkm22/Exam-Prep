#include<bits/stdc++.h>
using namespace std;

int getUpperbound(int a[], int hi, int lo, int x)
{
    int ans = hi+1;
    bool found = false;
    int mid;
    while(hi >= lo)
    {
        mid = (hi+lo)/2;
        if(a[mid] <= x)
        {
            lo = mid + 1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
    }

    //returns index
    return ans;
}

int getLowerbound(int a[], int hi, int lo, int x)
{
    int ans = hi+1;
    bool found = false;
    int mid;
    while(hi >= lo)
    {
        mid = (hi+lo)/2;
        if(a[mid] < x)
        {
            lo = mid + 1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
    }

    //returns index
    return ans;
}

int main()
{
    int a[] = {1, 2, 3, 5, 5, 5, 5, 6, 6, 7, 9};
    int hi=10, lo=0, mid, ans;
    int x;
    cin>>x;

    ans = getUpperbound(a, hi, lo, x);
    if(ans > hi)
    {
        cout<<"No Upperbound"<<endl;
    }
    else
    {
        cout<<"Index: "<<ans<<endl;
        cout<<"Value: "<<a[ans]<<endl;
    }

}
