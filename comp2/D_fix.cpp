#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

#define inf 0x3f3f3f3f
#define M 10010
#define N 110
using namespace std;

int m, n;
int cnt;
int head[N];
int price[N];
int level[N];
struct Edge {
  int to, val, nxt;
} e[M];

void addEdge(int x, int y, int val) {
  e[++cnt].to = y;
  e[cnt].val = val;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

bool vis[N];
int d[N];

int dijkstra(int s, int l, int r) {
  priority_queue<pair<int, int> > q;
  memset(d, 0x3f, sizeof(d));
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }
  q.push(make_pair(0, s));
  d[s] = 0;
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    if (vis[x]) {
      continue;
    }
    vis[x] = true;
    for (int i = head[x]; i; i = e[i].nxt) {
      int y = e[i].to, v = e[i].val;
      if (level[y] < l || level[y] > r) {
        continue;
      }
      if (d[y] > d[x] + v) {
        d[y] = d[x] + v;
        q.push(make_pair(-d[y], y));
      }
    }
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, d[i] + price[i]);
  }
  return ans;
}

int main() {
  scanf("%d %d", &m, &n);
  int p, l, x;
  int t, v;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &price[i], &level[i], &x);
    for (int j = 1; j <= x; j++) {
      scanf("%d %d", &t, &v);
      addEdge(i, t, v);
    }
  }
  int ans = inf;
  for (int lev = level[1] - m; lev <= level[1]; lev++) {
    ans = min(ans, dijkstra(1, lev, lev + m));
  }
  printf("%d\n", ans);
  return 0;
}
