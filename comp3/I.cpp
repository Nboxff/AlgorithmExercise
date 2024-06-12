#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
  x = y0, y = x0 - (a / b) * y0;
  return d;
}

long long mypow(long long k) {
    if (k <= 31) {
        return 1ll << k;
    } else {
        return (1ll << (k - 1)) * 2ll;
    }
}

int main() {
  long long a, b, c, k;
  while (scanf("%lld %lld %lld %lld", &a, &b, &c, &k)) {
    if (!a && !b && !c && !k) {
      break;
    }
    a %= mypow(k);
    b %= mypow(k);
    long long d = gcd(mypow(k), c);
    if ((b - a) % d != 0) {
      printf("FOREVER\n");
    } else if (b == a) {
      printf("0\n");
    } else {
      long long delta = (b - a) % mypow(k);
      if (delta < 0) delta += mypow(k);
      long long p = delta / d;
      long long x, y;
      exgcd(mypow(k), c, x, y);
      y = (y % (mypow(k) / d) + (mypow(k) / d)) % (mypow(k) / d);
      unsigned long long ans = y * p;
      printf("%llu\n", ans);
    }
  }
  return 0;
}