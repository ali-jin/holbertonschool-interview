#include "palindrome.h"

/**
 * is_palindrome - checks if unsigned integer is a palindrome
 * @n: Integer to check
 * Return: return 1 if n is a palindrome, or 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long remainder, original;
	unsigned long reversed = 0;

	original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	if (original == reversed)
		return (1);
	return (0);
}
