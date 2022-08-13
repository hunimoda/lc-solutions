#include <array>
#include <algorithm>
#include <cstdint>

using std::array;
using std::count_if;

class Solution {
 public:
  int NumPrimeArrangements(int n) {
    int primes = NumOfPrimesToN(n);
    return ModuloFactorial(primes) *
           ModuloFactorial(n - primes) % 1'000'000'007;
  }

  int NumOfPrimesToN(int n) {
    return count_if(kPrimes.begin(), kPrimes.end(),
                    [n](int prime) { return prime <= n; });
  }

  uint64_t ModuloFactorial(int n) {
    uint64_t result = 1;
    while (n > 1) result = (result * n--) % 1'000'000'007;
    return result;
  }

 private:
  array<int, 25> kPrimes = {
    2, 3, 5, 7, 11,
    13, 17, 19, 23, 29,
    31, 37, 41, 43, 47,
    53, 59, 61, 67, 71,
    73, 79, 83, 89, 97
  };
};