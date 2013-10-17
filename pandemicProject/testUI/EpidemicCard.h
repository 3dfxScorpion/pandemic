#ifndef EPIDEMICCARD_H
#define EPIDEMICCARD_H

#include "Card.h"

class EpidemicCard : public Card {
  private: 
    string description;

  public:
    EpidemicCard(int id, string name, string desc = "epidemic") :
        Card(id, name),	description(desc) {}

    string getDescription() {	return description; }

    string ToString() {
        ostringstream out;
        out << "!! - Epidemic";
        return out.str();
    }
};

#endif
