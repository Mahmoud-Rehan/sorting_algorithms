#include "sort.h"



/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using COCKTAIL SHAKER SORT.
 * @list: The doubly linked list to be sorted.
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *my_list = *list;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (!list || !(*list) || !(*list)->next)
	{
		return;
	}

	do {
		while (my_list->next)
		{
			if (my_list->n > my_list->next->n)
			{
				swap_nodes(my_list->next, my_list, list);
			}
			else
			{
				my_list = my_list->next;
			}
		}
		end = my_list;

		while (my_list->prev != start)
		{
			if (my_list->n < my_list->prev->n)
			{
				swap_nodes(my_list, my_list->prev, list);
			}
			else
			{
				my_list = my_list->prev;
			}
		}
		start = my_list;
	} while (start != end);
}



/**
 * swap_nodes - Swaps two nodes.
 * @current_node: Pointer to the current node.
 * @old_node: Pointer to the old node.
 * @mylist: The doubly linked list.
 */


void swap_nodes(listint_t *current_node,
		listint_t *old_node, listint_t **mylist)
{
	listint_t *tmp1 = current_node->next;
	listint_t *tmp2 = old_node->prev;

	if (tmp1 != NULL)
	{
		tmp1->prev = old_node;
	}

	if (tmp2 != NULL)
	{
		tmp2->next = current_node;
	}

	current_node->prev = tmp2;
	old_node->next = tmp1;
	current_node->next = old_node;
	old_node->prev = current_node;

	if (*mylist == old_node)
	{
		*mylist = current_node;
	}
	print_list(*mylist);
}
