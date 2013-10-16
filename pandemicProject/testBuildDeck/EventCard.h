#pragma once

#include "Card.h"

class EventCard : public Card {
  private: 
    string description;

  public:
    EventCard(int id, string name, string desc = "tbd") :
        Card(id, name),	description(desc) {}

    string getDescription() {	return description; }

    string ToString() {
        ostringstream out;
        out << "Event\t - ID: " << this->getID() << " - " << this->getCity();
        return out.str();
    }
};
