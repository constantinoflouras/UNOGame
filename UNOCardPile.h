#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

// So this knows what an UNOCard is.
#include "UNOCard.h"

#ifndef UNOCARDPILE_H
    #define UNOCARDPILE_H

using std::string;



class UNOCardPile
{
    std::vector<UNOCard> cardArray;
    int cardArraySize;
    int numberOfCards;

    public:
        UNOCardPile();
        UNOCardPile(int size);
        void shuffle( void );

        /*
            The following method will add a card to the card pile,
            and return a 0 if adding the card was successful, or 1
            if there was an error.
        */
        int addCard(UNOCard card);
        string toString();

    private:
        void swap(UNOCard &x, UNOCard &y);
};















#endif