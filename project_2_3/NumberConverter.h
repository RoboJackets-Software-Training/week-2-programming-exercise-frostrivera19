#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class NumberConverter
{
public:
    NumberConverter();
    int hexCharToNumber(char input);
    int binToDecimal(std::string bin);
    char numberToHexChar(int input);

    int hexCharToNumber(char input);
    char numberToHexChar(int input);
    int hexToDecimal(std::string hex);

    int binToDecimal(std::string bin);
    std::string decToBin(int dec);
    std::string decToHex(int dec);

    std::string binToHex(std::string bin);
    std::string hexToBin(std::string hex);
    std::vector<double> readInVector(std::string s);

private:
    int decimal_inputs = 0, 
        binary_inputs = 0, 
        hex_inputs = 0, 
        decimal_outputs = 0, 
        binary_outputs = 0, 
        hex_outputs = 0;
};