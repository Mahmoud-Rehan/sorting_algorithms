#include "sort.h"


/**
 * bubble_sort - Sorts an array using bubble sort.
 * @array: The sorted array.
 * @size: The size of the array.
 */


void bubble_sort(int *array, size_t size)
{
	unsigned long int i;
	unsigned long int j;
	int tmp;


	if (array == NULL)
	{
		return;
	}

	for (i = size; i > 0; i--)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
