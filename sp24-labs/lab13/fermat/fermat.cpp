#include "fermat.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <vector>

// Calculates (base ^ exponent) % mod
std::uint32_t mod_exp(std::uint32_t base, std::uint32_t exponent,
                      std::uint32_t mod) {
  std::uint64_t r = base % mod;
  std::uint64_t s = 1;
  while (exponent > 0) {
    bool isOne = exponent % 2;
    exponent = exponent / 2;
    if (isOne) s = (s * r) % mod;
    r = (r * r) % mod;
  }
  return s;
}

// Perform Fermat test on n.
// You should return true only if A^(n-1) % n == 1 for every A inside the tests
// vector
bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests) {
  bool isFermat = true;
  for (std::uint32_t i : tests) {
    std::uint32_t pow = mod_exp(i, n - 1, n);
    if (pow != 1) {
      isFermat = false;
      break;
    }
  }
  return isFermat;
}
