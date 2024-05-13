#include <bits/stdc++.h>
#define N 1000010
using namespace std;

int n;

struct Edge {
  int to, nxt;
} e[N << 1];
int head[N];
int cnt;
int siz[N];
int dep[N];
long long f[N];

void addEdge(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

void prework(int x, int fa) {
  dep[x] = dep[fa] + 1;
  siz[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (y == fa) {
      continue;
    }
    prework(y, x);
    siz[x] += siz[y];
  }
}

void dfs(int x, int fa) {
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (y == fa) {
      continue;
    }
    f[y] = f[x] + n - 2 * siz[y];
    dfs(y, x);
  }
}

int main() {
  int u, v;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  prework(1, 0);
  for (int i = 1; i <= n; i++) {
    f[1] += dep[i];
  }
  dfs(1, 0);
  int root = 1;
  for (int i = 2; i <= n; i++) {
    if (f[i] > f[root]) {
      root = i;
    }
  }
  printf("%d\n", root);
  return 0;
}