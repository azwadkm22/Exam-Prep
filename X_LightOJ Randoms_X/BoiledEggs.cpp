#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t=1; t<=T; t++)
    {
        int n, p, q, x = 0;
        cin>>n>>p>>q;
        for(int i=0; i<n; i++)
        {
            int y;
            cin>>y;
            if(q-y>=0)
            {
                x++;
                q = q-y;
            }
        }
        cout<<"Case "<<t<<": "<<min(p, x)<<endl;
    }

}
