#include <bits/stdc++.h>
using namespace std;

void printPerm(int n, int a[])
{
    for(int i=0; i<n; i++)
    printf("%d ", a[i]);
    printf("\n");
}

void printRev(int n, int a[])
{
    for(int i=n-1; i>=0; i--)
    printf("%d ", a[i]);
    printf("\n");
}

void permute(int n, int start, int end, int a[])
{
    if(start == 0 && end == 3 && n == 4) printPerm(n, a);
    if (start == end) {
        return;
    }

    for(int i=start; i<end; i++)
    {
        for(int j=i+1; j<=end; j++)
        {
            swap(a[i], a[j]);
            permute(n, i+1, end, a);
            printPerm(n, a);
            swap(a[i], a[j]);
        }
    }
    // printPerm(n, a);
}

void permute2(int n, int start, int end, int a[])
{
    // if(start == 0 && end == 3 && n == 4) printPerm(n, a);
    if (start == end) {
        printPerm(n, a);
        return;
    }

    for(int i=start; i<end; i++)
    {
            swap(a[start], a[i]);
            permute(n, start+1, end, a);
            // printPerm(n, a);
            swap(a[start], a[i]);

    }
    // printPerm(n, a);
}


int main()
{
    int a[4] = {1, 2, 3, 4};

    // printPerm(3, a);
    permute(4, 0, 3, a);

    return 0;

}
