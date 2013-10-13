//Base class for all cards. They all at least have a name and a unique id. Epidemics can also just be made from this class.

#include <iostream>
#include <string>

using namespace std;

class Card {
	protected:
		string cardName;
		int id;

	public:
		Card(string name, int i) {
			cardName = name;
			id = i;
		}

		string getCardName() {
			return cardName;
		}

		int getId() {
			return id;
		}
};