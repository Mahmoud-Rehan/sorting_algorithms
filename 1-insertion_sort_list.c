#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list
 * using insertion sort.
 * @list: The linked list.
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *node1, *node2, *tmp1, *tmp2;

	if (list == NULL)
	{
		return;
	}
	node1 = (*list)->next;

	while (node1 != NULL)
	{
		node2 = node1;
		node1 = node1->next;
		while (node2 != NULL && node2->prev != NULL)
		{
			if (node2->prev->n > node2->n)
			{
				tmp1 = node2;
				tmp2 = node2->prev;
				if (tmp2->prev != NULL)
					tmp2->prev->next = tmp1;
				if (tmp1->next != NULL)
					tmp1->next->prev = tmp2;

				tmp2->next = tmp1->next;
				tmp1->prev = tmp2->prev;
				tmp2->prev = tmp1;
				tmp1->next = tmp2;

				if (node2->prev == NULL)
					(*list) = node2;
				print_list(*list);
			}
			else
				node2 = node2->prev;
		}
	}
}
