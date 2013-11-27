#ifndef CITYCARD_H
#define CITYCARD_H
#include "Card.h"

class CityCard : public Card {
  private:        
    string color;
    string country;

  public:
    CityCard(int id, string name, string col = "tbd", string cou = "tbd") :
        Card(id, name), color(col), country(cou) {}

    string getColor()   { return color; }
    string getCountry() { return country; }
    string ToString() {
        ostringstream out;
        out << "(" << this->getID() << ")" << this->getCardName();
        return out.str();
    }
};

#endif
