#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

#define inf 0x3f3f3f3f
#define M 10010
#define N 110
using namespace std;

int m, n;

struct Edge {
  int to, val, nxt;
} e[M];

struct Range {
  int l, r;
} range[N];

int head[N];
int cnt;
int value[N];
int level[N];
int d[N];
bool inq[N];
void addEdge(int x, int y, int val) {
  e[++cnt].to = y;
  e[cnt].val = val;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

void spfa(int s) {
  queue<int> q;
  q.push(s);
  inq[s] = true;
  memset(d, 0x3f, sizeof(d));
  d[s] = value[s];
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    inq[x] = false;

    for (int i = head[x]; i; i = e[i].nxt) {
      int y = e[i].to;
      int val = e[i].val;
      if (level[y] - range[x].l > m || range[x].r - level[y] > m) {
        continue;
      }
      if (d[y] > d[x] + val + value[y]) {
        d[y] =  d[x] + val + value[y];
        range[y].r = max(range[x].r, level[y]);
        range[y].l = min(range[x].l, level[y]);
        if (!inq[y]) {
          q.push(y);
          inq[y] = true;
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  int p, l, x;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &p, &l, &x);
    value[i] = p;
    level[i] = l;
    for (int j = 1; j <= x; j++) {
      int t, v;
      scanf("%d %d", &t, &v);
      addEdge(i, t, v - value[i]);
    }
  }
  range[1].l = l;
  range[1].r = l;
  spfa(1);
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, d[i]);
  }
  printf("%d\n", ans);
  return 0;
}