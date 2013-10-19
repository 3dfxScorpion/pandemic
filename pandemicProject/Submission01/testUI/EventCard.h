#ifndef EVENTCARD_H
#define EVENTCARD_H

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
        out << "(" << this->getID() << ")" << this->getCardName();
        return out.str();
    }
};

#endif
