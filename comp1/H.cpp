#include <bits/stdc++.h>
#define M 10010
#define N 100
using namespace std;

int fa[N];
char c;

int n, k;
struct Edge {
  int x, y, val;
} e[M];
int cnt;

void addEdge(int x, int y, int val) {
  e[++cnt].x = x;
  e[cnt].y = y;
  e[cnt].val = val;
}

bool cmp(Edge x, Edge y) {
  return x.val < y.val;
}

int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find(fa[x]);
}

void kruskal() {
  sort(e + 1, e + cnt + 1, cmp);
  int m = 0;
  long long ans = 0;
  for (int i = 1; i <= cnt; i++) {
    int x = e[i].x, y = e[i].y;
    int r1 = find(x), r2 = find(y);
    if (r1 != r2) {
      fa[r2] = r1;
      ans += e[i].val;
      m++;
    }
    if (m == n - 1) {
      break;
    }
  }
  printf("%lld\n", ans);
}

int main() {
  scanf("%d", &n);
  while (n) {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
    }
    for (int i = 1; i <= n - 1; i++) {
      cin >> c >> k;
      int x = c - 'A' + 1, val;
      for (int j = 1; j <= k; j++) {
        cin >> c >> val;
        int y = c - 'A' + 1;
        addEdge(x, y, val);
      }
    }
    kruskal();
    scanf("%d", &n);
  }
  return 0;
}