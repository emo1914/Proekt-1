#include "card.h"

int main()
{

	struct card attacker;
	struct card defender;
	int res=0;

	const char* attacker_name = " Attacker";
	const char* defender_name = " Defender";

	/* TEST 1 - same cards */
	card_init(&attacker,attacker_name,10,10,1);
	card_init(&defender,defender_name,10,10,1);
	res = card_attack(&attacker,&defender);
	get_card_op_result(res);

	/* TEST 2 - attacker has more attack */
	card_init(&attacker,attacker_name,11,10,1);
	card_init(&defender,defender_name,10,10,1);
	res = card_attack(&attacker,&defender);
	get_card_op_result(res);

	/* TEST 3 - attacker has more attack,defender has less attack */
	card_init(&attacker,attacker_name,11,10,1);
	card_init(&defender,defender_name,9,10,1);
	res = card_attack(&attacker,&defender);
	get_card_op_result(res);

	/* TEST 4 cards with more life */
	card_init(&attacker,attacker_name,11,50,1);
	card_init(&defender,defender_name,9,50,1);
	res = card_attack(&attacker,&defender);
	get_card_op_result(res);

	/* TEST 5 defender has more attack and defens */
	card_init(&attacker,attacker_name,11,50,1);
	card_init(&defender,defender_name,100,100,1);
	res = card_attack(&attacker,&defender);
	get_card_op_result(res);


	return 0;
}
