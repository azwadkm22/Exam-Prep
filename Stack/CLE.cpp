#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, 4, 5, 2, 1, 0, 7};
    int n = 8;
    stack<int> st;
    stack<int> ind;
    vector<int> cleIndex;

    st.push(-1);
    ind.push(-1);

    for(int i=0;i<n; i++)
    {
        while(st.top() >= arr[i])
        {
            st.pop();
            // ind.pop();
        }
        cout<<st.top()<<endl;
        //
        // if(i==0)
        // cleIndex.push_back(-1);
        // else cleIndex.push_back(ind.top());

        st.push(arr[i]);
    }

    for(auto c: cleIndex)
    cout<<c<<" ";

}
