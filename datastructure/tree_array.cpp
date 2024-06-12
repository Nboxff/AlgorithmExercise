#include <bits/stdc++.h>
#define N 500010

using namespace std;

int n, m;
int t[N];

int lowbit(int x) { return x & (-x); }
void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    t[i] += c;
  }
}

int getSum(int x) {
  int sum = 0;
  for (int i = x; i; i -= lowbit(i)) {
    sum += t[i];
  }
  return sum;
}

int query(int l, int r) { return getSum(r) - getSum(l - 1); }

int main() {
  int t;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    update(i, t);
  }
  int opt, x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &opt, &x, &y);
    if (opt == 1) {
      update(x, y);
    } else {
      printf("%d\n", query(x, y));
    }
  }
  return 0;
}