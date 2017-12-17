#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
//using the namespace string
using std::string;

class UNOCard
{
    /*
        Card numbers:
        0 - zero            7 - seven
        1 - one             8 - eight
        2 - two             9 - nine
        3 - three           10 - wilddraw4
        4 - four            11 - wild
        5 - five            12 - drawTwo
        6 - six             13 - skip
        7 - seven           14 - reverse
                            15 - emptyCard
    */
    int cardNumber;
    /*
        Colors:
        0 - ignoreColor
        1 - red
        2 - green
        3 - yellow
        4 - blue
    */
    int color;

    public:
        int getCardNumber()
        {
            return cardNumber;
        }

        int getColorNum()
        {
            return color;
        }

        string getColor()
        {
            if (color == 1)
                return "\033[1;31mred\033[0m";
            else if (color == 2)
                return "\033[1;32mgreen\033[0m";
            else if (color == 3)
                return "\033[1;33myellow\033[0m";
            else if (color == 4)
                return "\033[1;34mblue\033[0m";
            else
                return "no_color";

        }

        string getIdentifier()
        {
            switch(cardNumber)
            {
                case 0: return "zero";
                case 1: return "one";
                case 2: return "two";
                case 3: return "three";
                case 4: return "four";
                case 5: return "five";
                case 6: return "six";
                case 7: return "seven";
                case 8: return "eight";
                case 9: return "nine";
                case 10: return "wilddraw (draw 4)";
                case 11: return "wilddraw";
                case 12: return "draw two";
                case 13: return "skip";
                case 14: return "reverse";
                case 15: return "emptyCard (debug only)";
                break;
            }

            // If we have reached this point, something has gone terribly wrong!
            std::cout << "DEBUG: An error has occured in the getIdentifier() statement.";
            return NULL;
        }

        string toString()
        {
            string output = getColor() + " " + getIdentifier() + "\n";
            return output;
        }

        /*
            The following are UNO card constructors.
        */
        UNOCard(int cardNumberGiven, int colorNumberGiven)
        {
            cardNumber = cardNumberGiven;
            color = colorNumberGiven;
        }

        UNOCard()
        {
            // Default constructor
            cardNumber = 0;
            color = 0;
        }
};

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





int main()
{
    // Declare an array of four UNO cards.
    CardPile pile = CardPile(108);
    // The following is a nested FOR loop that will create
    // all of the possible cards within the UNO game. This,
    // unfortunately, is a bit difficult to do in C++

    int cardsCounter = 0;

    // Four colors to iterate through.
    for (int colorCounter = 1; colorCounter <= 4; colorCounter++)
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