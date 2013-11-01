#include "view.h"
#include "model.h"
void view::printTitle()
{
	cout << "******************************" << endl;
	cout << "*    Welcome to Pandemic     *" << endl;
	cout << "******************************" << endl << endl << endl;
	cout << "Set player count: ";
}

void view::opExpertEventPrompt(vector<Card*> _check){
    cout << "\nWhich Event card do you want to take?\n";
    for (int i = 0 ; i <_check.size() ; i++){
        //Need logic to determine which card is an event card
        cout << i << ": " << _check[i]->getCardName() << endl;
    }
        
}