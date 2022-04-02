#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        long long ans = 0;
        int n;
        cin>>n;
        cout<<"Case "<<t<<":"<<endl;
        for(int j=0; j<n; j++)
        {
            string cmd;
            cin>>cmd;
            if(cmd == "donate")
            {
                int k;
                cin>>k;
                ans += k;
            }
            else if(cmd == "report")
            {
                cout<<ans<<endl;
            }
        }
    }

}
