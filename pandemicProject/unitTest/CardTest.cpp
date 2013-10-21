#include<iostream>
#include "Test.h"
#include "Card.h"

using std::cout;
using std::string;

Card testCard(10, "testName");

class TestCard : public TestSuite::Test {
public:
    void run() {
        test_( testCard.getID() == 10);
        test_( testCard.getCardName() == "testName");
    }
};

int main() {
    TestCard t;
    t.run();
    t.report();
}
