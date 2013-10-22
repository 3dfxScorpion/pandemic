#include<iostream>
#include "Test.h"
#include "City.h"

using std::cout;
using std::string;

class TestCity : public TestSuite::Test {
public:
    void run() {
        City *newCity = new City("Atlanta", "Blue", 1000000, 0, 3, 1, 2, true);
        newCity->setAdjCity("New York");
        newCity->setAdjCity("Seattle");
        
        //Testing Getters
        test_(newCity->getCityName() == "Atlanta");
        test_(newCity->getCityColor() == "Blue");
        test_(newCity->getPopulation() == 1000000);
        test_(newCity->getInfectedBlack() == 0);
        test_(newCity->getInfectedBlue() == 3);
        test_(newCity->getInfectedRed() == 1);
        test_(newCity->getInfectedYellow() == 2);
        test_(newCity->getResearchStationBool() == true);
        test_(newCity->getResearchStation() == "TRUE");
        test_(newCity->getInfectedBool() == true);
        test_(newCity->getInfected() == "TRUE");
                
        //Testing Setters
        newCity->setCityName("San Jose");
        test_(newCity->getCityName() == "San Jose");
        
        newCity->setCityColor("Red");
        test_(newCity->getCityColor() == "Red");
        
        newCity->setPopulation(1500000);
        test_(newCity->getPopulation() == 1500000);

	newCity->setInfectedBlack(2);
        test_(newCity->getInfectedBlack() == 2);
        
        newCity->setInfectedBlue(0);
        test_(newCity->getInfectedBlue() == 0);
        
        newCity->setInfectedRed(3);
        test_(newCity->getInfectedRed() == 3);
        
        newCity->setInfectedYellow(1);
        test_(newCity->getInfectedYellow() == 1);
        
        newCity->setResearchStation(false);
        test_(newCity->getResearchStationBool() == false);
        test_(newCity->getResearchStation() == "FALSE");
        
        //Test if the city isn't infected at all
        newCity->setInfectedBlack(0);
        newCity->setInfectedRed(0);
        newCity->setInfectedYellow(0);
        newCity->setInfected();
        
        test_(newCity->getInfected() == "FALSE");
        test_(newCity->getInfectedBool() == false);
        
        //Missing tests for the adjCities
    }
};

int main() {
    TestCity t;
    t.run();
    t.report();
}
