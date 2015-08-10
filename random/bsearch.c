#include <stdio.h>
#include <conio.h>
int main()
{
    int cnt = 0,n;
    printf("Enter the number of elements of array=");
    scanf("%d",&n);
    int pos,hi,lo,mid,i,x,a[n];
    for(i=0;i<n;i++)
                    scanf("%d",&a[i]);
    printf("Enter the element to be searched");
    scanf("%d",&x);
    hi=n;
    lo=0;
    while(hi>=lo)
    {
                mid=(hi+lo)/2;
                if(a[mid]>x)
                            hi=mid-1;
                else if(a[mid]<x)
                     lo=mid+1;
                else
                {
                    pos=mid+1;
                    cnt++;
                    break;
                }
    }
    if(cnt==0)
    {
              printf("Element not found");
              }
              else
              printf("Position=%d",pos);getch();
              return 0;
}
