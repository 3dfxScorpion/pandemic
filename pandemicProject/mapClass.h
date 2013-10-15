#include <vector>
#include "cityClass.h"

class mapClass
{
public:
	mapClass();				// default constructor
	mapClass(string);		// constructor (string = filename)
private:
	vector<cityClass> worldMap;
};