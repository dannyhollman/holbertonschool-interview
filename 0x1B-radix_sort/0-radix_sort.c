#include "sort.h"

/**
 * counting_sort - Sort array based on significant digit
 * @array: Input array
 * @size: Size of array
 * @exp: Current exponent
 */
void counting_sort(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output = malloc(sizeof(int) * size);
	int i;

	for (i = 0; i < (int)size ; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}
/**
 * radix_sort - Sort array using radix sort
 * @array: Input array
 * @size: Size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, i;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
