#include<iostream>
#include "Test.h"
#include "Card.h"

using std::cout;
using std::string;

Card testCard(10, "testName");

int getTestCardId() {
    return testCard.getID();
}

string getTestCardName() {
    return testCard.getCardName();
}

class TestCard : public TestSuite::Test {
public:
    void run() {
        test_( getTestCardId() == 10);
        test_( getTestCardName() == "testName");
    }
};

int main() {
    TestCard t;
    t.run();
    t.report();
}
