/* 
 * Max possible sum of elem of array such that no two elem are consecutive
 * Author: Ashish Verma
 *
 * Created on Aug 1, 2013, 3:16PM
 */

#include <stdio.h>

int main()
{
    int a[6]={786,989,678,10,999,85}, i;
    int incl, excl, incl_n;

    incl=a[0];
    excl=0;

    for(i=1;i<=6;i++)
    {
        incl_n=(incl>excl)?incl:excl;
        incl=excl+a[i];
        excl=incl_n;
    }
	
    incl=(incl>excl)?incl:excl;
    printf("Max sum = %d",incl);

    return 0;
}

