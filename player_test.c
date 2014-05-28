#include <stdio.h>
#include "player.h"

int main()
{
	struct player t,*p = &t;
	struct card card,*c= &card;
	int i;

	player_init(p,30,100);

	//enter five cards in deck
	for(  i =0; i < 5; i ++ ){
		card_init(c,"test",i,i,i);
		deck_push(&p->deck,c);
	}

	player_turn_begin(p);

	if( PLAYER_OK !=player_play_card(p,c,2)){
		printf("first play card index 2 failed\n");
	}//should fail

	if(PLAYER_OK == player_play_card(p,c,0)){
		printf("succesfully played card\n");
		card_print(c);
	}//should success

	player_deinit(p);


	return 0;
}
