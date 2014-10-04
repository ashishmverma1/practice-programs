/*
 * Program to traverse graph using DFS
 */

#include <iostream>
using namespace std;

int stack[100];
int top = -1, rear = -1;
void push(int data)
{
    stack[++top] = data;
}
int pop()
{
    return stack[top--];
}

const int size = 8;

void DFS(int adj[][size])
{
    int state[size];
    for(int i=0; i<size; i++) state[i] = 1;
    int frontNode;
    push(0);
    state[0] = 2;
    
    while(top != -1)
    {
        frontNode = pop();
        state[frontNode] = 3;
        cout<<"\t"<<frontNode + 1;
        
        for(int i=0; i<size; i++)
            if(adj[frontNode][i] == 1 && state[i] == 1)
            {
                push(i);
                state[i] = 2;
            }
    }
}

int main()
{
    int adj[size][size];
    
    cout<<"Enter adjacency matrix: ";
    for(int i=0; i<size; i++)
        for(int j = 0; j<size; j++)
            cin>>adj[i][j];  
    
    cout<<"\nDFS is:\n";
    DFS(adj);
    return 0;
}