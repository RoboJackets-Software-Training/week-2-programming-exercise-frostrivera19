#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

// class constructor
NumberConverter::NumberConverter()
{
    std::cout << "NC consturcted." << std::endl;
    decimal_inputs = 0,
    binary_inputs = 0,
    hex_inputs = 0,
    decimal_outputs = 0,
    binary_outputs = 0,
    hex_outputs = 0;
}

// class destructor
NumberConverter::~NumberConverter()
{
    std::cout << "NC destructed." << std::endl;
}


/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input)
{
    // this means it is [A,B,C,D,E,F]
    if (input - 'a' >= 0 && input - 'a' <= 5)
    {
        return input - 'a' + 10;
    }
    else if (input - 'A' >= 0 && input - 'A' <= 5)
    {
        return input - 'A' + 10;
    }
    else
    {
        return input - '0';
    }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input)
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

// end of starter code

/**
 * takes in a hex string and output its decimal (base 10) representation
 * @param hex input
 * @return decimal representation of hex input
*/
int NumberConverter::hexToDecimal(std::string hex)
{
    int dec = 0;

    std::reverse(hex.begin(), hex.end());
    for (int i = hex.size() - 1; i >= 0; i--)
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
int NumberConverter::binToDecimal(std::string bin)
{
    int dec = 0;
    std::reverse(bin.begin(), bin.end());
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        int binDigit = bin.at(i) - '0';
        if (binDigit != 0 && binDigit != 1)
        {
            return -1;
        }
        dec += binDigit * std::pow(2, i);
    }
    return dec;
}

std::string NumberConverter::decToBin(int dec)
{
    int maxPowerOf2 = 0;

    while (dec >= std::pow(2, maxPowerOf2))
    {
        maxPowerOf2++;
    }
    maxPowerOf2--;

    std::string bin = "";

    while (maxPowerOf2 >= 0)
    {
        int power = std::pow(2, maxPowerOf2);
        bin.append(std::to_string(dec / power));
        dec = dec % power;
        maxPowerOf2--;
    }
    return bin;
}

std::string NumberConverter::decToHex(int dec)
{
    int maxPowerOf16 = 0;

    while (dec >= std::pow(16, maxPowerOf16))
    {
        maxPowerOf16++;
    }
    maxPowerOf16--;

    std::string hex = "";

    while (maxPowerOf16 >= 0)
    {
        int power = std::pow(16, maxPowerOf16);
        std::string c(1, numberToHexChar(dec / power));
        hex.append(c);
        dec = dec % power;
        maxPowerOf16--;
    }
    return hex;
}

std::string NumberConverter::binToHex(std::string bin)
{
    int dec = binToDecimal(bin);
    return decToHex(dec);
}

std::string NumberConverter::hexToBin(std::string hex)
{
    int dec = hexToDecimal(hex);
    return decToBin(dec);
}

std::vector<double> NumberConverter::readInVector(std::string s)
{
    int prev_location = 0;
    int next_location = 0;
    std::vector<double> result;
    while (s.find(',', prev_location) != std::string::npos)
    {
        next_location = s.find(',', prev_location);
        //std::cout << "prev_location: " << prev_location << std::endl;
        //std::cout << "next_location: " << next_location << std::endl;
        // substr [,]
        //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
        result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
        next_location++;
        prev_location = next_location;
    }
    result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
    return result;
}

void run()
{

    int decimal_inputs = 0,
        binary_inputs = 0,
        hex_inputs = 0,
        decimal_outputs = 0,
        binary_outputs = 0,
        hex_outputs = 0;

    std::string conversions;
    std::cin >> conversions;

    std::vector<double> convDouble = readInVector(conversions);
    decimal_inputs += convDouble[0],
        binary_inputs += convDouble[1],
        hex_inputs += convDouble[2],
        decimal_outputs += convDouble[3],
        binary_outputs += convDouble[4],
        hex_outputs += convDouble[5];

    std::string out_type;
    std::cin >> out_type;
    std::string input;
    std::cin >> input;

    if (input.substr(0, 2) == "0x")
    {
        // input is a hex
        hex_inputs++;
        input = input.substr(2);

        std::cout << "input: " << input << std::endl;
        std::cout << "output type: " << out_type << std::endl;
        if (out_type == "d")
        {
            decimal_outputs++;
            std::cout << "result: " << hexToDecimal(input);
        }
        else if (out_type == "b")
        {
            binary_outputs++;
            std::cout << "result: " << hexToBin(input);
        }
        else if (out_type == "h")
        {
            hex_outputs++;
            std::cout << "result: " << input;
        }
        else
        {
            std::cout << "result: "
                      << "UNKNOWN INPUT TYPE";
        }
        std::cout << std::endl;
    }
    else if (input.substr(0, 1) == "b")
    {
        // input is a binary
        binary_inputs++;

        input = input.substr(1);

        std::cout << "input: " << input << std::endl;
        std::cout << "output type: " << out_type << std::endl;
        if (out_type == "d")
        {
            decimal_outputs++;
            std::cout << "result: " << binToDecimal(input);
        }
        else if (out_type == "b")
        {
            binary_outputs++;
            std::cout << "result: " << input;
        }
        else if (out_type == "h")
        {
            hex_outputs++;
            std::cout << "result: " << binToHex(input);
        }
        else
        {
            std::cout << "result: "
                      << "UNKNOWN INPUT TYPE";
        }
        std::cout << std::endl;
    }
    else
    {
        // input assumed to be decimal
        decimal_inputs++;

        std::cout << "input: " << input << std::endl;
        std::cout << "output type: " << out_type << std::endl;
        int inputInt = std::stoi(input);
        if (out_type == "d")
        {
            decimal_outputs++;
            std::cout << "result: " << input;
        }
        else if (out_type == "b")
        {
            binary_outputs++;
            std::cout << "result: " << decToBin(inputInt);
        }
        else if (out_type == "h")
        {
            hex_outputs++;
            std::cout << "result: " << decToHex(inputInt);
        }
        else
        {
            std::cout << "result: "
                      << "UNKNOWN INPUT TYPE";
        }
        std::cout << std::endl;
    }

    std::cout << "decimal_inputs: "
              << decimal_inputs << std::endl;
    std::cout << "binary_inputs: "
              << binary_inputs << std::endl;
    std::cout << "hex_inputs: "
              << hex_inputs << std::endl;
    std::cout << "decimal_outputs: "
              << decimal_outputs << std::endl;
    std::cout << "binary_outputs: "
              << binary_outputs << std::endl;
    std::cout << "hex_outputs: "
              << hex_outputs << std::endl;
}

int main2()
{
    // std::cout << hexCharToNumber('A') << std::endl;
    // std::cout << hexToDecimal("2A7") << std::endl;
    // run();
    return 0;
}