//A list of children is given your job is to divide them in groups
// in such a way that the group's age difference stays in 1

#include<bits/stdc++.h>
using namespace std;

double age[] = {1.2, 2, 2.4, 3, 3.6, 4, 4.2, 4.5,4.6, 5, 6};

int minGroups()
{
    int curr = 0;
    int kids = 11;
    int groups = 1;
    int i=0;

    while(i < kids)
    {
        // cout<<curr<<" "<<i<<" "<<kids<<endl;
        if(age[i] - age[curr] <= 1.0)
        {
            i++;
        }
        else
        {
            cout<<"Need a new group for  "<<age[i]<<endl;
            curr = i;
            groups++;
        }

    }
    return groups;
}

int main()
{
    cout<<minGroups()<<endl;

}
