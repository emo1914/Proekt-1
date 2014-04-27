#ifndef MANAPOOL_H
#define MANAPOOL_H

struct manapool
{
	int mana;
};

#define MPOOL_ERROR 	0
#define MPOOL_OK		1
#define MPOOL_NEGATIVE 	2

int manapool_init(struct manapool* mpool);
int manapool_get(struct manapool* mpool,int mana);
int manapool_add(struct manapool* mpool,int mana);

int can_place_card( struct card* card, struct manapool* mpool );

#endif // MANAPOOL_H
