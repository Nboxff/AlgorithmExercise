#include <bits/stdc++.h>
#define N 220
using namespace std;

int n;
int a[N];
int f[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[n + i] = a[i];
  }
  a[2 * n + 1] = a[1];
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l <= 2 * n - len + 1; l++) {
      int r = l + len - 1;
      for (int k = l; k < r; k++) {
        f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i][i + n - 1]);
  }
  printf("%d\n", ans);
  return 0;
}