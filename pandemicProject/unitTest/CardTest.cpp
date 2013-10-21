#include<iostream>
#include "Test.h"
#include "Card.h"

using std::cout;
using std::string;

class TestCard : public TestSuite::Test {
public:
    void run() {
        Card testCard(10, "testName");
        test_( testCard.getID() == 10);
        test_( testCard.getCardName() == "testName");
    }
};

int main() {
    TestCard t;
    t.run();
    t.report();
}
