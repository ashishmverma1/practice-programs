/* 
 * prog. to find LCM, HCF
 * Author: Ashish Verma
 *
 * Created on February 14, 2013, 3:58 AM
 */

#include <stdio.h>

int LCM(int,int);
int HCF(int,int);

int main()
{
    int a,b,c;
    
    printf("Input two numbers : ");
    scanf("%d%d",&a,&b);
    
    printf("\n\nThe HCF is : %d",HCF(a,b));
    printf("\nThe LCM is : %d\n",LCM(a,b));
    
    return 0;
}

int HCF(int x, int y)
{
    int i, m=1,flag=0;
    for(i=2;i<=((x>y)?x:y);i++)
    {
        if(flag==1)i--;
        if((x%i)==0 && (y%i)==0)
        {
            x/=i;       y/=i;
            m*=i;
            flag=1;
        }
        else flag=0;
    }
        
    return m;
}
/*
 * using the formula
 * 
int LCM(int x, int y)
{
    return ((x*y)/HCF(x,y));
}
 */

//using logic
int LCM(int x, int y)
{
    int i, m=1, flag=0;
    
    for(i=2;i<=((x>y)?x:y);i++)
    {
        if(flag==1)i--;
        if((x%i)==0 && (y%i)==0)
        {
            x/=i;       y/=i;
            m*=i;
            flag=1;
        }
        else if((x%i)==0 && (y%i)!=0)
        {
            x/=i;
            m*=i;
            flag=1;
        }
        else if((x%i)!=0 && (y%i)==0)
        {
            y/=i;
            m*=i;
            flag=1;
        }
        else flag=0;
    }
    
    return m;
}