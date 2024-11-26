#include "sort.h"

/**
 * getMax - Get maximum value in an array
 *
 * @array: The arrayay to search
 * @size: Number of elements in @array
 *
 * Return: The maximum value in @array
 */
int getMax(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * countSort - Sort an array of integers according to the digit represented by
 *             @exp
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 * @exp: The digit to sort by
 */
void countSort(int *array, size_t size, int exp)
{
	int *output;
	int count[10];
	size_t i;
	int index;

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		return;
	}

	for (i = 0; i < 10; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		index = (array[i] / exp) % 10;
		count[index]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		index = (array[i] / exp) % 10;
		output[count[index] - 1] = array[i];
		count[index]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order using the radix
 *              sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (array == NULL || size < 2)
	{
		return;
	}

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
