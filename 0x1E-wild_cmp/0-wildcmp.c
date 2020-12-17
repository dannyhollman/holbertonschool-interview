#include "holberton.h"

/**
 * wildcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 1 if strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return ((wildcmp(s1, s2 + 1)) || (wildcmp(s1 + 1, s2)));
	return (0);
}
