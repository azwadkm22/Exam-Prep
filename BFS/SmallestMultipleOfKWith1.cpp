#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    int ans = 1;

    cin>>k;
    if(k%2 == 0 || k%5 ==0)
    {
        printf("Not Possible\n");
    }
    else
    {
        while(ans%k != 0)
        {
            ans = ans*10 + 1;
        }
        cout<<ans<<endl;
    }
}
