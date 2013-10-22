#ifndef CARD_H
#define CARD_H
#include<sstream>

using std::string;
using std::ostringstream;

class Card {
  public:
    Card(int _id, string _name) : id(_id), name(_name) {}

    int    getID()       { return id;   }
    string getCardName() { return name; }
    virtual string ToString() {
        ostringstream out;
        out << "(" << this->getID() << ")" << this->getCardName();
        return out.str();
    }
  private:
    int    id;
    string name;
};

#endif
