#include <stdio.h>
#include "card.h"
#include "deck.h"
int main()
{
	struct deck my_deck;
	struct card my_card,card_result;
	int res,i;

	#define CHECK_DECK_OP() \
	if ( res != DECK_OK ) {\
		deck_get_op_result(res);\
		deck_print_cards_cnt(&my_deck);\
	}

	//10 cards at first
	res = deck_init(&my_deck,10);
	CHECK_DECK_OP();

	//look in empty deck
	printf("look in empty deck test\n");
	res =deck_look(&my_deck,&my_card);
	CHECK_DECK_OP();
	card_print(&my_card);
	printf("look in empty deck test end\n");

	printf("draw from empty deck test\n");
	res = deck_draw(&my_deck,&my_card);
	CHECK_DECK_OP();
	card_print(&my_card);
	printf("draw from empty deck test end\n");

	printf("push in deck test\n");

	card_init(&my_card,"test",1,1,1);
	res =deck_push(&my_deck,&my_card);
	CHECK_DECK_OP();

	res =deck_look(&my_deck,&card_result);
	CHECK_DECK_OP();
	card_print(&card_result);

	printf("push in deck test end\n");

	printf("push five cards and draw 5 cards test\n");
	for(  i =0; i < 5; i ++ ){
		card_init(&my_card,"test",i,i,i);
		res = deck_push(&my_deck,&my_card);
		CHECK_DECK_OP();
	}
	printf("get last 10 cards from deck\n");
	for (  i =0; i < 10; i++ ){
		res = deck_draw(&my_deck,&card_result);
		CHECK_DECK_OP();
		card_print(&card_result);
	}

	printf("push five cards and draw 10 cards test end\n");

	printf("reallocation test\n");

	printf("old size [%d]\n",deck_get_size(&my_deck));
	for (  i =0; i < 15; i++ ){
		card_init(&my_card,"test",i,i,i);
		res = deck_push(&my_deck,&my_card);
		CHECK_DECK_OP();
	}
	printf("new size [%d]\n",deck_get_size(&my_deck));

	printf("reallocation test end\n");




	printf("Deck deinit\n");
	deck_deinit(&my_deck);



	return 0;
}
