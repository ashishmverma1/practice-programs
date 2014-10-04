/* 
 * Title: Sorting an array using bubble sort.
 * Author: Ashish Verma
 * Adm. No.: 2012-JE-0804
 * Section: D
 * Created on March 11, 2013, 12:01 AM
 */

#include <stdio.h>

int main()
{
    int ar[10],i,j,s;
    
    printf("Input an array of size 10:\n");
    for(i=0;i<10;i++)scanf("%d",&ar[i]);
    
    //bubble sort
    for(i=0;i<10;i++)
    {
       for(j=0;j<10;j++)
       {
           if(ar[j]>ar[j+1])
           {
               s=ar[j];
               ar[j]=ar[j+1];
               ar[j+1]=s;
           }
       }
    }
    
    printf("\n\nAfter sorting:\n\n");
    for(i=0;i<10;i++)printf("%d ",ar[i]);
    
    return 0;
}