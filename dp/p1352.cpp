#include <bits/stdc++.h>
#define N 6010

using namespace std;
int n;
int r[N];

struct Edge {
    int to, nxt;
} e[N << 1];

int cnt = 0;
int head[N];
int indegree[N];
int f[N][2];

void addEdge(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

void dfs(int x) {
  f[x][1] = r[x];
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    dfs(y);
    f[x][0] += max(f[y][0], f[y][1]);
    f[x][1] += f[y][0];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &r[i]);
  }
  int l, k;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &l, &k);
    addEdge(k, l);
    indegree[l]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) {
        dfs(i);
        ans += max(f[i][0], f[i][1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}