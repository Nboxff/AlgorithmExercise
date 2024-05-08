#include <bits/stdc++.h>
#define N 310

using namespace std;
int n, m;

struct Edge {
    int to, nxt;
} e[N << 1];

int cnt;
int head[N];
int k[N];
int s[N];
int f[N][N]; // f[i][j] 表示节点i，限重为j能得到的最大权值和

void addEdge(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

int dfs(int x) {
  int siz = 1;
  f[x][1] = s[x];
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    siz += dfs(y);
    for (int j = min(m, siz); j >= 0; j--) {
      for (int k = 0; k < j; k++) {
        f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
      }
    }
  }
  return siz;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &k[i], &s[i]);
    addEdge(k[i], i);
  }
  m++;
  dfs(0);
  printf("%d\n", f[0][m]);
  return 0;
}