#include <iostream>
#include <random>
#include <ctime>

#include "types.h"
#include "deck.h"


using namespace std;

const char ascii_suits[] = "CSDH.";
const char ascii_ranks[] = "A23456789TJQK";

static inline void Print_card(CARDS card) {
	if (card != NO_CARD) {
		cout << ascii_suits[get_card_suit(card)];
		cout << ascii_ranks[get_card_rank(card)];
	}
	return;
}

void Print_deck(DECK* deck) {

	for (int i = 0; i < ALL_DECKS_SIZE; ++i) {
		Print_card(deck->cards[i]);
		cout << ' ';
	}
	cout << endl;
}



int main() {
	srand(unsigned(time(NULL)));

	DECK deck;

	Fill_deck(&deck);
	Print_deck(&deck);
	Shuffle_deck(&deck);
	Print_deck(&deck);

	Shuffle_deck(&deck);
	Print_deck(&deck);

	return 0;
}
