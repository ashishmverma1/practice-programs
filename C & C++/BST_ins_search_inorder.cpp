// program to insert, search in BST and display using inorder

#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *lptr;
    node *rptr;
};

void inorder(node *root);
void BSTinsert(int, node **);
void BSTsearch(int, node *);

node *stack[100];
int top = -1;
void push(node *data)
{
    if(top<100)
        stack[++top] = data;
}
node *pop()
{
    if(top>=0)
        return stack[top--];
    return NULL;
}
node *peek()
{
    if(top>=0)
        return stack[top];
    return NULL;
}

int main()
{ 
    node *root = NULL;
    BSTinsert(38, &root);
    BSTinsert(14, &root);
    BSTinsert(8, &root);
    BSTinsert(23, &root);
    BSTinsert(18, &root);
    BSTinsert(56, &root);
    BSTinsert(45, &root);
    BSTinsert(82, &root);
    BSTinsert(70, &root);
    
    inorder(root);
    
    BSTsearch(2, root);
    BSTsearch(70, root);
    
    return 0; 
}

void inorder(node *root)
{
    if(root == NULL)
    {
        cout<<"\nThe tree is empty!";
        return;
    }
    
    if(root->lptr != NULL) inorder(root->lptr);
    cout<<"\nData: "<<root->data;
    if(root->rptr != NULL) inorder(root->rptr);
}

void BSTinsert(int val, node **root)
{
    node *p = new node;
    p->data = val;
    p->lptr = NULL;
    p->rptr = NULL;
    if(*root == NULL)
    {
        *root = p;
        return;
    }
    
    node *curr = *root;
    node *prev;
    while(curr != NULL)
    {
        prev = curr;
        if(val < curr->data)
            curr = curr->lptr;
        else
            curr = curr->rptr;
    }

    if(val < prev->data)
        prev->lptr = p;
    else
        prev->rptr = p;    
}

void BSTsearch(int val, node *root)
{
    while(root != NULL)
    {
        if(val < root->data)
        {
            root = root->lptr;
        }
        else if(val > root->data)
        {
            root = root->rptr;
        }
        else
        {
            cout<<"\n"<<val<<" is present";
            return;
        }
    }
    cout<<"\n"<<val<<" is not present";
}
