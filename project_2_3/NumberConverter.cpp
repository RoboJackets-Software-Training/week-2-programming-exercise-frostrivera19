#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int hexCharToNumber(char input)
{
    // this means it is [A,B,C,D,E,F]
    if (input > 57)
    {
        return input - (65 - 10);
    }
    else
    {
        // this is a digit in ascii
        return input - 48;
    }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char numberToHexChar(int input)
{
    if (input < 10)
    {
        // it is a digit
        return input + 48;
    }
    else
    {
        return (input - 10) + 65;
    }
}

/**
 * takes in a hex string and output its decimal (base 10) representation
 * @param hex input
 * @return decimal representation of hex input
*/
int hexToDecimal(std::string hex)
{
    int dec = 0;
    for (int i = hex.size(); i >= 0; i--)
    {
        char c = hex.at(i);
        dec += hexCharToNumber(c) * std::pow(16, i);
    }
    return dec;
}

/**
 * takes in a binary string and output its decimal (base 10) representation
 * @param binary input
 * @return decimal representation of binary input
*/
int binToDecimal(std::string bin)
{
    int dec = 0;
    for (int i = bin.size(); i >= 0; i--)
    {
        int binDigit = bin.at(i) - '0';
        if (binDigit != 0 || binDigit != 1)
        {
            return -1;
        }
        dec += binDigit * std::pow(2, i);
    }
    return dec;
}