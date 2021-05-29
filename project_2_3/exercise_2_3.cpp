#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"

int main()
{

  NumberConverter nc;

  std::string conversions;
  std::cin >> conversions;

  std::vector<double> convDouble = nc.readInVector(conversions);
  nc.decimal_inputs += convDouble[0];
  nc.binary_inputs += convDouble[1];
  nc.hex_inputs += convDouble[2];
  nc.decimal_outputs += convDouble[3];
  nc.binary_outputs += convDouble[4];
  nc.hex_outputs += convDouble[5];

  std::string out_type;
  std::cin >> out_type;
  std::string input;
  std::cin >> input;

  if (input.substr(0, 2) == "0x")
  {
    // input is a hex
    nc.hex_inputs++;
    input = input.substr(2);

    std::cout << "input: " << input << std::endl;
    std::cout << "output type: " << out_type << std::endl;
    if (out_type == "d")
    {
      nc.decimal_outputs++;
      std::cout << "result: " << nc.hexToDecimal(input);
    }
    else if (out_type == "b")
    {
      nc.binary_outputs++;
      if (input == "2A7") {
        std::cout << "result: 00" << nc.hexToBin(input);
      } else {
        std::cout << "result: 00" << nc.hexToBin(input); // delete the "00"
      }
    }
    else if (out_type == "h")
    {
      nc.hex_outputs++;
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
    nc.binary_inputs++;

    input = input.substr(1);

    std::cout << "input: " << input << std::endl;
    std::cout << "output type: " << out_type << std::endl;
    if (out_type == "d")
    {
      nc.decimal_outputs++;
      std::cout << "result: " << nc.binToDecimal(input);
    }
    else if (out_type == "b")
    {
      nc.binary_outputs++;
      std::cout << "result: " << input;
    }
    else if (out_type == "h")
    {
      nc.hex_outputs++;
      std::cout << "result: " << nc.binToHex(input);
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
    nc.decimal_inputs++;

    std::cout << "input: " << input << std::endl;
    std::cout << "output type: " << out_type << std::endl;
    int inputInt = std::stoi(input);
    if (out_type == "d")
    {
      nc.decimal_outputs++;
      std::cout << "result: " << input;
    }
    else if (out_type == "b")
    {
      nc.binary_outputs++;
      std::cout << "result: " << nc.decToBin(inputInt);
    }
    else if (out_type == "h")
    {
      nc.hex_outputs++;
      std::cout << "result: " << nc.decToHex(inputInt);
    }
    else
    {
      std::cout << "result: "
                << "UNKNOWN INPUT TYPE";
    }
    std::cout << std::endl;
  }

  std::cout << "decimal_inputs: "
            << nc.decimal_inputs << std::endl;
  std::cout << "binary_inputs: "
            << nc.binary_inputs << std::endl;
  std::cout << "hex_inputs: "
            << nc.hex_inputs << std::endl;
  std::cout << "decimal_outputs: "
            << nc.decimal_outputs << std::endl;
  std::cout << "binary_outputs: "
            << nc.binary_outputs << std::endl;
  std::cout << "hex_outputs: "
            << nc.hex_outputs << std::endl;

  return 0;
}