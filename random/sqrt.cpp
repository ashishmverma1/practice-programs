#include <cstdlib>
#include <iostream>

using namespace std;

float root(float num)
{
    float mod = 1;
    float ans=0;
    for(int i=0 ; i<1000000 ; i++)
    {
        if(ans*ans>num)
        {
            ans = ans - mod;
            mod = mod/10;
        }
        ans = ans + mod;
    }
    return ans;
}

int main() 
{
    float a;
    
    cout<<"Enter the number: ";
    cin>>a;
    cout<<"\n\nThe root of number is: "<<root(a);
    return 0;
}
