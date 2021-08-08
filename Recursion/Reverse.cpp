#include <bits/stdc++.h>
using namespace std;


void reverse(int start, int end, int arr[])
{
    if(start >= end) return;
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;

    reverse(start+1, end-1, arr);
}


int main()
{
    int a[3] = {1, 2, 3, 4, 5, 6};

    reverse(0, 6-1, a);

    for(int i=0; i< 6; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;

}
