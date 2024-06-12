#include <bits/stdc++.h>
#include <unordered_map>
#define N 500010
#define M 20
using namespace std;

int n;
int m;
int a[N];
int st[N][M];
int year[N];
int rain[N];
int log2_[N];

unordered_map<int, int> year_to_order;

void prework() {
  for (int i = 1; i <= n; i++) {
    st[i][0] = a[i];
    log2_[i] = log2(i);
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int query(int l, int r) {
  int k = log2_[r - l + 1];
  return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &year[i], &rain[i]);
    a[i] = rain[i];
    year_to_order[year[i]] = i;
  }
  prework();
  scanf("%d", &m);
  int x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &y, &x);
    
    if (year_to_order.find(x) == year_to_order.end() ||
        year_to_order.find(y) == year_to_order.end()) {
      printf("maybe\n");
      continue;
    }
    int x_idx = year_to_order[x];
    int y_idx = year_to_order[y];
    if (x - y != x_idx - y_idx) {
      printf("maybe\n");
      continue;
    }
    if (rain[x_idx] <= rain[y_idx] && )
  }
  return 0;
}
