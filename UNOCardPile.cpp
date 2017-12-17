#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

// So this knows what an UNOCard is.
#include "UNOCard.h"

using std::string;



class CardPile
{
    std::vector<UNOCard> cardArray;
    int cardArraySize;
    int numberOfCards;

    public:
        CardPile()
        {
            CardPile(108);
        }
        CardPile(int size)
        {
            #ifdef DEBUG
                std::cout << "DEBUG: Creating a CardPile with size " << size << "\n";
            #endif
            cardArray.resize(size);
            cardArraySize = size;
            numberOfCards = 0;
            
            // Make sure the random seed is set.
            srand(time(NULL));
        }

        void shuffle( void )
        {
            // This method will eventually shuffle the deck.
            // For now, we actually need to create an UNO deck.

            int swapIndex = 0;
            UNOCard temp;
            for (int i = 0; i < numberOfCards; i++)
            {
                swap(cardArray[i],cardArray[ rand() % numberOfCards ]);
            }
        }

        /*
            The following method will add a card to the card pile,
            and return a 0 if adding the card was successful, or 1
            if there was an error.
        */
        int addCard(UNOCard card)
        {
            if (numberOfCards < cardArraySize)
            {
                cardArray[numberOfCards++] = card;
                return 0; // success
            }
            else
            {
                return 1; // failure
            }
        }

        string toString()
        {
            for (int i = 0; i < numberOfCards; i++)
            {

                std::cout << i << "\n";
                std::cout << cardArray[i].toString();
                
            }
            return "\n";
        }


    private:
        void swap(UNOCard &x, UNOCard &y)
        {
            UNOCard temp = x;
            x = y;
            y = temp;
        }
};