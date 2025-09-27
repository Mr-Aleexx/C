/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:
Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long reverse(long x)
{
	long res = 0;
	while (x != 0)
	{
		long digit = x % 10;
		x /= 10;
		
		// digit > 7 and digit < -8 beacause the digit is the last number (mod)
		// and the last number of MAX MIN is 7 and 8 (-8 for the negative inut) 
		if (res > LONG_MAX / 10 || (res == LONG_MAX / 10 && digit > 7))
			return 0;
		if (res < LONG_MIN / 10 || (res == LONG_MIN / 10 && digit < -8))
			return 0;

		res = res * 10 + digit;
	}
	return res;
}

int main () {
	long input;
	printf("Enter a int : ");
	scanf("%ld", &input);
	long output = reverse(input);
	printf("Output : %ld\n", output);
	return 0;
}
