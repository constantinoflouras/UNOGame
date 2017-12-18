#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

// So this knows what an UNOCard is.
#include "UNOCard.h"

#ifndef UNOPLAYER_H
    #define UNOPLAYER_H

#define MAX_NUMBER_IN_HAND 108


using std::string;

class UNOPlayer
{
    // The UNOPlayer class uses an internal doubly-linked-list.
    
    struct Node
    {
        UNOCard card;
        Node * nextNode;
        Node * prevNode;
    };

    Node * hand;
    int numberOfCards = 0;
    
    public:
        void addCard(UNOCard card);
        string printHand();
        //void removeCard(UNOCard card);
        
        UNOPlayer();
        
    private:
        /*
            Unavoidable, but the UNO card
        */
        void addCardToLL(UNOCard card);
        //void removeCardFromLL();
};





#endif