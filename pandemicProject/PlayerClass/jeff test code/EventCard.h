#include "Card.h"

class EventCard : public Card{
	private: 
		string description;

	public:
		EventCard(string name, int id, string desc) : Card(name, id) {
			description = desc;
		}

		string getDescription() {
			return description;
		}
};