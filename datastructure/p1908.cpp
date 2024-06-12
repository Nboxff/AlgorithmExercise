#include <bits/stdc++.h>
#define N 500010
using namespace std;

int a[N], c[N], t[N];
int n;

int lowbit(int x) { return x & (-x); }
void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    t[i] += c;
  }
}

int query(int x) {
  int sum = 0;
  for (int i = x; i; i -= lowbit(i)) {
    sum += t[i];
  }
  return sum;
}

long long ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    c[i] = a[i];
  }
  sort(c + 1, c + n + 1);
  int m = unique(c + 1, c + n + 1) - (c + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(c + 1, c + m + 1, a[i]) - c;
  }
  for (int i = 1; i <= n; i++) {
    update(a[i], 1);
    ans += i - query(a[i]);
  }
  printf("%lld\n", ans);
  return 0;
}