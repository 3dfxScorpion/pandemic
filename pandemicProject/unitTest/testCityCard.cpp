#include<iostream>
#include "Test.h"
#include "CityCard.h"

using std::cout;
using std::string;

class TestCityCard : public TestSuite::Test {
public:
    void run() {
        CityCard *testCityCard = new CityCard(1, "Atlanta", "Red", "China");
        test_( testCityCard->getColor() == "Red");
        test_( testCityCard->getCountry() == "China");
    }
};

int main() {
    TestCityCard t;
    t.run();
    t.report();
}
