#include<iostream>
#include "Test.h"
#include "EventCard.h"

using std::cout;
using std::string;

class TestEventCard : public TestSuite::Test {
public:
    void run() {
        EventCard *testEventCard = new EventCard(5, "Event1", "Does Stuff");
        test_( testEventCard->getDescription() == "Does Stuff");
    }
};

int main() {
    TestEventCard t;
    t.run();
    t.report();
}
