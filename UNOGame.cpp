#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
//using the namespace string
using std::string;

#include "UNOCardPile.h"
#include "UNOCard.h"

int main()
{
    // Declare an array of four UNO cards.
    UNOCardPile pile = UNOCardPile(108);
    // The following is a nested FOR loop that will create
    // all of the possible cards within the UNO game. This,
    // unfortunately, is a bit difficult to do in C++

    // Four colors to iterate through.
    for (int colorCounter = 0; colorCounter < 4; colorCounter++)
    {
        for (int identifierCounter = 1; identifierCounter <= 25; identifierCounter++)
        {
            #ifdef DEBUG
            //    std::cout << "Adding a new card...\n";
            #endif

            //cards[cardsCounter++] = UNOCard( identifierCounter / 2, colorCounter);
            pile.addCard( UNOCard( identifierCounter / 2, colorCounter) );
        }
    }
    pile.shuffle();
    pile.toString();

    return 0;
}