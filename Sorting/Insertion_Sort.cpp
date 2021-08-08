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
        int x;
        cin>>x;
        arr[i] = x;

        // arr[i] = n-i;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }

        for(int k=0; k<n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");

    }

    for(int i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;

}
