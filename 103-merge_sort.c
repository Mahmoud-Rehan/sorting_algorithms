#include "sort.h"


/**
 * merge_sort - Sorts an array of integers using MERGE SORT.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;
	size_t i;

	buffer = (int *)malloc(sizeof(int) * size - 1);

	if (buffer == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		buffer[i] = array[i];
	}

	separate_array(buffer, 0, size, array);
	free(buffer);
}


/**
 * separate_array - Separate the array to complete the sorting.
 * @buffer: Buffer of the array.
 * @start: The first position in the array.
 * @size: The size of the array.
 * @array: The original array.
 */

void separate_array(int *buffer, int start, size_t size, int *array)
{
	int middle;

	if (size - start < 2)
		return;

	middle = (size + start) / 2;

	separate_array(array, start, middle, buffer);
	separate_array(array, middle, size, buffer);

	merge(buffer, size, start, middle, array);
}


/**
 * merge - Merges the values in the subarray.
 * @array: The array.
 * @size: The size of the buffer.
 * @start: The first position in the array.
 * @middle: The middle position.
 * @buffer: Buffer of the array.
 */

void merge(int *array, int size, int start, int middle, int *buffer)
{
	int i, j, n;


	print_subarray(array, size, start, middle);

	i = start;
	j = middle;


	printf("[Done]: ");
	n = start;

	while (n < size)
	{
		if (i < middle && (j >= size || array[i] <= array[j]))
		{
			buffer[n] = array[i];
			i++;
		}
		else
		{
			buffer[n] = array[j];
			j++;
		}

		if (n < (size - 1))
		{
			printf("%d, ", buffer[n]);
		}
		else
		{
			printf("%d\n", buffer[n]);
		}
		n++;
	}
}


/**
 * print_subarray - Print the left and right subarrays.
 * @array: The array to print.
 * @size: the size of the array.
 * @start: The first position.
 * @middle: The middle position.
 */

void print_subarray(int *array, int size, int start, int middle)
{
	int n;

	printf("Merging...\n");
	printf("[left]: ");

	n = start;

	while (n < middle)
	{
		if (n != middle - 1)
		{
			printf("%d, ", array[n]);
		}
		else
		{
			printf("%d\n", array[n]);
		}
		n++;
	}

	printf("[right]: ");

	n = middle;

	while (n < size)
	{
		if (n < size - 1)
		{
			printf("%d, ", array[n]);
		}
		else
		{
			printf("%d\n", array[n]);
		}
		n++;
	}
}
