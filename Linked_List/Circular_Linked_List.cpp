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


class CircularList {
public:

    Node* head;

    CircularList(){
        head = NULL;
    }


    bool isEmpty() { return head == NULL; };

    void insertNode(int index, int x)
    {
        if (index < 0) return;
        Node* currNode = head;

        for(int curr=1; currNode!=head && curr<=index; curr++)
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
        for(; curr!=NULL; curr = curr->next)
        {
            if(curr->next == head)
            {
                return curr;
            }
        }
    }

    void insertLast(int x)
    {
        if(head == NULL)
        {
            head = new Node(x, head);
            head->next = head;
            return;
        }

        Node* currLast = findLast();
        Node* newNode = new Node(x, head);
        currLast->next = newNode;

    }

    // void insertAfter(int after, int x)
    // {
    //     Node* curr = findNode(after);
    //     if(curr)
    //     {
    //         Node* newNode = new Node(x, curr->next);
    //         curr->next = newNode;
    //     }
    // }
    //
    // void insertBefore(int before, int x)
    // {
    //     Node* curr = head;
    //
    //     for(; curr->next!=NULL; curr = curr->next)
    //     {
    //         if(curr->next->data == before)
    //         {
    //             Node* newNode = new Node(x, curr->next);
    //             curr->next = newNode;
    //             return;
    //         }
    //     }
    // }

    // Node* findNode(int x)
    // {
    //     Node* curr = head;
    //
    //     for(; curr!=NULL; curr = curr->next)
    //     {
    //         if(curr->data == x)
    //         return curr;
    //     }
    //
    //     return NULL;
    // }

    void updateHead(Node* newHead)
    {
        Node* curr = head;
        for(curr; curr->next!=head; curr = curr->next);
        curr->next = newHead;
    }

    void deleteNode(int x)
    {
        Node* curr = head;
        if(head->data == x)
        {
            updateHead(head->next);
            head = head->next;
            return;
        }
        for(; curr->next!=head; curr = curr->next)
        {
            if(curr->next->data == x)
            {
                curr->next = curr->next->next;
                return;
            }
        }
    }

    // void deleteNode(Node* delNode)
    // {
    //     if(head == delNode)
    //     {
    //         head = head->next;
    //         return;
    //     }
    //
    //     Node* curr = head;
    //
    //     for(; curr->next!=NULL; curr = curr->next)
    //     {
    //         if(curr->next == delNode)
    //         {
    //             curr->next = curr->next->next;
    //             return;
    //         }
    //     }
    //     return;
    // }

    // void deleteBefore(int before)
    // {
    //     Node* curr = head;
    //
    //     if(head->next->data == before)
    //     {
    //         head = head->next;
    //         return;
    //     }
    //
    //     for(; curr->next->next!=NULL; curr = curr->next)
    //     {
    //         if(curr->next->next->data == before)
    //         {
    //             curr->next = curr->next->next;
    //             return;
    //         }
    //     }
    //
    // }

    void displayList()
    {
        Node* curr = head;
        if(curr != NULL)
        {

            cout<<curr->data<<endl;
        }
        for(curr = curr->next; curr!=head; curr = curr->next)
        {
            cout<<curr->data<<endl;
        }
    }
    //
    // void reverseList()
    // {
    //     reverse(head);
    // }
    //
    // void reverse(Node *p)
	// {
    //     if(p->next == NULL)
	// 	{
	// 		head = p;
	// 		return;
	// 	}
    //
	// 	reverse(p->next);
    //
	// 	Node *q = p->next;
	// 	q->next = p;
	// 	p->next = NULL;
    //
	// }
};


int main()
{
    CircularList cll;

    cll.insertLast(1);

    cll.insertLast(2);
    cll.insertLast(3);
    cll.insertLast(4);
    cll.insertLast(5);
    cll.insertLast(6);
    cll.insertLast(7);
    cll.insertLast(8);

    cll.displayList();

    cll.deleteNode(5);
    cll.deleteNode(1);

    cll.displayList();

    return 0;
}
