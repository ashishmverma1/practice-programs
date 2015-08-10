/* 
 * Title: Illustration of #define as a function
 * Author: Ashish Verma
 * Created on March 18, 2013, 1:17 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define swap(x,y) x=x+y; y=x-y; x=x-y;

int main()
{
    char a='a',b='b';
    swap(a,b);
    printf("a=%c, b=%c",a,b);
    return 0;
}
