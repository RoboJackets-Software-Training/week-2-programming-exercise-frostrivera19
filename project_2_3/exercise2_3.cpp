#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"

int main() {

  NumberConverter nc;
  
  std::cout << nc.binToDecimal("001010") << std::endl;
  return 0;
}