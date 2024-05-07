#include "sort.h"


/**
* bitonic_sort - Sorts an array of integers using using BITONIC SORT.
* @array: The Array to be sorted.
* @size: The size of array.
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size, 1, size);
}


/**
* sort - THE BITONIC RECURSIVE SORT.
* @array: The array to be sorted.
* @min: The minimum index.
* @slice: The count of slice.
* @dir: The direction: ASC or DESC.
* @size: The size of the total array to print.
*/

void sort(int *array, int min, int slice, int dir, size_t size)
{
	int i;

	if (slice > 1)
	{
		i = slice / 2;
		printf("Merging [%d/%d] ", slice, (int)size);

		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");

		print_array(array + min, slice);

		sort(array, min, i, 1, size);
		sort(array, min + i, i, 0, size);

		bitonic_merge(array, min, slice, dir, size);

		printf("Result [%d/%d] ", slice, (int)size);

		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");

		print_array(array + min, slice);
	}
}



/**
* bitonic_merge - BITONIC MERGE.
* @array: The array slice to be merged.
* @min: The minimum index.
* @slice: The count of slice.
* @dir: The direction: ASC or DESC.
* @size: The size of total array to print
*/

void bitonic_merge(int *array, int min, int slice, int dir, size_t size)
{
	int i, j;

	if (slice > 1)
	{
		j = slice / 2;

		for (i = min; i < min + j; i++)
		{
			if (((array[i] > array[i + j]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + j])))
				swap(&array[i], &array[i + j]);
		}

		bitonic_merge(array, min, j, dir, size);
		bitonic_merge(array, min + j, j, dir, size);
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
