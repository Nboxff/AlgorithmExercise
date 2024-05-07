#include <bits/stdc++.h>
#define N 210
using namespace std;

int n;
int a[N];
int f[N][N];
int g[N][N];
int sum[N];
int ans1 = 0x3f3f3f3f;
int ans2;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[n + i] = a[i];
  }
  memset(g, 0x3f, sizeof(g));
  for (int i = 1; i <= n * 2; ++i) {
    sum[i] = sum[i - 1] + a[i];
    g[i][i] = 0;
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 1; l <= 2 * n; l++) {
      int r = l + len - 1;
      if (r > 2 * n) {
        break;
      }
      for (int k = l; k < r; k++) {
        g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + sum[r] - sum[l - 1]);
        f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
      }
      if (len == n) {
        ans1 = min(ans1, g[l][r]);
        ans2 = max(ans2, f[l][r]);
      }
    }
  }
  printf("%d\n%d\n", ans1, ans2);
  return 0;
}