/*
 * Brute force to make all possible combinations of n chars
 * 
 * Author: Ashish Verma
 * Created: 7:03 PM, Aug 07 2013  
 */

#include <stdio.h>

int len = 5;
char letters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int nbletters = sizeof(letters)-1;

int main() {
    int i, entry[len];
    FILE *f;
    f=fopen("brute.txt","w");
    for(i=0 ; i<len ; i++) entry[i] = 0;
    do {
        for(i=0 ; i<len ; i++) putc(letters[entry[i]],f);
        putc('\n',f);
        for(i=0 ; i<len && ++entry[i] == nbletters; i++) entry[i] = 0;
    } while(i<len);
    fcloseall();
    return 0;
}
