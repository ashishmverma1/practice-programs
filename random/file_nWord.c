#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("temp.txt", "w+");
    
    char string[10000] = "More data types makes programming easier but too many data types might be confusing\0";
    fputs(string, f);
    fseek(f, 0, SEEK_SET);
    
    char search[100], temp[100];
    gets(search);
    
    int count = 0;
    
    while(EOF != fscanf(f, "%s", temp))
        if(strcmp(temp, search) == 0) count++;     
    
    if(count != 0)
        printf("\nNumber of occurrences: %d", count);
    else
        printf("\nNot found");
    
    fclose(f);  
    return 0;
}
