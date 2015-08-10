/* 
 * Title: Searching an element in an array
 * Author: Ashish Verma
 * Adm. No.: 2012-JE-0804
 * Section: D
 * Created on March 11, 2013, 12:05 AM
 */

#include <stdio.h>

int main()
{
    int ar[10],i,e;
    
    printf("Input an array of size 10 (each element should be unique):\n");
    for(i=0;i<10;i++)scanf("%d",&ar[i]);
    
    printf("\n\nInput an element to be searched for: ");
    scanf("%d", &e);
    
    //searching in array
    for(i=0;i<10;i++) if(ar[i]==e)break;
    
    printf("\n\nThe element %d is present at the location %d in the array.", e, i);
    
    return 0;
}