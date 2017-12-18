#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

// So this knows what an UNOCard is.
#include "UNOCard.h"
using std::string;

// Before we define anything within an UNOCardPile....
#include "UNOCardPile.h"


UNOCardPile::UNOCardPile()
{
    UNOCardPile(108);
}
UNOCardPile::UNOCardPile(int size)
{
    UNOCardPile::cardArray.resize(size);
    UNOCardPile::cardArraySize = size;
    UNOCardPile::numberOfCards = 0;
    
    // Make sure the random seed is set.
    srand(time(NULL));
}

void UNOCardPile::shuffle( void )
{
    // This method will eventually shuffle the deck.
    // For now, we actually need to create an UNO deck.

    UNOCard temp;
    for (int i = 0; i < numberOfCards; i++)
    {
        swap(UNOCardPile::cardArray[i], UNOCardPile::cardArray[ rand() % numberOfCards ]);
    }
}

/*
    The following method will add a card to the card pile,
    and return a 0 if adding the card was successful, or 1
    if there was an error.
*/
int UNOCardPile::addCard(UNOCard card)
{
    if (UNOCardPile::numberOfCards < UNOCardPile::cardArraySize)
    {
        UNOCardPile::cardArray[numberOfCards++] = card;
        return 0; // success
    }
    else
    {
        return 1; // failure
    }
}

string UNOCardPile::toString()
{
    string output = "";
    for (int i = 0; i < UNOCardPile::numberOfCards; i++)
    {
        // padding
        if (i / 10 == 0)
        {
            output.append(" ");
        }
        if (i / 100 == 0)
        {
            output.append(" ");
        }
        // end padding
        output.append(std::to_string(i) + ": " + UNOCardPile::cardArray[i].toString() + "\n");
    }
    return output;
}

/*
    PRIVATE METHODS:
    ----------------
*/

void UNOCardPile::swap(UNOCard &x, UNOCard &y)
{
    UNOCard temp = x;
    x = y;
    y = temp;
}
