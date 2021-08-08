#include <bits/stdc++.h>
using namespace std;


int binarySearch(int x, int start, int end, int a[])
{
    if(start > end ) return -1;

    int mid =  (start + end )/2;
    if(a[mid] > x)
    return binarySearch(x, start, mid-1, a);
    else if(a[mid] < x)
    return binarySearch(x, mid+1, end, a);
    else return mid;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = i+1;
    }

    int x;
    cin>>x;

    int index = binarySearch(x, 0, n, arr);

    cout<<index<<endl;
    return 0;

}
