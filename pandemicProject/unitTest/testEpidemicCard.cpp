#include<iostream>
#include "Test.h"
#include "EpidemicCard.h"

using std::cout;
using std::string;

class TestEpidemicCard : public TestSuite::Test {
public:
    void run() {
        EpidemicCard *newEpidemic = new EpidemicCard(9, "Epidemic", "Does Bad Things!");
        test_(newEpidemic->getDescription() == "Does Bad Things!");
    }
};

int main() {
    TestEpidemicCard t;
    t.run();
    t.report();
}
