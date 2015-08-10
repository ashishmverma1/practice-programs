/*
 * Program to merge sort
 */

#include <iostream>
using namespace std;
const int size = 10;

void merge(int a[], int low, int mid, int high)
{
    int b[size];
    int i1 = low, i2 = mid + 1;
    int j = low;
    while(i1 <= mid && i2 <= high)
    {
        if(a[i1] >= a[i2])
        {
            b[j] = a[i2];
            j++;
            i2++;
        }
        else
        {
            b[j] = a[i1];
            j++;
            i1++;
        }
    }
    if(i1 > mid)
        while(i2 <= high)
        {
            b[j] = a[i2];
            j++;        i2++;
        }
    else
        while(i1 <= mid)
        {
            b[j] = a[i1];
            j++;        i1++;
        }
    
    for(j = low; j<high; j++)
        a[j] = b[j];
}

void sort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (high+low)/2;
        sort(a, low, mid);
        sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int array[size];
    
    cout<<"Enter array: ";
    for(int i=0; i<size; i++)
            cin>>array[i];  
    
    cout<<"\nBefore:\n";
    for(int i=0; i<size; i++)
            cout<<array[i];  
    
    sort(array, 0, size-1);
    
    cout<<"\n\nAfter:\n";
    for(int i=0; i<size; i++)
            cout<<array[i];  
    return 0;
}
