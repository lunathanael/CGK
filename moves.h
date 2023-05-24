#ifndef MOVES_H
#define MOVES_H

#include "types.h"


static inline bool Turn_stock(STOCK* stock) {
	if (stock->cardsLeft == 0) {
		// ILLEGAL MOVE
		return false;
	}
	while (true) {
		++stock->faceCard;
		if (stock->faceCard > STOCK_SIZE) {
			stock->faceCard = -1;
			return true;
		}
		if (stock->faceCard == STOCK_SIZE) {
			return true;
		}
		if (stock->stack[stock->faceCard] != NO_CARD) {
			return true;
		}
	}
	return true;
};


static inline bool Stock_to_foundation(GAMESTATE* gamestate) {
	STOCK* stock = &gamestate->stock;
	bool stock_displaying_card = (stock->faceCard != -1 && stock->faceCard != STOCK_SIZE);
	if (stock_displaying_card) {
		CARDS stock_card = stock->stack[stock->faceCard];
		int foundation_index = get_card_suit(stock_card);
		FOUNDATION* foundation = &gamestate->foundations[foundation_index];

		if (foundation->cards == 0) {
			if (get_card_rank(stock_card) != ACE) {
				return false;
			}
		}
		else {
			bool stock_card_is_one_higher = ((stock_card - 1) == (foundation->stack[foundation->cards - 1]));
			if (!stock_card_is_one_higher) {
				return false;
			}
		}


		// add foundation card;
		foundation->stack[foundation->cards] = stock_card;
		++foundation->cards;

		// remove stock card
		stock->stack[stock->faceCard] = NO_CARD;
		Turn_stock(stock);
		--stock->cardsLeft;
		return true;
	}
	return false;
}





#endif