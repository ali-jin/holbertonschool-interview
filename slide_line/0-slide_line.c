#include "slide_line.h"

/**
 * slide_line - slides an array to left or right to sum numbers
 *
 * @line: line of numbers to be checked
 * @size: size of array
 * @direction: left or right
 * Return: 1 if success or 0 if failed
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == 2)
		return (merge_line_left(line, size));
	if (direction == 1)
		return (merge_line_right(line, size));
	else
		return (0);
}

/**
 * merge_line_left - slide to the left to sum
 *
 * @line: line of numbers to be checked
 * @size: size of array
 * Return: 1 on success
 */
int merge_line_left(int *line, size_t size)
{
	int current = 0, next = 0;
	size_t i, index = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && current == 0)
			current = line[i];
		else if (current != 0 && line[i] != 0)
			next = line[i];

		if (current != 0 && next != 0)
		{
			if (current == next)
			{
				line[index++] = current + next;
				current = 0;
				next = 0;
			}
			else
			{
				line[index++] = current;
				current = next;
				next = 0;

				if (i == size - 1)
					line[index++] = current;
			}
		}
		if (current != next && i == size - 1)
			line[index++] = current;
	}
	for (i = index; i < size; i++)
		line[i] = 0;

	return (1);
}

/**
 * merge_line_right - slides an array to sum numbers
 *
 * @line: line of numbers to be checked
 * @size: size of array
 * Return: 1 on success
 */
int merge_line_right(int *line, size_t size)
{
	int current = 0, previous = 0;
	size_t i, index = size - 1;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && current == 0)
			current = line[i];
		else if (current != 0 && line[i] != 0)
			previous = line[i];
		if (current != 0 && previous != 0)
		{
			if (current == previous)
			{
				line[index--] = current + previous;
				current = 0;
				previous = 0;
			}
			else
			{
				line[index--] = current;
				current = previous;
				previous = 0;

				if (i == 0)
					line[index--] = current;
			}
		}
		else if (current != previous && i == 0)
			line[index--] = current;
	}
	for (i = 0; i < index + 1; i++)
		line[i] = 0;

	return (1);
}
