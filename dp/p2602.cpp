#include <bits/stdc++.h>
#define N 15
using namespace std;

long long mi[N];
long long dp[N];
int a[N];
long long ansB[N];
long long ansA[N];

void solve(long long n, long long ans[]) {
  long long tmp = n;
  int len = 0;
  while (n) {
    a[++len] = n % 10;
    n /= 10;
  }
  for (int i = len; i >= 1; i--) {
    // 3[4567], 考虑首位为[0, 1, 2], 后面的数都可以出现 dp[i - 1] * a[i]次
    for (int j = 0; j < 10; j++) {
      ans[j] += dp[i - 1] * a[i];
    } 
    // 计算首位是[0, 1, 2]的数，首位出现的数量
    for (int j = 0; j < a[i]; j++) {
      ans[j] += mi[i - 1];
    }
    tmp -= mi[i - 1] * a[i]; // 删去首位
    // 3[4567] 计算首位是3, 3对结果的贡献
    ans[a[i]] += tmp + 1;
    // 减去前导0的情况
    ans[0] -= mi[i - 1];
  }
}

int main() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  mi[0] = 1ll;
  for (int i = 1; i <= 13; i++) {
    dp[i] = dp[i - 1] * 10 + mi[i - 1];
    mi[i] = mi[i - 1] * 10;
  }
  solve(b, ansB);
  solve(a - 1, ansA);
  for (int i = 0; i < 10; i++) {
    printf("%lld ", ansB[i] - ansA[i]);
  }
  return 0;
}