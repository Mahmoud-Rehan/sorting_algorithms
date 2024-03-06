#include "sort.h"


/**
 * quick_sort - Sorts an array using quick sort.
 * @array: The array.
 * @size: The array size.
 */


void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
	{
		return;
	}

	quicker(array, 0, size - 1, size);
}


/**
 * quicker - Sorts the array recursively.
 * @array: The array.
 * @start: The start of the array.
 * @end: The end of the array.
 * @size: The size of the array.
 */

void quicker(int *array, int start, int end, size_t size)
{
	int p;

	if (start < end)
	{
		p = partition(array, start, end, size);
		quicker(array, start, p - 1, size);
		quicker(array, p + 1, end, size);
	}
}


/**
 * partition - Partition scheme.
 * @array: The array.
 * @start: The start of the array.
 * @end: The end of the array.
 * @size: The size of the array.
 * Return: The pivot index.
 */


int partition(int *array, int start, int end, size_t size)
{

	int pivot;
	int i;
	int j;

	i = start - 1;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			if (i < j)
			{
				pivot = array[i];
				array[i] = array[j];
				array[j] = pivot;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > array[end])
	{
		pivot = array[i + 1];
		array[i + 1] = array[end];
		array[end] = pivot;
		print_array(array, size);
	}

	return (i + 1);
}
