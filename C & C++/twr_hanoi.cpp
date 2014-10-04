/* 
 * Title: Tower of hanoi using stack
 * Author: Ashish Verma
 * Created on September 17, 2013, 12:29 AM
 */

#include <stdio.h>
#include <stdlib.h>

class peg
{
    public:
    int stick[100];
    int top;
    
    peg()
    {
        top = -1;
    }
    
    void push(int e)
    {
        stick[++top] = e;
    }
    
    int pop()
    {
        return stick[top--];
    }
};

int steps = 0;

void tower(int n, peg *source, peg *inter, peg *dest)
{
    if(n>0)
    {
        steps++;
        tower(n-1, source, dest, inter);
        dest->push(source->pop());
        tower(n-1, inter, source, dest);    
    }
}



int main()
{
    peg A, B, C;
    int i;
    
    //Initialize A
    A.push(4);
    A.push(3);
    A.push(2);
    A.push(1);
    
    printf("\nThe contents of A are:\n");
    for(i=0; i<=A.top; i++) printf("%d  ", A.stick[i]);
        
    tower(4, &A, &B, &C);
    
    if(A.top == -1)
        printf("\n\nA is empty");
    else
    {
            printf("\n\nThe contents of A are:\n",A.top);
            for(i=0; i<=A.top; i++) printf("%d  ", A.stick[i]);
    }
    
    if(C.top == -1)
        printf("\n\nC is empty");
    else
    {
            printf("\n\nThe contents of C are:\n");
            for(i=0; i<=C.top; i++) printf("%d  ", C.stick[i]);
    }
    
    printf("\n\nNumber of steps taken: %d", steps);
    
    return 0;
}
