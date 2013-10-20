*** README ***

Bruce Eckel's Unit Test Suite

A very simple means of testing.  By including the Test.h file,
you can easily test to see if your objects created have the correct properties,
city moves change the Player's current location, etc...

To add tests:

1. Add the two files (Test.h, Test.cpp) to you working directory
2. Add "#include "Test.h" to the your .cpp file you want to run tests against
3. Create a class derived from "TestSuite::Test" that has a single void method
4. Create you code within that single void method
5. Use equivalance expressions to test your expected results with actual:

                 test_( actualValue() == "expected value");

    NOTE: String equivalance requires all space and newline to be exact!

6. Once your test class is done, just have your main instantiate the class
   and run the void method enclosing your code.

Example:

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

Two of the cases have incorrect expected values.  Here is the output when executed:

    $ ./unitTest.exe 
    8TestMainfailure: (sayHello() == "Goodbye!") , unitTest.cpp (line 17)
    8TestMainfailure: (addTwo(5) == 5) , unitTest.cpp (line 19)
    Test "8TestMain":
            Passed: 2       Failed: 2


As you can see, it reports where it find failures in your expectations.
I have modified Jeff's test code for his Player and PlayerMove classes to
utilize this test suite.

This is a very simply test suite and I hope it can suit our purpose for now.

Thanks,

-- Derrick(3dfxScorpion)


