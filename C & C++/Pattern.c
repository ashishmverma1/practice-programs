/* 
 * prog. to display a pattern
 * Author: Ashish Verma
 *
 * Created on February 12, 2013, 1:41 AM
 */

#include <stdio.h>

int main()
{
    int i,j,n;
    
    printf("Enter a number : ");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++)
    {
        for(j=0;j<(2*n-i);j++) printf(" ");
        for(j=0;j<((2*i)-1);j++) printf("*");
        printf("\n");
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=0;j<(n-i);j++) printf(" ");
        for(j=0;j<i;j++) printf("*");
        for(j=0;j<(2*n-1);j++) printf(" ");
        for(j=0;j<i;j++) printf("*");
        printf("\n");
    }
    
    for(i=1;i<=(n-1);i++)
    {
        for(j=0;j<i;j++) printf(" ");
        for(j=(n-i);j>0;j--) printf("*");
        for(j=0;j<(2*n-1);j++) printf(" ");
        for(j=(n-i);j>0;j--) printf("*");
        printf("\n");
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=0;j<(n+i-1);j++) printf(" ");
        for(j=0;j<(2*n-(2*i-1));j++) printf("*");
        printf("\n");
    }
        
    return 0;
}