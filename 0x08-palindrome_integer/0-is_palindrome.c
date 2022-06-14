#include "palindrome.h"
/**
 * is_palindrome - Function that checks whether or not
 * a given unsigned integer is a palindrome
 * @n: Unsigned integer to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    int remainder;
    int temp = n;
    int rev = 0;

    while (n != 0)
    {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    if (rev == temp)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
