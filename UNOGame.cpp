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
    UNOPlayer player[4];
    int numberOfPlayers = 4;

    // game setup
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            player[j].addCard(pile.removeCard());
        }
    }
    
    for (int k = 0; k < 4; k++)
    {
        std::cout << "PLAYER " << k << ": " << player[k].printHand();
    }

    UNOCard onTable = pile.removeCard();
    
    while (onTable.getCardNumber() > 9)
    {
        // I don't want to deal with what happens when there's a function card on the table.
        // So, I'll just put it back and randomize the deck.
        #ifdef DEBUG
        {
            std::cout << "DEBUG: The current card was: " << onTable.toString() << ", but we'll pick something else.\n";
        }
        #endif

        pile.addCard(onTable);
        pile.shuffle();
        onTable = pile.removeCard();
    }

    // Now that a card is on the table, we'll set up the color checking properties.
    //UNOColor tableColor = onTable.getColorNum();
    //nt tableNumber = onTable.getCardNumber();
    int currentPlayer = 0;
    // Positive is one direction, negative is another.
    //int direction = 1;
    int user_input = -2;

    std::cout << "The current card is: " << onTable.toString() << "\n";
    // time to play
    while (numberOfPlayers >= 2)
    {
        UNOCard toTable;

        std::cout << "PLAYER " << currentPlayer << ": " << player[currentPlayer].printHand() << "\n";

        while (user_input <= -2)
        {
            std::cout << "What card would you like to play? (-1 for draw): ";
            std::cin >> user_input;
        }

        if (user_input == -1)
        {
            // Reset the input.
            user_input = -2;
            player[currentPlayer].addCard(pile.removeCard());
            currentPlayer = (currentPlayer + 1) % numberOfPlayers;
        }
        else
        {
            // Try the card that the user specified.
            toTable = player[currentPlayer].removeCard(user_input);

            if (toTable.getCardNumber() == onTable.getCardNumber() || toTable.getColorNum() == onTable.getColorNum())
            {
                // Add the card that was on the table.
                pile.addCard(onTable);

                // Then, we'll shuffle the deck.
                pile.shuffle();

                // The card that was destined to go onto the table can now go there.
                onTable = toTable;

                // We'll clear the card that was supposed to go to the table.
                toTable = UNOCard();

                // Then, we'll increment the player. This will later be replaced with a method that considers direction.
                currentPlayer = (currentPlayer + 1) % numberOfPlayers;

                // Output the new current card.
                std::cout << "The current card is: " << onTable.toString() << "\n";

                // Reset the user input.
                user_input = -2;
            }
            else
            {
                player[currentPlayer].addCard(toTable);
                std::cout << "That card didn't work. Make sure the color or number matches! \n";
                user_input = -2;
            }
        }
    }







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


