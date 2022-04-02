#include<bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int value;
    double perUnit;

    item(int _weight, int _value)
    {
        weight = _weight;
        value = _value;
        perUnit = (double)value/weight;
    }
    bool operator <(const item &a)const{
        return perUnit>=a.perUnit;
    }

    item()
    {
        weight = value = 0;
        perUnit = 0;
    }



    void print()
    {
        cout<<weight<<" "<<value<<" "<<perUnit<<endl;
    }
};

// bool win(item a)
// {
//     return a.perUnit>= perUnit;
// }

int weight[] = {5, 1, 8, 9, 2};
int value[] = {4, 10, 2, 3, 1};


int main()
{
    int w = 7;
    int n = 5;
    item list[5];
    // for(int i=0; i<n; i++)
    // {
    //     perUnit[i] = (double)value[i]/weight[i];
    // }

    for(int i=0; i<n; i++)
    {
        list[i] = item(weight[i], value[i]);
    }

    sort(list, list+n);
    // reverse(item, item+n);


    for(int i=0; i<n; i++)
    {
        list[i].print();
    }

    double remain = w;
    double val =0;

    for(int i=0; i<n; i++)
    {
        if(remain - list[i].weight > 0 )
        {
            cout<<"Taken: w = "<<list[i].weight<<" v:"<<list[i].value<<endl;
            remain -= list[i].weight;
            val += list[i].value;
        }
        else if(remain > 0)
        {
            val += remain*list[i].perUnit;
            cout<<"Taken: w = "<<remain<<" from "<<list[i].weight<<" v:"<<remain*list[i].perUnit<<endl;
            remain = 0;
        }
        else
        {
            break;
        }
    }

    cout<<"Total valued things: "<<val<<endl;


    // cout<<fractionalKnapsack6(w, n)<<endl;

}
