#include "sort.h"


/**
 * quick_sort_hoare - Sorts an array of integers using QUICK SORT.
 * @array: The array of integers.
 * @size: The of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quickly(array, 0, size - 1, size);
}


/**
 * quickly - Sorts the array.
 * @array: The array to be sorted.
 * @first: The first position.
 * @last: The last position.
 * @size: The size of the array.
 */

void quickly(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = array_partition(array, first, last, size);
		quickly(array, first, pivot, size);
		quickly(array, pivot + 1, last, size);
	}
}


/**
 * array_partition - The array partition.
 * @array: The array to be sorted.
 * @start: The first position.
 * @end: The last position.
 * @size: The size of the array.
 * Return: The index of the int pivot.
 */

int array_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int f = start - 1;
	int l = end + 1;
	int tmp;

	while (1)
	{
		do {
			f++;
		} while (array[f] < pivot);

		do {
			l--;
		} while (array[l] > pivot);

		if (l < f)
			return (l);

		if (array[f] > array[l])
		{
			tmp = array[f];
			array[f] = array[l];

			array[l] = tmp;
			print_array(array, size);
		}
	}
}
