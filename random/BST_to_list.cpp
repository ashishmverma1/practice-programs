/*
 * Program to convert BST to doubly linked list
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

void newListNode(node **head, int val)
{
    node *p = new node;
    node *temp;
    p->data = val;
    if(*head == NULL)
    {
        p->lptr = NULL;
        p->rptr = NULL;
        *head = p;
    }
    else
    {
        temp = *head;
        while(temp->rptr != *head && temp->rptr != NULL)
        {
            temp = temp->rptr;
        }
        temp->rptr = p;
        p->lptr = temp;
        p->rptr = *head;
        (*head)->lptr = p;
    }
}

void convert(node **headList, node **headBST)
{
    if(headBST == NULL)
        return;
    
    if((*headBST)->lptr != NULL) convert(headList, &((*headBST)->lptr));
    newListNode(headList, (*headBST)->data);
    if((*headBST)->rptr != NULL) convert(headList, &((*headBST)->rptr));
}

void inorder(node *head)
{
    if(head == NULL)
        return;
    
    inorder(head->lptr);
    cout<<"\t"<<head->data;
    inorder(head->rptr);
}

void traverseList(node *head)
{
    node *temp = head->rptr;
    if(head->rptr == NULL)
        return;
    while(temp != head)
    {
        cout<<"\t"<<temp->data;
        temp = temp->rptr;
    }
}

int main()
{
    node *head;
    node *headList;
    head = newnode(4);
    head->lptr = newnode(2);
    head->rptr= newnode(5);
    head->lptr->lptr = newnode(1);
    head->lptr->rptr = newnode(3);
    
    cout<<"\nInorder:\n";
    inorder(head);
    
    convert(&headList, &head);
    
    cout<<"\n";
    traverseList(headList);
    
    return 0;
}
