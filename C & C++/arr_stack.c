/* 
 * Title: Push, pop from a stack using simple arrays
 * Author: Ashish Verma
 * Created on March 11, 2013, 7:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

int push(int s[],int *a);
int pop(int s[],int *a);
int disp(int s[],int a);

int main()
{
    int stk[100],i,n=0,ch=0;
    
    while(ch!=4)
    {
        printf("\n\n\nWhat do you want to do? \n1)Push \n2)Pop \n3)Display stack \n4)Exit \nYour Choice: ");
        scanf("%d",&ch);
        
        if(ch==1)push(stk,&n);
        if(ch==2)pop(stk,&n);
        if(ch==3)disp(stk,n);
    }
    return 0;
}

int push(int s[],int *a)
{
    if(*a==100)
    {
        printf("\n\nStack Overflow");
        return 0;
    }
    
    printf("\n\nInput a number to be pushed: ");
    scanf("%d", &s[*a]);
    printf("\nPush successful.");
    (*a)++;
    
}

int pop(int s[],int *a)
{
    if(*a==0)
    {
        printf("\n\nStack Underflow");
        return 0;
    }
    
    printf("\n\nPopped value: %d",s[*a-1]);
    s[*a-1]=0;
    (*a)--;
}

int disp(int s[],int a)
{
    if(a==0)
    {
        printf("\n\nStack is empty");
        return 0;
    }
    
    int i;
    printf("\n\nContents of the stack are:\n");
    for(i=0;i<a;i++) printf("%d ",s[i]);
}