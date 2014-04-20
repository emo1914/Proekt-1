#ifndef DECK_H
#define DECK_H

struct deck
{
	struct card  *cards;
	unsigned int initial_size;
	unsigned int current_size;
	unsigned int top;
};


#define DECK_ERROR 	0
#define DECK_OK 	1
#define DECK_EMPTY	2

/* interface functions */

int deck_init(struct deck* deck,unsigned int deck_size);
int deck_deinit(struct deck* deck);
int deck_push(struct deck* deck,struct card* card);
int deck_draw(struct deck* deck,struct card* card);
int deck_look(struct deck* deck,struct card* card);
unsigned int deck_get_cards_count(struct deck *deck);
int deck_is_empty(struct deck* deck);
unsigned int deck_get_size(struct deck* deck);
void deck_get_op_result(int deck_op_result);
void deck_print_cards_cnt(struct deck* deck);


#endif // DECK_H
