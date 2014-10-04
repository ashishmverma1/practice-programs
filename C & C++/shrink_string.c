/* 
 * program to shrink multiple alphabet in string
 * Author: Ashish Verma
 * Created on 8 February, 2013, 2:03 AM
 */

#include <stdio.h>

int main()
{
    char s1[100],s2[100];
    int i,f,a=0;
    
    printf("Input a string :\t");
    gets(s1);
    
    for(i=0;s1[i]!='\0';)
    {
        if(s1[i]==s1[i+1])
        {
            for(f=i;s1[f]==s1[f+1];f++);
            f=f+1-i;
            s2[a]=s1[i];
            a++;
            s2[a]=f+48;
            a++;
        }
        else
        {
            s2[a]=s1[i];
            a++;
            s2[a]='1';
            a++;
            f=1;
        }
        i+=f;
    }
    
    s2[a]='\0';
    
    printf("\n\nThe shrunk string is :\t");
    puts(s2);
    
    return 0;
}