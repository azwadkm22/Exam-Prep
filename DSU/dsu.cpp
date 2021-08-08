#include<bits/stdc++.h>
using namespace std;

int id[100];
int sz[100] = {0};


int find(int p)
{
    if(p == id[p])
        return p;
    id[p] = find(id[p]);
    return id[p];
}

void qUnion(int p, int q)
{
    int rp = find(p);
    int rq = find(q);
    if(rp == rq) return;
    if(sz[rp] < sz[rq])
    {
        sz[rp] += sz[rq];
        id[rp] = rq;
    }
    else
    {
        sz[rq] += sz[rq];
        id[rq] = rp;
    }
    return;
}


int main()
{
    int n;
    cin>>n;

    for(int i=0; i<=n; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }

    int q;
    cin>>q;
    while(q--)
    {
        for(int i=0; i<=n; i++) cout<<"rt: "<<id[i]<<" sz: "<<sz[i]<<" ";
        cout<<endl;
        cout<<"Union? 0"<<endl;
        cout<<"Find? 1"<<endl;
        int x;
        cin>>x;
        if(x == 0 )
        {
            int p, q;
            cin>>p>>q;
            qUnion(p, q);
        }
        if(x == 1)
        {
            int p;
            cin>>p;
            cout<<find(p)<<endl;
        }
    }


}
