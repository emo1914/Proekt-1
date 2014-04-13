#include <stdio.h> //printf
#include "card.h"


int card_init(struct card* card,const char* name,
			unsigned int power,unsigned int life,unsigned int price)

{
	if(!card){
		return CARD_ERROR;
	}
	sprintf(card->name,"%s",name);
	card->power = power;
	card->life  = life;
	card->price = price;

	return CARD_OK;
}


int card_attack(struct card* attacker, struct card* defender)
{
	if(!attacker || !defender){
		return CARD_ERROR;
	}

	int attack_result = attacker->power - defender->life;
	int defend_result = defender->power - attacker->life;

	if ( attack_result >= 0 && defend_result >= 0 ){
		return CARD_BATTLE_NO_WINNER;
	}

	if ( attack_result >= 0 ) {
		return CARD_BATTLE_ATTACKER_WON;
	}

	if ( defend_result >=0  ){
		return CARD_BATTLE_DEFENDER_WON;
	}

	return CARD_BATTLE_BOTH_SURVIVED;
}

void get_card_op_result(int card_operation_result)
{
	const char* result_strings[] =
	{
		"CARD_ERROR",
		"CARD_OK",
		"CARD_BATTLE_NO_WINNER",
		"CARD_BATTLE_ATTACKER_WON",
		"CARD_BATTLE_DEFENDER_WON",
		"CARD_BATTLE_BOTH_SURVIVED"
	};
	printf("Attack result [%s]\n",result_strings[card_operation_result]);

}


int card_print(struct card* card)
{
	if( !card ){
		printf(" Null ptr\n");
		return CARD_ERROR ;
	}
	printf("CARD : Name [%s] , power[%d] , life [%d] , price[%d]\n",
			card->name,card->power,card->price,card->life);
	return CARD_OK;
}

