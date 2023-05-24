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

static inline bool Pile_to_foundation(GAMESTATE* gamestate, int pile_index) {
	PILE* pile = &gamestate->piles[pile_index];
	if (pile->cardNumber != 0) { // cards exist
		CARDS pile_card = pile->pile[pile->cardNumber - 1]; // Top card
		int foundation_index = get_card_suit(pile_card);
		FOUNDATION* foundation = &gamestate->foundations[foundation_index];

		bool card_is_one_higher = (get_card_rank(pile_card) == foundation->cards);
		if (!card_is_one_higher) {
			return false;
		}

		// add foundation card;
		foundation->stack[foundation->cards] = pile_card;
		++foundation->cards;

		// remove pile card
		--pile->cardNumber;
		pile->pile[pile->cardNumber] = NO_CARD;
		//Update_pile(pile);
		return true;
	}
	return false;
}

static inline bool Foundation_to_pile(PILE* pile, FOUNDATION* foundation, int foundationIndex) {
	if (foundation->cards != 0) { // cards exist
		CARDS foundation_card = foundation->stack[foundation->cards - 1]; // Top card

		if (pile->cardNumber == 0 && get_card_rank(foundation_card) != KING) {
			return false;
		}
		else {
			bool is_not_same_suit = ((foundationIndex >> 1) ^ (get_card_suit(pile->pile[pile->cardNumber - 1]) >> 1));
			if (is_not_same_suit) {
				return false;
			}
			else {
				bool card_is_one_higher = (get_card_rank(foundation_card) + 1) == (get_card_rank(pile->pile[pile->cardNumber - 1]));
				if (!card_is_one_higher) {
					return false;
				}
			}
		}

		// add pile card
		pile->pile[pile->cardNumber] = foundation_card;
		++pile->cardNumber;
		//Update_pile(pile);

		// remove foundation card;
		--foundation->cards;
		foundation->stack[foundation->cards] = NO_CARD;
		return true;
	}
	return false;
}





#endif