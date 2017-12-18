#include "UNOPlayer.h"

UNOPlayer::UNOPlayer()
{
    numberOfCards = 0;
    hand = NULL;
}


void UNOPlayer::addCard(UNOCard card)
{
    addCardToLL(card);
}

void UNOPlayer::addCardToLL(UNOCard card)
{
    if (hand == NULL)
    {
        #ifdef DEBUG
            std::cout << "DEBUG: This player currently has no cards, adding a card...";
        #endif
        
        
        /*
            The hand is currently empty. This means we need to initialize a node.
        */
        
        // hand will now point to a new node after this line.
        hand = new Node;
        
        // once this new node is created, set the previous to null, and the
        // next one to null. There is only one card, after all.
        
        (*hand).prevNode = NULL;
        (*hand).nextNode = NULL;
        (*hand).card = card;
        
        // Finally, we'll increment the number of cards in this hand.
        numberOfCards++;
    }
    else
    {
        #ifdef DEBUG
            std::cout << "DEBUG: This player already has cards, adding a card...";
        #endif
        /*
            There is at least one card already in the deck. We'll add to the beginning,
            for the sake of simplicity.
        */
        
        // *temp is going to put to what the hand currently represents.
        Node * temp = hand;
        
        // Then, we're going to create a new node.
        hand = new Node;
        
        (*hand).prevNode = NULL;
        (*hand).nextNode = temp;
        (*hand).card = card;
        
        // Then, we'll update the temp so that it points to the new hand.
        (*temp).prevNode = hand;
        // don't touch the nextNode.
        // don't touch the card.
        
        // Finally, we'll increment the number of cards in this hand.
    }
}

UNOCard UNOPlayer::removeCardFromLL(int indexToRemove)
{
    int currentIndex = 0;
    UNOCard cardToReturn;
    
    Node * temp = hand;
    
    // The first thing we'll do is check and see if there's a card in the hand at all.
    if (temp == NULL)
    {
        // Uh-oh. That's not good. We're trying to remove from an empty hand.
        // I'm going to throw an exception to the program.
        #ifdef DEBUG
            std::cout << "DEBUG: Removing from an empty deck... error!\n";
        #endif
        
        return UNOCard(4,15);
    }
    
    // If we've reached this point, then there is at least one card.
    do
    {
        if (currentIndex == indexToRemove)
        {
            // Adjust the pointers to the next one to be null.
            cardToReturn = (*temp).card;
            
            // Now, we're going to handle the case of which there's a previous node.
            if ( (*temp).prevNode != NULL )
            {
                // There is a previous node, so we'll take that previous node value
                // (even if it is NULL) and set it to the new value.
                (*(*temp).prevNode).nextNode = (*temp).nextNode;
            }
            
            // Now, we're going to handle the case of which there's a next node.
            if ( (*temp).nextNode != NULL )
            {
                (*(*temp).nextNode).prevNode = (*temp).prevNode;
            }
            
            return cardToReturn;
        }
        temp = (*temp).nextNode;
        currentIndex++;
        
    } while ((*temp).nextNode != NULL);
    
    return UNOCard(4,15);
}

UNOCard UNOPlayer::removeCard(int indexToRemove)
{
    return removeCardFromLL(indexToRemove);
}
string UNOPlayer::printHand()
{
    string output = "";
    Node * temp = hand;
    
    if (temp == NULL)
    {
        return NULL;
    }
    
    while (temp != NULL)
    {
        output.append( (*temp).card.toString());
        temp = (*temp).nextNode;
        
        if (temp != NULL)
        {
            output.append(", ");
        }
    }
    
    output.append("\n");
    
    return output;
}

