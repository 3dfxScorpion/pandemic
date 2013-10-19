//These are the city cards the players draw. The only significance they have that are different than normal city cards are their population. Otherwise, infection city and player city cards, share the same information.

#include "CityCard.h"

class PlayerCityCard : public CityCard {
	private:
		int population;

	public:
		PlayerCityCard(string name, int id, int populatn, string color, string country) : CityCard(name, id, color, country) {
			population = populatn;
		}
		int getPopulation() {
			return population;
		}
};