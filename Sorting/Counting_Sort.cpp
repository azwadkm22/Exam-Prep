#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"debugging - "<<x<<endl;
#define ull unsigned long long
#define ll long long

void countingSort(int A[], int n)
{



}

int main()
{
    int n = 8;
    int A[] = {2, 4, 1, 2, 1, 4, 4, 3};
    int freq[8] = {0};
    int cumulated[8] = {0};
    int maxx = -100;

    for(int i=0; i<n; i++)
    {
        freq[A[i]]++;
        maxx = max(maxx, A[i]);
    }

    freq[0] = 0;
    for(int i=1; i<=maxx; i++)
    {
        cout<<freq[i]<<endl;
        freq[i] += freq[i-1] ;
    }

    cout<<"cumulated "<<endl;
    //
    for(int i=1; i<=maxx; i++)
    {
        cout<<freq[i]<<endl;
    }

    // int prev = 0;
    //
    // for(int i=1; i<=maxx; i++)
    // {
    //     prev = freq[i];
    //
    //     freq[i+1] = freq[i];
    // }
    //
    // int temp = 0;

    int shifted[n];

    for(int i=2; i<=maxx ; i++)
    {
        shifted[i] = freq[i-1];
    }

    shifted[1] = 0;

    for(int i=0; i<=maxx; i++)
    {
        cout<<shifted[i]<<endl;
    }



    int newArr[n] = {0};

    // for j D A:length downto 1
    // B[C [A[j]]] =  AŒj
    // C ŒAŒj  D C ŒAŒj   1

    debug("calculate")
    for(int i=0; i<=maxx; i++)
    {
        cout<<"sh : "<<shifted[i]<<endl;
        while(shifted[i+1] - shifted[i] > 0)
        {
            shifted[i+1]--;
            cout<<i<<endl;
        }
    }

    for(int i=0; i<=maxx; i++)
    {
        cout<<shifted[i]<<endl;
    }

    cout<<"SORTED"<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<newArr[i]<<endl;
    }
    //
    // for(int i=0; i<=n; i++)
    // {
    //
    // }


    return 0;
}
