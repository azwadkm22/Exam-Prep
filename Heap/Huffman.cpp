#include<bits/stdc++.h>
using namespace std;

class node{

public:

    int freq;
    char value;
    node* left;
    node* right;

    node()
    {
        freq = -1;
        value = 0;
        left = NULL;
        right = NULL;
    }

    node(int _freq, char _value)
    {
        freq = _freq;
        value = _value;
        left = NULL;
        right = NULL;
    }

    node(int _freq, node* _left, node* _right)
    {
        freq = _freq;
        value = '-';
        left = _left;
        right = _right;
    }

    void print()
    {
        cout<<"Freq: "<<freq;//<<endl;
        cout<<" Char: "<<value<<endl;
    }

    friend bool operator< (node const& a, node const& b);
    friend bool operator!= (node const& c, node const& d);

};


bool operator < (node const& a, node const& b)
{
    if(a.freq > b.freq) return true;
    else return false;
}

bool operator != (node const& c, node const& d)
{
    if(c.value == d.value) return true;
    else return false;
}

void traverseTree(node x)
{
    node nil;
    if(*x.left != nil)
    {
        cout<<0;
        traverseTree(*x.left);
    }

    else if(*x.right != nil)
    {
        cout<<1;
        traverseTree(*x.right);
    }

    else
    {
        cout<<" "<<x.value<<endl;
    }
}


void printLeafNodes(node *root)
{

    cout<<"HERE"<<endl;
    // if node is null, return
    if (!root)
        return;

    // if node is leaf node, print its data
    if (!root->left && !root->right)
    {

        cout << root->value << " ";
        return;
    }

    cout<<"HERE 2 "<<endl;

    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes(root->left);


   cout<<"HERE 3"<<endl;
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes(root->right);


   cout<<"HERE 4"<<endl;
}


int main()
{
    priority_queue<node*>  pq;

    string mainCode;
    cin>>mainCode;
    int freqCount[26]={0};

    for(int i=0; i<(int)mainCode.length(); i++)
    {
        freqCount[mainCode[i] - 'A']++;
    }

    for(int i=0; i<26; i++)
    {
        char x = i + 'A';
        cout<<x<<" : "<<freqCount[i]<<endl;
        if(freqCount[i]!=0)
        {
            pq.push(node(freqCount[i], x));
        }
    }

    // AABBCDEFFF

    while(!pq.empty())
    {
        node* x1 = new node();
        node* x2 = new node();
        x1 = pq.top();//AABBCDEFFF
        x1.print();
        pq.pop();

        if(pq.empty())
        {
            cout<<x1.left<<endl;
            cout<<x1.right<<endl;
            printLeafNodes(&x1);

            break;
        }
        else{
            x2 = pq.top();
            x2.print();
            pq.pop();
            cout<<&x1<<" "<<&x2<<endl;
            node *z = new node(x1.freq+x2.freq, &x1, &x2);
            pq.push(*z);
        }
    }






    return 0;

}
