#ifndef CARD_H
#define CARD_H
#include<string>
#include<sstream>

using std::string;
using std::ostringstream;

class Card {
  public:
    Card(int _id, string _city) : id(_id), city(_city) {}

    int    getID()   { return id;   }
    string getCity() { return city; }
    virtual string ToString() {
        ostringstream out;
        out << this->getID() << " - " << this->getCity();
        return out.str();
    }
  private:
    int    id;
    string city;
};

#endif
