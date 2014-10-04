//Author: Ashish Verma
//D/T: 5-Sep-2014, 12:10 AM
//Prog to do basic functions on BST such as:
//insert, search, inorder, preorder, postorder


#include <iostream>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};

void insert(node **head, int val);
bool search(node *head, int val);
void inorder(node *head);
void preorder(node *head);
void postorder(node *head);

int main()
{
    int val = 0;
    node *head = NULL;
    
    cout<<"Insert values: ";
    while(1)
    {
        cin>>val;
        if(val<0) break;
        insert(&head, val);
    }
    
    cout<<"\n\nInorder: \n";
    inorder(head);
    
    cout<<"\n\nPreorder: \n";
    preorder(head);
    
    cout<<"\n\nPostorder: \n";
    postorder(head);
    
    cout<<"\n\nEnter value to be searched: ";
    cin>>val;
    val = search(head, val);
    if(val) 
        cout<<"Present";
    else 
        cout<<"Not present";
    
    return 0;
}

void insert(node **head, int val)
{
    if(*head == NULL)
    {
        *head = new node;
        (*head)->val = val;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
    else
    {
        if(val>(*head)->val)
        {
            insert(&((*head)->right), val);
        }
        else
        {
            insert(&((*head)->left), val);
        }
    }
}

void inorder(node *head)
{
    if(head == NULL) return;
    
    inorder(head->left);
    cout<<head->val<<"  ";
    inorder(head->right);
}

void preorder(node *head)
{
    if(head == NULL) return;
    
    cout<<head->val<<"  ";
    inorder(head->left);
    inorder(head->right);
}

void postorder(node *head)
{
    if(head == NULL) return;
    
    inorder(head->left);
    inorder(head->right);
    cout<<head->val<<"  ";
}

bool search(node *head, int val)
{
    if(val == head->val)
    {
        return true;
    }
    else
    {
        if(val > head->val && head->right != NULL)
            return search(head->right, val);
        else if(val < head->val && head->left != NULL)
            return search(head->left, val);
        else
            return false;
    }  
}
