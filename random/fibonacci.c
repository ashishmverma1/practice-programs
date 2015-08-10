/* 
 * Title: Print a Fibonacci series
 * Author: Ashish Verma
 * Adm. No.: 2012-JE-0804
 * Section: D
 * Created on March 11, 2013, 12:08 AM
 */

#include <stdio.h>

int main()
{
    int a[20],i,n;
    
    a[0]=0;     a[1]=1;
    
    printf("Input the number of terms upto which Fibonacci series is to be printed (maximum of 20 terms): ");
    scanf("%d",&n);
     
    //Fibonacci series
    for(i=2;i<n;i++) a[i]=a[i-1]+a[i-2];
    
    printf("\n\nThe Fibonacci series upto %d terms is:\n\n", n);
    
    for(i=0;i<n;i++) printf("%d ", a[i]);
    
    return 0;
}