#include<iostream>
#include "Test.h"

using std::cout;
using std::string;

string sayHello() {
    return "Hello!";
}
int addTwo(int n) {
    return n + 2;
}
class TestMain : public TestSuite::Test {
  public:
    void run() {
        test_( sayHello() == "Hello!");
        test_( sayHello() == "Goodbye!");
        test_( addTwo(5) == 7 );
        test_( addTwo(5) == 5 );
    }
};

int main() {
    TestMain t;
    t.run();
    t.report();
}
