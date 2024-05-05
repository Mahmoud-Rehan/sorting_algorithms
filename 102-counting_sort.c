#include "sort.h"



/**
 * counting_sort - Sort an array of integers using COUNTING SORT.
 * @array: the array of integers to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int *my_array, *array2, max, n;
	size_t s;


	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	my_array = malloc(sizeof(size_t) * max + 1);
	array2 = malloc(sizeof(int) * size);

	for (s = 0; (int)s <= max; s++)
	{
		my_array[s] = 0;
	}

	for (s = 0; s < size; s++)
	{
		n = array[s];
		my_array[n] += 1;
	}

	for (s = 1; (int)s <= max; s++)
	{
		my_array[s] += my_array[s - 1];
	}

	print_array(my_array, max + 1);

	for (s = 0; s < size; s++)
	{
		array2[my_array[array[s]] - 1] = array[s];
		my_array[array[s]]--;
	}

	for (s = 0; s < size; s++)
		array[s] = array2[s];

	free(array2);
	free(my_array);
}



/**
 * get_max - Get the max value in an array of integers.
 * @my_array: The array of integers.
 * @size: The size of the array.
 * Return: The max value of the array.
 */

int get_max(int *my_array, size_t size)
{
	int max;
	size_t n;

	max = my_array[0];

	for (n = 1; n < size; n++)
	{
		if (my_array[n] > max)
		{
			max = my_array[n];
		}
	}

	return (max);
}
