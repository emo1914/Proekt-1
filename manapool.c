
#include "manapool.h"

int manapool_init(struct manapool* mpool)
{
	if(!mpool){
		return MPOOL_ERROR;
	}
	mpool->mana = 1;
	return MPOOL_OK;
}

int manapool_get(struct manapool* mpool,int mana)
{
	if(!mpool){
		return MPOOL_ERROR;
	}
	mpool->mana -= mana;
	return mpool->mana>= 0 ? MPOOL_OK  : MPOOL_NEGATIVE;
}

int manapool_add(struct manapool* mpool,int mana)
{
	if(!mpool){
		return MPOOL_ERROR;
	}
	mpool->mana += mana;
	return MPOOL_OK;
}

int can_place_card( struct card* card, struct manapool* mpool )
{
	if (!card || !mpool){
		return MPOOL_ERROR;
	}
	return card->price >mpool->mana ? MPOOL_ERROR : MPOOL_OK;

}
