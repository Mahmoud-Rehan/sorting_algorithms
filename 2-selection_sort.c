#include "sort.h"


/**
 * selection_sort - Sorts an array using selection sort.
 * @array: The array.
 * @size: The size of the array.
 */


void selection_sort(int *array, size_t size)
{
	unsigned long int i;
	unsigned long int j;
	unsigned long int n;
	int num;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1, n = i + 1; j > i; j--)
		{
			if (array[j] < array[n])
				n = j;
		}
		if (array[i] > array[n])
		{
			num = array[i];
			array[i] = array[n];
			array[n] = num;
			print_array(array, size);
		}
	}
}
