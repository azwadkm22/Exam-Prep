#include <bits/stdc++.h>
using namespace std;


class MaxHeap{
public:

    int data[100] = {0};
    int index = 0;
    int num = 0;

    int father(int ind)
    {
        return ind/2;
    }

    int leftChild(int ind )
    {
        return 2*ind;
    }

    int rightChild(int ind)
    {
        return 2*ind + 1;
    }

    void insert(int x)
    {
        num++;
        data[num] = x;
        index = num;
        while(index != 1 && data[father(index)] < data[index])
        {
            swap(data[father(index)], data[index]);

            index = father(index);
        }

        print();
    }

    int extractMax()
    {

        cout<<"Swap: "<<data[1]<<" "<<data[num]<<endl;
        int res = data[1];
        data[1] = -9999;

        swap(data[1], data[num]);

        index = 1;
        num--;

        while(data[index] < data[leftChild(index)] || data[index] < data[rightChild(index)] )
        {
            if(data[index] < data[leftChild(index)])
            {
                swap(data[index],data[leftChild(index)]);
                index = leftChild(index);
            }
            else
            {
                swap(data[index],data[rightChild(index)]);
                index = rightChild(index);
            }

        }

        print();
    }

    void print()
    {
        for(int i=1; i<=num; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    MaxHeap mh;

    mh.insert(5);
    mh.insert(4);
    mh.insert(3);
    mh.insert(6);
    mh.insert(0);
    mh.insert(10);
    mh.insert(9);
    mh.print();


    mh.extractMax();
}
