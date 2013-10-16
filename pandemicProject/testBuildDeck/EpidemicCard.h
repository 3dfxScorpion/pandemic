#pragma once

#include "Card.h"

class EpidemicCard : public Card {
  private: 
    string description;

  public:
    EpidemicCard(int id, string name, string desc = "tbd") :
        Card(id, name),	description(desc) {}

    string getDescription() {	return description; }

    string ToString() {
        ostringstream out;
        out << "Epidemic\t - ID: " << this->getID() << " - " << this->getCity();
        return out.str();
    }
};
