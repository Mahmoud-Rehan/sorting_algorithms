#include "deck.h"
#include "sort.h"


/**
 * sort_deck - Sorts the deck using COCKTAIL SORT.
 * @deck: The card deck to be sorted.
 */

void sort_deck(deck_node_t **deck)
{
	int swap = 1, value1, value2;
	size_t low = 0, i = 0, high = (decklen(*deck) - 1);
	deck_node_t *tmp = *deck;

	if (!deck || !(*deck) || !((*deck)->next))
		return;
	while (swap)
	{
		swap = 0;
		for (; i < high; i++)
		{
			value1 = assign_card(tmp);
			value2 = assign_card(tmp->next);
			if (value2 < value1)
			{
				swap_next(deck, tmp);
				swap = 1;
			}
			else
				tmp = tmp->next;
		}

		if (!swap)
			break;
		swap = 0;
		for (; i > low; i--)
		{
			value1 = assign_card(tmp);
			value2 = assign_card(tmp->prev);
			if (value2 > value1)
			{
				swap_next(deck, tmp->prev);
				swap = 1;
			}
			else
				tmp = tmp->prev;
		}
		high--;
		low++;
	}
}


/**
 * decklen - Gets the length of a card deck.
 * @head: Head node to the deck.
 * Return: The size of the deck.
 */

size_t decklen(const deck_node_t *head)
{
	size_t len = 0;

	while (head != NULL)
	{
		len++;
		head = head->next;
	}

	return (len);
}


/**
 * assign_card - Assigns a unique numeric value to each card.
 * @node: The card node to extract the value from.
 * Return: Card id.
 */

int assign_card(deck_node_t *node)
{
	int n;
	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (n = 0; n < 13; n++)
	{
		if (!strcmp(node->card->value, values[n]))
		{
			return (n + (13 * node->card->kind));
		}
	}

	printf("Uh-oh. Card is out of range. I'm gonna crash now.");
	exit(EXIT_FAILURE);
}



/**
 * swap_next - Swaps node with the next node.
 * @deck: Pointer to the head.
 * @node: The node to be swaped.
 */

void swap_next(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}
