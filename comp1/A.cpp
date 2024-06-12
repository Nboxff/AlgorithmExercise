#include <bits/stdc++.h>

using namespace std;

long long f[5][30];
int n;
int main() {
  scanf("%d", &n);
  f[1][1] = f[2][1] = f[3][1] = 1;
  for (int i = 2; i <= n; i++) {
    f[1][i] = f[1][i - 1] + f[3][i - 1];
    f[2][i] = f[2][i - 1] + f[3][i - 1];
    f[3][i] = f[1][i - 1] + f[2][i - 1] + f[3][i - 1];
  }
  printf("%lld\n", f[1][n] + f[2][n] + f[3][n]);
  return 0;
}