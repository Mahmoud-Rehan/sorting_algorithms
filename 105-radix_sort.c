#include "sort.h"



/**
 * radix_sort - Sorts an array of integers using RADIX SORT.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int *new;
	int i, max;
	int n = 1;
	int size2 = size;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	new = (int *)malloc(sizeof(int) * size);

	while (max / n > 0)
	{
		int my_array[20] = {0};

		i = 0;
		while (i < size2)
		{
			my_array[(array[i] / n) % 10]++;
			i++;
		}

		if (my_array != NULL)
		{
			for (i = 1; i < 10; i++)
				my_array[i] += my_array[i - 1];

			for (i = size2 - 1; i >= 0; i--)
			{
				new[my_array[(array[i] / n) % 10] - 1] = array[i];
				my_array[(array[i] / n) % 10]--;
			}

			for (i = 0; i < size2; i++)
				array[i] = new[i];
		}
		n = n * 10;
		print_array(array, size);
	}
	free(new);
}
