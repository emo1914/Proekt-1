#include <stdio.h> //printf
#include <stdlib.h>

#include "card.h"
#include "deck.h"


#define deck_resize(deck) \
	deck->current_size+=deck->initial_size;\
	deck->cards = realloc(deck->cards,deck->current_size*sizeof(struct card));\


int deck_init(struct deck* deck,unsigned int deck_size)
{
	if(!deck){
		return DECK_ERROR;
	}
	//memory allocation for the initial given size
	deck->cards = malloc(deck_size*sizeof(struct card));
	if(!deck->cards){
		return DECK_ERROR;
	}
	deck->initial_size = deck_size;
	deck->current_size = deck_size;
	deck->top = -1;

	return DECK_OK;
}

int deck_deinit(struct deck* deck)
{
	if(deck) {
		if(deck->cards){
			free(deck->cards);
			deck->cards = NULL;
		}
		deck->top = -1;
		deck->initial_size = 0;
		deck->current_size = 0;
	}
	return DECK_OK;
}

int deck_push(struct deck* deck,struct card* card)
{
	if(!deck || !card){
		return DECK_ERROR;
	}
	//check if realoc is needed
	if( ++deck->top >=deck->current_size ){
		deck_resize(deck);
	}
	deck->cards[deck->top] = *card;
	return DECK_OK;
}


int deck_draw(struct deck* deck,struct card* card)
{
	if(!deck || (-1 == deck->top) ) { //empty or null ptr
		return DECK_EMPTY;
	}
	*card = deck->cards[deck->top--];
	return DECK_OK;
}

int deck_look(struct deck* deck,struct card* card)
{
	if(!deck || (-1 == deck->top) ) { //empty or null ptr
		return DECK_EMPTY;
	}
	*card = deck->cards[deck->top];
	return DECK_OK;
}

unsigned int deck_get_cards_count(struct deck *deck)
{
	if(!deck){
		return DECK_ERROR;
	}
	return deck->top + 1;
}

// make me inline
int deck_is_empty(struct deck* deck)
{
	 return (-1 == deck->top );

}

unsigned int deck_get_size(struct deck* deck)
{
	return deck ? deck->current_size : -1;
}

void deck_get_op_result(int deck_op_result)
{
	const char* result_strings[] =
	{
		"DECK ERROR",
		"DECK OK",
		"DECK EMPTY"
	};
	printf("Deck result [%s]\n",result_strings[deck_op_result]);
}

void deck_print_cards_cnt(struct deck* deck)
{
	printf("Deck cards [%d]\n",deck_get_cards_count(deck));
}




