#include <bits/stdc++.h>
using namespace std;

void printArray(int n, int a[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int removeOdd(int cur, int n, int cursor, int a[], int evenCnt) {
    if(cur == n) return evenCnt;

    if(a[cur] % 2) {
        //do nothing
    } else {
        a[cursor] = a[cur];
        cursor++;
        evenCnt++;
    }

    return removeOdd(cur+1, n, cursor, a, evenCnt);

}


int main()
{
    int a[4] = {1, 2, 3, 4};

    // printPerm(3, a);
    int ct = removeOdd(0, 4, 0, a, 0);

    printArray(ct, a);

    return 0;

}
