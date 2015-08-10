//Author: Ashish Verma
//D/T: 14-Oct-2014, 10:23PM
// Find substr in a str and reverse it

#include <iostream>
using namespace std;

int main()
{
    char str[1000], substr[999], swapper;
    bool isPresent = false;
    int start, end, l, m;
    
    cin>>str;
    cin>>substr;
    
    for(int i=0; str[i]!='\0' && !isPresent; i++)
    {
        l = i;
        m = 0;
        while(str[l] == substr[m])
        {
            if(substr[m+1] == '\0')
            {
                isPresent = true;
                start = i;
                end = l;
                break;
            }
            l++;
            m++;
        }
    }
    
    if(isPresent)
    {
        while(start < end)
        {
            swapper = str[start];
            str[start] = str[end];
            str[end] = swapper;
            start++;
            end--;
        }
        
        cout<<"YES"<<endl;
        cout<<str;
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}
