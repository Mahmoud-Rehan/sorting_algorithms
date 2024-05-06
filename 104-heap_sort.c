#include "sort.h"


/**
 * heap_sort - Sorts an array of integers using HEAP SORT.
 * @array: The array to be sorted.
 * @size: The size of array.
 */

void heap_sort(int *array, size_t size)
{
	size_t node, sort;

	if (array == NULL || size < 2)
		return;

	for (node = get_parent(size - 1); node != SIZE_MAX; node--)
	{
		shift(array, size, node, size - 1);
	}

	for (sort = size - 1; sort > 1; sort--)
	{
		array[0] ^= array[sort];
		array[sort] ^= array[0];
		array[0] ^= array[sort];
		print_array(array, size);
		shift(array, size, 0, sort - 1);
	}

	array[0] ^= array[1];
	array[1] ^= array[0];
	array[0] ^= array[1];
	print_array(array, size);
}


/**
 * get_parent - Get the parent value.
 * @i: The size of the array.
 * Return: The new value.
 */

size_t get_parent(size_t i)
{
	return ((i - 1) / 2);
}


/**
 * get_right - Get the right value.
 * @i: The size of the array.
 * Return: The new value.
 */

size_t get_right(size_t i)
{
	return (2 * i + 2);
}


/**
 * get_left - Get the left value.
 * @i: The size of the array.
 * Return: The new value.
 */

size_t get_left(size_t i)
{
	return (2 * i + 1);
}


/**
 * shift - sift_down.
 * @array: The array containing heap.
 * @size: The size of array.
 * @index: index of index node of heap.
 * @n: Index of nth node in heap.
 */

void shift(int *array, size_t size, size_t index, size_t n)
{
	size_t large, l, r;

	do {
		l = get_left(index);
		r = get_right(index);
		large = index;

		if (r <= n && array[r] > array[index])
		{
			large = r;
		}

		if (array[l] > array[large])
		{
			large = l;
		}

		if (index == large)
			return;

		array[index] ^= array[large];
		array[large] ^= array[index];
		array[index] ^= array[large];
		print_array(array, size);
		index = large;

	} while (get_left(index) <= n);
}
