#ifndef CARD_H
#define CARD_H

#define CARD_NAME_LEN 20

struct card
{
	/**
	 * name of the card,max CARD_NAME_LEN long
	 */
	char name[CARD_NAME_LEN];

	/**
	 * power of card
	 * range 0  - MAX_INT
	 */
	unsigned int power;

	/**
	 * life of card
	 * range 0  - MAX_INT
	 */
	unsigned int life;

	/**
	 * price of card in mana
	 * range 0  - MAX_INT
	 */
	unsigned int price;
};

int card_init(struct card* card,const char* name,
			unsigned int power,unsigned int life,unsigned int price);

#define CARD_ERROR 					0
#define CARD_OK						1

#define CARD_BATTLE_NO_WINNER 		2
#define CARD_BATTLE_ATTACKER_WON	3
#define CARD_BATTLE_DEFENDER_WON	4
#define CARD_BATTLE_BOTH_SURVIVED 	5


int card_attack(struct card* attacker, struct card* defender);

int card_print(struct card* card);

void get_card_op_result(int card_operation_result);



#endif // CARD_H
