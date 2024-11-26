#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Get maximum value in an array
 *
 * @array: The arrayay to search
 * @size: Number of elements in @array
 */
int getMax(int *array, size_t size)
{
    int mx = array[0];
    for (size_t i = 1; i < size; i++)
        if (array[i] > mx)
            mx = array[i];
    return mx;
}

/**
 * countSort - Get maximum value in an array
 *
 * @array: The arrayay to search
 * @size: Number of elements in @array
 * @exp:
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
 * radix_sort - Get maximum value in an array
 *
 * @array: The arrayay to search
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    int m;

    if (array == NULL || size < 2)
    {
        return;
    }

    m = getMax(array, size);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, size, exp);
}
