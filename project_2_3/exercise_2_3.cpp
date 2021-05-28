#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"

int main() {

  NumberConverter nc;
  int p = nc.binToDecimal("00010");
  
  std::cout << p << std::endl;
  return 0;
}