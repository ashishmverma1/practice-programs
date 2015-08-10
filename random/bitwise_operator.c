/*
* program illustrating the use of
* bitwise operators to find sum of
* two numbers
*
* Author: Ashish Verma
* Created on 10 February, 2013, 3:34 AM
*/

#include <stdio.h>
 
int main()
{
	unsigned int x=3, y=1, sum, carry;
	sum = x ^ y; // Ex - OR x and y
	carry = x & y; // AND x and y
	while(carry != 0) // enter the loop 
	{
		carry = carry << 1; // left shift the carry
		x = sum; // initialize x as sum
		y = carry; // initialize y as carry
		sum = x ^ y; // sum is calculated
		carry = x & y; // carry is calculated and loop condition is checked and the process repeated until carry = 0.
	}
	printf("%d\n", sum); // the program will print 4
	return 0;
}