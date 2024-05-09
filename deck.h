#ifndef DECK_H_
#define DECK_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * enum kind_e - The enum of the 4 card colors.
 * @SPADE: value 0
 * @HEART: value 1
 * @CLUB: value 2
 * @DIAMOND: value 3
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;


void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);
size_t decklen(const deck_node_t *head);
int assign_card(deck_node_t *node);
void swap_next(deck_node_t **deck, deck_node_t *node);


#endif
