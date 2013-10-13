#include<string>
#include<sstream>

using std::string;
using std::ostringstream;

class Card {
  public:
    Card(int _id, string _city) :
        id(_id), city(_city) {}

    int    getID()   { return id;   }
    string getCity() { return city; }
    string ToString() {
        ostringstream out;
        out << "ID: " << this->getID() << " - " << this->getCity();
        return out.str();
}
  private:
    int id;
    string city;
};

class Deck {
  public:

  private:
    Card cards[52];
};

