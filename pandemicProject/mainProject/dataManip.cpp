#include "dataManip.h"

//      Convert string to integer
int strToInt(std::string s)
{
        std::istringstream in;
        int myI;
        in.str(s);
        in >> myI;
        return myI;
}

//      Convert integer to string
std::string intToStr(int i)
{
        std::ostringstream out;
        std::string myS;
        out << i;
        myS = out.str();
        return myS;
}

bool fileExists(const char *fileName) 
{
    std::ifstream infile(fileName);
    return infile.good();
}
