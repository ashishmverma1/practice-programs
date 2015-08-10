#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    char infix[400], temp[100];
    int topTemp;
    while(t--)
    {
        cin>>infix;
        topTemp = 0;
        
        for(int i=0; infix[i] != '\0'; i++)
        {
            if(infix[i] == '(')
                continue;
            else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^')
                temp[topTemp++] = infix[i];
            else if(infix[i] == ')')
                cout<< temp[--topTemp];
            else
                cout<< infix[i];
        }
        cout<< endl;
    }  
    return 0;
}
