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
    node *lptr;
    node *rptr;
};

node *newnode(int val)
{
    node *p = new node;
    p->lptr = NULL;
    p->rptr = NULL;
    p->data = val;
    return p;
}

void mirror(node *head)
{
    if(head == NULL)
        return;
    mirror(head->lptr);
    mirror(head->rptr);
    
    node *temp;
    temp = head->lptr;
    head->lptr = head->rptr;
    head->rptr = temp;
}

void inorder(node *head)
{
    if(head == NULL)
        return;
    
    inorder(head->lptr);
    cout<<"\t"<<head->data;
    inorder(head->rptr);
}

int main()
{
    node *head;
    head = newnode(1);
    head->lptr = newnode(2);
    head->rptr= newnode(3);
    head->lptr->lptr = newnode(4);
    head->lptr->rptr = newnode(5);
    
    cout<<"\nInorder:\n";
    inorder(head);
    mirror(head);
    cout<<"\n";
    inorder(head);
    
    return 0;
}
