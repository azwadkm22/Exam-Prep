#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int _data, Node* _next, Node* _prev)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};


class DoublyList {
public:
    DoublyList(){
        head = NULL;
        tail = NULL;
    }
    Node* head;
    Node* tail;

    void insert(int x)
    {
        if(head == NULL)
        {
            head = new Node(x, NULL, NULL);
            return;
        }

        Node* tmp ;
        for(tmp = head; tmp->next; tmp = tmp->next);

        tmp->next = new Node(x, NULL, tmp);
    }

    void printList()
    {
        for(Node* tmp = head; tmp; tmp = tmp->next)
        {
            cout<<"Val: "<<tmp->data<<endl;
            cout<<"Prev: "<<tmp->prev<<endl;
            cout<<"Here: "<<tmp<<endl;
            cout<<"Next: "<<tmp->next<<endl;
        }
    }

};


int main()
{
    DoublyList dl;
    cout<<"ss"<<endl;

    dl.insert(5);
    dl.insert(4);
    dl.insert(10);

    cout<<"ss"<<endl;
    dl.printList();

    cout<<"ss"<<endl;
}
