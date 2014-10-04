/*
 * Program to selection sort
 */

#include <iostream>
using namespace std;
const int size = 10;

void sort(int a[])
{
    int temp, min;
    for(int i=0; i<size; i++)
    {
        min = i;
        for(int j=i; j<size; j++)
        {
            if(a[j]<a[min]) min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
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