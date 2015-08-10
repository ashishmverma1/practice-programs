/*
 * Program to traverse graph using BFS
 */

#include <iostream>
using namespace std;

int queue[100];
int front = -1, rear = -1;
void insertQ(int data)
{
    if(front == -1)
    {
        front = rear = 0;
        queue[front] = data;
    }
    else
        queue[++rear] = data;
}
int deleteQ()
{
    if(front == rear)
    {
        int temp  = queue[front];
        front = rear = -1;
        return temp;
    }        
    return queue[front++];
}

const int size = 8;

void BFS(int adj[][size])
{
    int state[size];
    for(int i=0; i<size; i++) state[i] = 1;
    int frontNode;
    insertQ(0);
    state[0] = 2;
    
    while(front != -1)
    {
        frontNode = deleteQ();
        state[frontNode] = 3;
        cout<<"\t"<<frontNode + 1;
        
        for(int i=0; i<size; i++)
            if(adj[frontNode][i] == 1 && state[i] == 1)
            {
                insertQ(i);
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
    
    cout<<"\nBFS is:\n";
    BFS(adj);
    return 0;
}