#include "gamestate.h"
#include "deck.h"

#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

const char ascii_suits[] = "CSDH";

const char ascii_ranks[] = "A23456789TJQK";


static inline void Print_stock_card(STOCK* stock) {
    if (stock->faceCard == -1 || stock->faceCard == (STOCK_SIZE)) {
        cout << "mt";
        return;
    }

    if (stock->stack[stock->faceCard] != NO_CARD) {
        cout << ascii_suits[get_card_suit(stock->stack[stock->faceCard])];
        cout << ascii_ranks[get_card_rank(stock->stack[stock->faceCard])];
    }
    return;
}

static inline void Print_foundation_card(FOUNDATION* foundation) {
    if (foundation->cards == 0) {
        cout << "mt ";
        return;
    }

    cout << ascii_suits[get_card_suit(foundation->stack[foundation->cards - 1])];
    cout << ascii_ranks[get_card_rank(foundation->stack[foundation->cards - 1])] << ' ';
    return;
}

static inline void Print_card(CARDS card) {
    if (card != NO_CARD) {
        cout << ascii_suits[get_card_suit(card)];
        cout << ascii_ranks[get_card_rank(card)];
    }
    return;
}

void Print_pile(PILE* pile, bool hidden) {
    for (int i = 0; i < pile->cardNumber; ++i) {
        if (i >= pile->revealed || !hidden) {
            Print_card(pile->pile[i]);
        }
        else {
            cout << "**";
        }
        cout << ' ';
    }
    cout << endl;
}

void Print_gamestate(GAMESTATE* gamestate, bool hidden) {
    cout << endl;
    cout << "Current stock card: ";
    Print_stock_card(&gamestate->stock);


    cout << "       Foundations: ";
    Print_foundation_card(&gamestate->foundations[0]);
    Print_foundation_card(&gamestate->foundations[1]);
    Print_foundation_card(&gamestate->foundations[2]);
    Print_foundation_card(&gamestate->foundations[3]);

    cout << "\n                                          C  S  D  H ";
    cout << "\nPILES:";
    cout << "                 MOVES: " << gamestate->moves << endl;

    for (PILES pile = PILE7; pile >= 0; --pile) {
        // Each card
        cout << endl << pile + 1 << ':';
        Print_pile(&gamestate->piles[pile], hidden);
    }
    cout << endl;
}


GAMESTATE Start_game() {
    GAMESTATE gamestate;


    DECK deck;
    Fill_deck(&deck);
    Shuffle_deck(&deck);

    // 7 piles
    for (PILES pile = PILE1; pile < NUMBER_OF_PILES;) {
        // Each card
        CARDS* start = (deck.cards + deck.currentCard);
        ++pile;
        deck.currentCard += (pile);
        CARDS* end = (deck.cards + deck.currentCard);
        copy(start, end, gamestate.piles[pile - 1].pile);
    }

    // rest into stock
    CARDS* start = (deck.cards + deck.currentCard);
    deck.currentCard += STOCK_SIZE;
    CARDS* end = (deck.cards + deck.currentCard);
    copy(start, end, gamestate.stock.stack);

    return gamestate;
}