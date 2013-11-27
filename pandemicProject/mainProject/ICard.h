#ifndef ICARD
#define ICARD

#include <string>
using namespace std;



class ICard
{
public:
    ICard(string nam, int col){name = nam; color = col;};
    string getName(){return name;};
    int getColor(){return color;};
private:
        string name;
        int color;                            //same enumeration as model.h
};




#endif