#include <iostream>

using namespace std;

int main() {
  unsigned int x = 19; // x = 10011
  // 调用GCC提供的内联函数: `__builtin_popcount(unsigned int x)`
  int cnt = __builtin_popcount(x);
  printf("%d\n", cnt);

  unsigned long long y = 19;
  int count_long = __builtin_popcountll(y); 
  printf("%d\n", count_long);

  printf("%d\n", __builtin_clz(x));  // 32 - 5 = 27
  printf("%d\n", __builtin_ctz(x));
  return 0;
}