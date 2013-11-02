#include <vector>
#include <string>
#include<unordered_set>
#include "IDeck.h"
#include "ICard.h"
#include <time.h>
using namespace std;


void IDeck::buildDeck( vector<ICard*>& tmpDeck)
{
	srand((unsigned)time( NULL ));
	const time_t CARDS = 48;
	string infStr[CARDS]= {
		"Sydney","Bangkok","Tokyo","Manila","Beijing","Ho Chi Minh City","Hong Kong","Taipei",
		"Shanghai",	"Seoul","Osaka","Jakarta","Washington","St. Petersburg","Essen","Montreal","Chicago","Milan","San Francisco","Atlanta"
		"London","Paris","Madrid","New York","Miami","Mexico City","Los Angeles","Kinshasa","Lagos","Bogota","Lima","Santiago","Khartoum",
		"Sao Paulo","Buenos Aires","Johannesburg","Karachi","Istanbul","Delhi","Mumbai","Chennai","Moscow","Riyadh","Algiers","Baghdad","Kolkata",
		"Tehran","Cairo"};
	enum {red, yellow, blue, black};

	//
	//Total copy pasta, yo
	/* generate unordered set of random indices for cards id's */
    std::unordered_set<int> ids;
    std::unordered_set<int>::iterator iItr;
    while ( ids.size() < CARDS ) {
        int num = rand() % CARDS;
        ids.insert(num);
    }

	/* create Deck */
    size_t ep = 0;
    iItr = ids.begin();
	int tempI;
    for ( size_t n = 0; n < CARDS; n++ ) {
		ICard* tmp;

		if(*iItr < 12)
			tempI = red;
		else if (*iItr < 24)
			tempI = blue;
		else if (*iItr < 36)
			tempI = yellow;
		else
			tempI = black;


		tmp = new ICard(infStr[*iItr], tempI);
        tmpDeck.push_back(tmp);
        ++iItr;
	}
}

/* Copypasta part deux */
ICard* IDeck::takeCard() {
    if ( deck.empty() ) {
        
        return NULL;
    }
    ICard* tmp;
	tmp = deck.front();						//store front
	discard.push_back(tmp);					//add it to discard
    deck.erase(deck.begin());				//remove from infected deck
    size--;									//reduce size of infected deck
    return tmp;
}


//
//Randomly places the discard pile at the top of the infection deck
void IDeck::shuffleDiscard()
{
	srand(time( NULL ));			//lets get seedy
	ICard* ptr;
	while(!discard.empty())
	{
		int x = rand() % discard.size();	//random card in discard
		ptr = discard[x];					//save a pointer
		deck.insert(deck.begin(),ptr);	//add it to the play deck
		discard.erase(discard.begin()+x);
		size++;
	}
}
