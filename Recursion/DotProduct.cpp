#include <bits/stdc++.h>
using namespace std;


int findDot(int n, int vec1[], int vec2[])
{
    if (n < 0) return 0;
    return vec1[n]*vec2[n] + findDot(n-1, vec1, vec2);
}


int main()
{
    int a[3] = {1, 2, 3};
    int b[3] = {-1, -1, 1};

    cout<<findDot(2, a, b)<<endl;


    return 0;

}
