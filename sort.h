#ifndef SORT_H_
#define SORT_H_


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void quicker(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t *current_node,
		listint_t *old_node, listint_t **mylist);
void counting_sort(int *array, size_t size);
int get_max(int *my_array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/*void sort_deck(deck_node_t **deck);*/
void separate_array(int *buffer, int start, size_t size, int *array);
void merge(int *array, int size, int start, int middle, int *buffer);
void print_subarray(int *array, int size, int start, int middle);
size_t get_parent(size_t i);
size_t get_right(size_t i);
size_t get_left(size_t i);
void shift(int *array, size_t size, size_t index, size_t n);


#endif
