//Author: Ashish Verma
//D/T: 5-Sep-2014, 12:10 AM
// Prog to check for anagram/palindrome b/w pattern - string


#include <iostream>
using namespace std;

bool compare(int *s1, int *s2);
void hash(char *s, int *count);

int main()
{
    int wcount[26], tcount[26], wlen, tlen, ptr, k, j;
    
    bool present;
    
    char word[100], text[1000], buff[100];
    cin>>word>>text;
    
    wlen = strlen(word);
    tlen = strlen(text);
    
    hash(word, wcount);
    
    for(int i=0; i<tlen; i++)
    {
        
        for(j=i, k=0; j<wlen+i; j++) buff[k++] = text[j];
        buff[k] = '\0';
        
        hash(buff, tcount);
        present = compare(wcount, tcount);
        
        if(present)
        {
            cout<<"\nPresent at: "<<i;
        }
    }
    
    return 0;
}

bool compare(int *s1, int *s2)
{
    for(int i=0; i<26; i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}

void hash(char *s, int *count)
{
    for(int i=0; i<26; i++) count[i] = 0;
    
    for(int i=0; s[i] != '\0'; i++)
    {
        count[s[i] - 97]++;
    }
}
