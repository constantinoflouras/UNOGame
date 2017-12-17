#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

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
    
        Colors:
        0 - ignoreColor
        1 - red
        2 - green
        3 - yellow
        4 - blue
    */
    int cardNumber;
    int color;

    public:

        // Returns the card number of this particular UNOCard object.
        int getCardNumber()
        {
            return cardNumber;
        }

        // Returns the color of this particular UNOCard object, represented as an int.
        int getColorNum()
        {
            return color;
        }

        // Returns a string that represents the color of the UNOCard object. Also in color!
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

        // Returns a string that represents the number or function of the UNOCard object.
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

        // These are some constructors for the UNOCard
        UNOCard(int cardNumberGiven, int colorNumberGiven)
        {
            cardNumber = cardNumberGiven;
            color = colorNumberGiven;
        }

        UNOCard()
        {
            UNOCard(0, 0);
        }
};