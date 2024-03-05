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

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
