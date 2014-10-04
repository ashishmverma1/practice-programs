/*
 * Program to perform following on linked list:
 * insert, delete, display
 * reverse, merge
 */

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void insert(int val, node **head);
void display(node *head);
void del(int val, node **head);
void reverse(node **head);

int main()
{
    int ch = 1, val;
    node *head = NULL;
    while(ch)
    {
        cout<<"\n\n1.ins \n2.dis \n3.del \n4.rev \nCh:";
        cin>>ch;
        if(ch == 1)
        {
            cin>>val;
            insert(val, &head);
        }
        if(ch == 2)display(head);
        if(ch == 3)
        {
            cin>>val;
            del(val, &head);
        }
        if(ch == 4) reverse(&head);
    }
    
    return 0;
}

void insert(int val, node **head)
{
    node *p = new node;
    node *n = *head;;
    p->data = val;
    p->next = NULL;
    if(*head == NULL)
        *head = p;
    else
    {
        while(n->next != NULL)
        {
            n = n->next;
        }
        n->next = p;
    }
}

void display(node *head)
{
    if(head == NULL)
        cout<<"\nEmpty";
    else
        while(head != NULL)
        {
            cout<<"\t"<<head->data;
            head = head->next;
        }
}

void del(int val, node **head)
{
    node *prev = NULL, *p = *head;
    while(p != NULL)
    {
        if(p->data == val)
        {
            if(prev == NULL)
            {
                *head = NULL;
                return;
            }
            
            prev->next = p->next;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void reverse(node **head)
{
    if(*head == NULL)
        return;
    
    node *prev, *curr, *next;
    prev = NULL;
    curr = *head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
