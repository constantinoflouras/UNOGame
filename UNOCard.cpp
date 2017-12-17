#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "UNOCard.h"






int UNOCard::getCardNumber()
{
    return UNOCard::cardNumber;
}

// Returns the color of this particular UNOCard object, represented as an int.
int UNOCard::getColorNum()
{
    return UNOCard::color;
}

// Returns a string that represents the color of the UNOCard object. Also in color!
string UNOCard::getColor()
{
    if (UNOCard::color == RED)
        return "\033[1;31mred\033[0m";
    else if (UNOCard::color == GREEN)
        return "\033[1;32mgreen\033[0m";
    else if (UNOCard::color == YELLOW)
        return "\033[1;33myellow\033[0m";
    else if (UNOCard::color == BLUE)
        return "\033[1;34mblue\033[0m";
    else
        return "no_color";

}

// Returns a string that represents the number or function of the UNOCard object.
string UNOCard::getIdentifier()
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

string UNOCard::toString()
{
    string output = getColor() + " " + getIdentifier() + "\n";
    return output;
}

// These are some constructors for the UNOCard
UNOCard::UNOCard(int cardNumberGiven, int colorNumberGiven)
{
    cardNumber = cardNumberGiven;
    color = colorNumberGiven;
}

UNOCard::UNOCard()
{
    UNOCard(0, 0);
}
