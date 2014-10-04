/* 
 * prog. to evaluate simple mathematical expressions
 * Author: Ashish Verma
 *
 * Created on February 15, 2013, 3:16 AM
 */

#include <stdio.h>

int pow(int,int);

int main()
{
    char exp[100],opr;
    int i,j=0,a=0,b=0,c,len,flag=0;
    
    printf("Enter the expression : \n\n\t");
    gets(exp);
    
    for(len=0;exp[len]!='\0';len++);
        
    for(i=len-1; i>=0; i--)
    {
        if(exp[i]>='0' && exp[i]<='9' && flag==0)
        {
           b+= pow(10,j)*(exp[i]-48);
           j++;
        }
        
        if(exp[i]<48 && exp[i]!=' ')
        {
            opr=exp[i];
            flag=1;
            j=0;
        }
        
        if(exp[i]>='0' && exp[i]<='9' && flag==1)
        {
           a+= pow(10,j)*(exp[i]-48);
           j++;
        }
    }
    
    if     (opr=='+')c=a+b;
    else if(opr=='-')c=a-b;
    else if(opr=='*')c=a*b;
    else if(opr=='/')c=a/b;
    else if(opr=='%')c=a%b;
    else
    {
        printf("\n\nYou entered an invalid expression or operator!");
        return 0;
    }
    
    printf("\nThe evaluated expression is :\n\n\t%s=%d",exp,c);
               
    return 0;
}

int pow(int a, int b)
{
    int i,p=1;
    for(i=0;i<b;i++)p*=a;
    return p;
}