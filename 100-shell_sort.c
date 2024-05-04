#include "sort.h"


/**
 * shell_sort - Sorts an array using SHELL SORT.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int n;

	while (gap < size)
	{
		gap = (3 * gap) + 1;
	}

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = 1; i < size; i++)
		{
			n = array[i];

			for (j = i; j >= gap && array[j - gap] > n; j = j - gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = n;
		}
		print_array(array, size);
	}
}
