#ifndef TYPES_H
#define TYPES_H

#define NUMBER_OF_DECKS 1
#define NUMBER_OF_PILES 7

#define NUMBER_OF_SUITS 4
#define CARDS_IN_SUIT 13

static constexpr int DECK_SIZE = (NUMBER_OF_SUITS * CARDS_IN_SUIT);
static constexpr int ALL_DECKS_SIZE = (NUMBER_OF_DECKS * DECK_SIZE);
static constexpr int STOCK_SIZE = (ALL_DECKS_SIZE - (NUMBER_OF_PILES * (NUMBER_OF_PILES + 1) / 2)); // last element is the no face card

static constexpr int MAX_PILE_SIZE = (CARDS_IN_SUIT + NUMBER_OF_PILES);


enum CARDS : int {
	CA, C2, C3, C4, C5, C6, C7, C8, C9, CT, CJ, CQ, CK,
	SA, S2, S3, S4, S5, S6, S7, S8, S9, ST, SJ, SQ, SK,
	DA, D2, D3, D4, D5, D6, D7, D8, D9, DT, DJ, DQ, DK,
	HA, H2, H3, H4, H5, H6, H7, H8, H9, HT, HJ, HQ, HK, NO_CARD
};



#endif