/*
 * Program to insertion sort
 */

#include <iostream>
using namespace std;
const int size = 10;

void sort(int a[])
{
    int temp, i, j;
    for(i = 1; i<size; i++)
    {
        j = i - 1;
        temp = a[i];
        for(j; temp<a[j] && j>=0; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}

int main()
{
    int array[size];
    
    cout<<"Enter adjacency matrix: ";
    for(int i=0; i<size; i++)
            cin>>array[i];  
    
    cout<<"\nBefore:\n";
    for(int i=0; i<size; i++)
            cout<<array[i];  
    
    sort(array);
    
    cout<<"\n\nAfter:\n";
    for(int i=0; i<size; i++)
            cout<<array[i];  
    return 0;
}