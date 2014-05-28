#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "manapool.h"

struct player
{
	struct deck deck;

	struct manapool mpool;

	int hp;

	//array of cards,initialized with initial count of deck
	struct card  *hand;

	int current_cards_in_hand;
	int hand_size;

};

#define PLAYER_ERROR 	0
#define PLAYER_OK 		1

int player_init(struct player* pl,unsigned int deck_size,int hp);
int player_change_hp(struct player* pl,int hp);



int player_deinit(struct player* pl);

int player_play_card(struct player* pl,struct card* card_played,int card_index);

int player_turn_begin(struct player* pl);

#define player_is_alive(pl) pl->hp > 0


int player_ok(struct player* pl);

#endif // PLAYER_H
