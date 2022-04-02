#include <bits/stdc++.h>
using namespace std;

int gas[] = {0, 200, 300, 400, 550, 600, 700, 950, 1000, 1200, 1500, 1800};


int main()
{
    int d = 300;
    int n = 11;
    int currentFill=0;
    int lastFill=0;
    int numRefill =0;
    while(currentFill < n)
    {
        lastFill = currentFill;
        while(currentFill <= n && (gas[currentFill+1] - gas[lastFill] <= d) )
        {
            currentFill++;
        }
        if(currentFill == lastFill)
        {
            cout<<"Impossibleeeee"<<endl;
            return 0;
        }
        if(currentFill <= n)
        {
            numRefill++;
        }
    }

    cout<<numRefill<<endl;

}
