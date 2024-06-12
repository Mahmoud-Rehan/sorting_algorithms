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

		if (pivot > first)
		{
			quickly(array, first, pivot, size);
		}
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
	int f = start;
	int l = end;

	while (1)
	{
		while (array[f] < pivot)
		{
			f++;
		}

		while (array[l] > pivot)
		{
			l--;
		}

		if (f < l)
		{
			swap(&array[f], &array[l]);
			print_array(array, size);
			f++;
			l--;
		}
		else
		{
			if (f != l)
			{
				return (l);
			}
			return (l - 1);
		}
	}
}

/**
* swap - Swaps indexes of the array.
* @a: left or low index to swap.
* @b: right or high index
*/

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
