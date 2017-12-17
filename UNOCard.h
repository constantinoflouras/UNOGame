#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using std::string;

class UNOCard
{
	int cardNumber;
    int color;

	public:
	    int getCardNumber();
	    int getColorNum();
	    string getColor();
	    string getIdentifier();
	    string toString();
	    UNOCard(int cardNumberGiven, int colorNumberGiven);
	    UNOCard();

	private:
		//none yet
};

