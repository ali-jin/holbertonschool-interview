#include "sort.h"

/**
 * merge - Merge two subarrays of array[]
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @start: Start index
 * @mid: Middle index
 * @end: End index
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = start;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < end)
		temp[k++] = array[j++];

	for (i = start; i < end; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @start: Start index
 * @end: End index
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = start + (end - start) / 2;
	merge_sort_recursive(array, temp, start, mid);
	merge_sort_recursive(array, temp, mid, end);
	merge(array, temp, start, mid, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
