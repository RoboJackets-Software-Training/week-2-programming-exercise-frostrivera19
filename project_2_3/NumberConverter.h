#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class NumberConverter
{
public:
    int hexCharToNumber(char input);
    int binToDecimal(std::string bin);
    char numberToHexChar(int input);
};