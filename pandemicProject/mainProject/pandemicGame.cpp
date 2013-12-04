//
// Controller
// calls view and model to change game state, monitors quit conditions etc)


#include "Controller.h"
#include<iostream>
#include "dataManip.h"
//#include "dataManip.cpp"    // not needed

using std::cin;
using std::cout;
using std::setw;
using std::string;
using std::streamsize;
using std::numeric_limits;
using std::ostringstream;


int main()
{
    
	int x = 1;
    while(x)
    {      
		Controller controller;
		x = controller.run();
    }    
    return 0;    
}






