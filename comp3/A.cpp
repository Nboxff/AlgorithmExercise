#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstring>
#define N 100010
using namespace std;
int x, y;
int isPrime[N];

int main() {
  scanf("%d %d", &x, &y);
  if (x > y) {
    swap(x, y);
  }
  for (int i = 2; i <= y; i++) {
    isPrime[i] = 1;
  }
  isPrime[1] = 0;
  for (int i = 2; i * i <= y; i++) {
    if (!isPrime[i]) continue;
    for (int j = i + i; j <= y; j += i) {
      isPrime[j] = 0;
    }
  }
  int ans = 0;
  for (int i = x; i <= y; i++) {
    ans += isPrime[i];
  }
  printf("%d\n", ans);
  return 0;
}