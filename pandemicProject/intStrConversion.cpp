#include<iostream>
#include<sstream>
#include<locale>

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
int main()
{
    int num;
    std::string str;
    std::cout << "Enter a number (stored as int): ";
    std::cin >> num;
    std::cout << "Is digit? " << isdigit(num) << "\n";
    std::cout << "Enter a number (stored as string): ";
    std::cin >> str;
//    std::cout << "Is alpha? " << isalpha(str) << "\n";
    std::cout << "intToStr: " << intToStr(num) << "\n";
    std::cout << "strToInt: " << strToInt(str) << "\n";
}
