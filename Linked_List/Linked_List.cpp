#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int _data, Node* _next)
    {
        data = _data;
        next = _next;
    }
};


class List {
public:
    List(){
        head = NULL;
    }

    Node* head;

    bool isEmpty() { return head == NULL; };

    void insertNode(int index, int x)
    {
        if (index < 0) return;
        Node* currNode = head;

        for(int curr=1; currNode!=NULL && curr<=index; curr++)
        {
            currNode = currNode->next;
        }

        Node* newNode = new Node(x, NULL);

        if(index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
        return;
    }

    Node* findLast()
    {
        Node* curr = head;
        for(; curr->next!=NULL; curr = curr->next);
        return curr;
    }

    void insertLast(int x)
    {
        if(head == NULL)
        {
            head = new Node(x, NULL);
            return;
        }

        Node* currLast = findLast();
        Node* newNode = new Node(x, NULL);
        currLast->next = newNode;
    }

    void insertAfter(int after, int x)
    {
        Node* curr = findNode(after);
        if(curr)
        {
            Node* newNode = new Node(x, curr->next);
            curr->next = newNode;
        }
    }

    void insertBefore(int before, int x)
    {
        Node* curr = head;

        for(; curr->next!=NULL; curr = curr->next)
        {
            if(curr->next->data == before)
            {
                Node* newNode = new Node(x, curr->next);
                curr->next = newNode;
                return;
            }
        }
    }

    Node* findNode(int x)
    {
        Node* curr = head;

        for(; curr!=NULL; curr = curr->next)
        {
            if(curr->data == x)
            return curr;
        }

        return NULL;


    }

    void deleteNode(int x)
    {
        Node* curr = head;
        if(head->data == x)
        {
            head = head->next;
            return;
        }
        for(; curr->next!=NULL; curr = curr->next)
        {
            if(curr->next->data == x)
            {
                curr->next = curr->next->next;
                return;
            }
        }
    }

    void deleteNode(Node* delNode)
    {
        if(head == delNode)
        {
            head = head->next;
            return;
        }


        Node* curr = head;

        for(; curr->next!=NULL; curr = curr->next)
        {
            if(curr->next == delNode)
            {
                curr->next = curr->next->next;
                return;
            }
        }
        return;
    }

    void deleteBefore(int before)
    {
        Node* curr = head;

        if(head->next->data == before)
        {
            head = head->next;
            return;
        }

        for(; curr->next->next!=NULL; curr = curr->next)
        {
            if(curr->next->next->data == before)
            {
                curr->next = curr->next->next;
                return;
            }
        }

    }

    void displayList()
    {
        Node* curr = head;

        for(; curr!=NULL; curr = curr->next)
        {
            cout<<curr->data<<endl;
        }
    }

    void reverseList()
    {
        reverse(head);
    }

    void reverse(Node *p)
	{
        if(p->next == NULL)
		{
			head = p;
			return;
		}

		reverse(p->next);

		Node *q = p->next;
		q->next = p;
		p->next = NULL;

	}
};


int main()
{
    List ll;

    cout<<"EMPTY HEHE: "<<ll.isEmpty()<<endl;

    ll.insertLast(1);
    ll.insertLast(2);
    ll.insertLast(3);
    ll.insertLast(4);
    ll.insertLast(5);
    ll.insertLast(6);

    ll.displayList();

    // cout<<ll.findNode(2)->data<<endl;

    ll.deleteNode(2);
    cout<<"AFTER DELETING 2"<<endl;
    ll.displayList();


    ll.insertLast(10);
    cout<<"AFTER INSERTING 10"<<endl;
    ll.displayList();

    cout<<"AFTER DELETING BEFORE 3 (WHEN HEAD ER NEXT E)"<<endl;
    ll.deleteBefore(3);
    ll.displayList();

    cout<<"AFTER DELETING BEFORE 10"<<endl;
    ll.deleteBefore(10);
    ll.displayList();

    cout<<"AFTER DELETING BEFORE 5"<<endl;
    ll.deleteBefore(5);
    ll.displayList();


    ll.reverseList();
    cout<<"AFTER REVERSING"<<endl;

    ll.displayList();

    return 0;
}
