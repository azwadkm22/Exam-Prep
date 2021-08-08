#include <bits/stdc++.h>
using namespace std;




int main()
{
    int n;
    cin>>n;
    int min = 9999, minInd=0;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = n-i;
    }

    for(int i=0; i<n; i++)
    {
        min = 9999;
        for(int j=i; j<n; j++)
        {
            if(arr[j] < min)
            {
                minInd = j;
                min = arr[j];
            }
        }
        swap(arr[i], arr[minInd]);
    }

    for(int i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;

}
