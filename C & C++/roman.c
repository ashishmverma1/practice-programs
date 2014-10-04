/* 
 * Title: Decimal to Roman numeral conversion
 * Author: Ashish Verma
 * Created on April 12, 2013, 5:06 PM
 */

#include <stdio.h>

int main()
{
     int num,a,i;

     printf("Input a number (<4000): ");
     scanf("%d",&num);

     printf("\nThe Roman number equivalent of %d is: ",num);

     //For thousands place
     a=num/1000;
     for(i=1;i<=a && a<=3 && a>0; i++) printf("M");

     //For hundreds place
     a=(num%1000)/100;
     if(a>=1 && a<=3) for(i=1;i<=a;i++) printf("C");
     if(a==4) printf("CD");
     if(a==5) printf("D");
     if(a>=6 && a<=8)
     {
         printf("D");
         a-=5;
         for(i=1;i<=a;i++) printf("C");
     }
     if(a==9) printf("CM");
     
     //For tens place
     a=(num%100)/10;
     if(a>=1 && a<=3) for(i=1;i<=a;i++) printf("X");
     if(a==4) printf("XL");
     if(a==5) printf("L");
     if(a>=6 && a<=8)
     {
         printf("L");
         a-=5;
         for(i=1;i<=a;i++) printf("X");
     }
     if(a==9) printf("XC");
     
     //For ones place
     a=num%10;
     if(a>=1 && a<=3) for(i=1;i<=a;i++) printf("I");
     if(a==4) printf("IV");
     if(a==5) printf("V");
     if(a>=6 && a<=8)
     {
         printf("V");
         a-=5;
         for(i=1;i<=a;i++) printf("I");
     }
     if(a==9) printf("IX");
     
     return 0;
}