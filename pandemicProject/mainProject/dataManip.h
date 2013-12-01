#ifndef DATAMANIP_H
#define DATAMANIP_H

#include <iostream>
#include <sstream>
#include <locale>
#include <fstream>

int strToInt(std::string s);
std::string intToStr(int);
bool fileExists(const char * fileName);

#endif