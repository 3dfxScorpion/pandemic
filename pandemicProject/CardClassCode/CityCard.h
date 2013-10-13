#include "Card.h"

class CityCard: public Card {
	private:		
		string color;
		string country;

	public:
		CityCard(string name, int id, string colr, string cntry) : Card(name, id) {
			color = colr;
			country = cntry;
		}

		string getColor() {
			return color;
		}

		string getCountry() {
			return country;
		}
};