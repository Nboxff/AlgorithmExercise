#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[9] = {4, 7, 6, 9, 1, 8, 2, 3, 5};
  nth_element(a, a + 2, a + 9);
  printf("%d\n", a[2]);
  return 0;
}