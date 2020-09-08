#include "search_algos.h"

/**
 * print_array - prints the array after each iteration
 * @array: array to print
 * @start: first index to print
 * @end: last index to print
 */
void print_array(int *array, int start, int end)
{
	int temp;

	printf("Searching in array: ");

	for (temp = start; temp <= end; temp++)
	{
		if (temp != start)
			printf(", ");
		printf("%d", array[temp]);
	}
	printf("\n");

}

/**
 * advanced_binary - uses binary search to find value in array
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: index of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	int first, middle, last;

	first = 0;
	last = (int) size - 1;
	middle = (first + last) / 2;

	if (array == NULL)
		return (-1);
	while (first <= last)
	{
		print_array(array, first, last);
		if (array[middle] < value)
			first = middle + 1;
		else
			last = middle - 1;
		if (array[middle] == value)
		{
			if (array[middle - 1] == value)
				last = middle;
			else
				return (middle);
		}
		middle = (first + last) / 2;
	}
	return (-1);
}
