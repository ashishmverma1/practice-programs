//Author: Ashish Verma
//D/T: 21-Aug-2014, 10:23PM
//
//Given a linked list, write a function to reverse every k nodes (where k is an input to the function).
//Example:
//Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
//Output:  3->2->1->6->5->4->8->7->NULL. 
//Inputs:   1->2->3->4->5->6->7->80->NULL and k = 5
//Output:  5->4->3->2->1->8->7->6->NULL. 

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node **head, int dat);
void display(node **head);
void rotate(node **head, int k);
void reverse(node **head);

int main()
{
    int k;
    node *head = NULL;
    
    char input[100];
    cin>>input;
    
    for(int i=0; input[i] != '\0'; i++)
    {
        if(input[i] >= 48 && input[i] <= 57)
        {
            insert(&head, input[i] - 48);
        }
    }
    
    cin>>k;
    rotate(&head, k);
        
    display(&head);
    
    return 0;
}

void insert(node **head, int dat)
{
    node *newNode = new node();
    newNode->data = dat;
    newNode->next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    node *temp;
    temp = *head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(node **head)
{
    if(*head == NULL)
    {
        cout<<"Empty!"<<endl;
        return;
    }
    
    node *temp;
    temp = *head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void rotate(node **head, int k)
{
    if(*head == NULL)
    {
        return;
    }
    
    bool curHead = true;
    
    node *prev, *next, *cur, *start, *temp;
    prev = NULL;
    cur = *head;
    
    int count;
    
    while(cur != NULL)
    {
        count = k;
        start = cur;
        
        while(count>1 && cur->next != NULL)
        {
            cur = cur->next;
            count--;
        }
        
        next = cur->next;
        cur->next = NULL;
        temp = start;
        reverse(&temp);
        
        if(curHead)
        {
            *head = cur;
            curHead = false;
            start->next = next;
        }
        else
        {
            start->next = next;
            if(prev != NULL)
            {
                prev->next = cur;
            }
        }
        
        prev = start;
        cur = next;
    }
}

void reverse(node **head)
{
    if(*head == NULL)
    {
        return;
    }
    
    node *prev, *cur, *next;
    prev = NULL;
    cur = *head;
    
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
