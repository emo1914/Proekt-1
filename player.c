#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "deck.h"
#include "card.h"

int player_init(struct player* pl,unsigned int deck_size,int hp)
{
	if(!pl){
		return PLAYER_ERROR;
	}

	//init deck
	if( DECK_OK != deck_init(&pl->deck,deck_size)){
		return PLAYER_ERROR;
	}

	//init manapool
	manapool_init(&pl->mpool);

	//set hp
	pl->hp = hp;

	//init hand of the player
	if( NULL == (pl->hand = malloc(deck_size*sizeof(struct card)))){
		deck_deinit(&pl->deck);
		return PLAYER_ERROR;
	}
	memset(pl->hand,0,deck_size*sizeof(struct card));

	pl->current_cards_in_hand = 0;
	pl->hand_size = deck_size;

	return PLAYER_OK;
}

int player_change_hp(struct player* pl,int hp)
{
	if(!pl){
		return PLAYER_ERROR;
	}
	pl->hp +=hp;
	return PLAYER_OK;
}

int player_deinit(struct player* pl)
{
	if(!pl){
		return PLAYER_ERROR;
	}

	deck_deinit(&pl->deck);
	if( pl->hand ){
		free(pl->hand);
		pl->hand = NULL;
	}
	pl->current_cards_in_hand = 0;
	pl->hand_size = 0;

	return PLAYER_OK;
}

int player_play_card(struct player* pl,struct card* card_played,int card_index)
{
	if(!player_ok(pl) || !card_played ||
		card_index >=pl->current_cards_in_hand ) {
		return PLAYER_ERROR;
	}

    *card_played = pl->hand[card_index];

	//make the last card the current played card
    pl->hand[card_index] = pl->hand[pl->current_cards_in_hand-1];
    //decrement cards count
    pl->current_cards_in_hand--;

	return PLAYER_OK;
}

int player_turn_begin(struct player* pl)
{
	if(!pl || deck_is_empty(&pl->deck)){
		return PLAYER_ERROR;
	}

	//resize
	if( pl->current_cards_in_hand >=pl->hand_size){
		pl->hand_size +=deck_get_size(&pl->deck);
		pl->hand = realloc(pl->hand,pl->hand_size*sizeof(struct card));
	}

	if( DECK_OK != deck_draw(&pl->deck,&pl->hand[pl->current_cards_in_hand++])){
		return PLAYER_ERROR;
	}

	return PLAYER_OK;
}

int player_ok(struct player* pl)
{
	return ( pl && pl->hand != NULL );

}


