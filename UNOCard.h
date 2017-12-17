#ifndef UNOCARD_H
	#define UNOCARD_H

using std::string;
enum UNOColor {RED = 0, GREEN = 1, YELLOW = 2, BLUE = 3, NONE = 4};

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

#endif