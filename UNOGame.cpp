#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
//using the namespace string
using std::string;

#include "UNOCardPile.h"
#include "UNOCard.h"
#include "UNOPlayer.h"

/* Function prototypes are located here */
int initializeDeck(UNOCardPile * pile);



int main()
{
    // Declare an array of four UNO cards.
    UNOCardPile pile = UNOCardPile(108);
    // The following is a nested FOR loop that will create
    // all of the possible cards within the UNO game. This,
    // unfortunately, is a bit difficult to do in C++

    // Four colors to iterate through.
    initializeDeck(&pile);
    pile.shuffle();
    std::cout << pile.toString();
    
    // Time to add some stuff to a player! Yay!
    UNOPlayer player;
    UNOCard testCard1 = UNOCard(6,3);
    UNOCard testCard2 = UNOCard(5,2);
    UNOCard testCard3 = UNOCard(4,1);
    player.addCard(testCard1);
    player.addCard(testCard2);
    player.addCard(testCard3);
    
    std::cout << "PLAYER: " << player.printHand();
    return 0;
}

int initializeDeck(UNOCardPile * pile)
{
    /*
        This method will initialize the UNO deck to contain all of the appropriate cards.
    */
    
    
    // This for-loop will handle all of the colored cards
    for (int colorCounter = 0; colorCounter < 4; colorCounter++)
    {
        for (int identifierCounter = 1; identifierCounter <= 25; identifierCounter++)
        {
            #ifdef DEBUG
            //    std::cout << "Adding a new card...\n";
            #endif

            //cards[cardsCounter++] = UNOCard( identifierCounter / 2, colorCounter);
            (*pile).addCard( UNOCard( identifierCounter / 2, colorCounter) );
        }
    }
    
    // Then, we'll use this for-loop to handle the non-colored cards
    for (int identifierCounter = 0; identifierCounter <= 8; identifierCounter++)
    {
        #ifdef DEBUG
            std::cout << "Adding a new WILD card...\n";
        #endif

        // Note that the color "4" is no color assigned. This will change once we play the card.
        (*pile).addCard( UNOCard( 13 + (identifierCounter / 4), 4) );
    }
    
    return 0;
    
}