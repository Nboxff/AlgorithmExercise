#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100010
using namespace std;
int T;
int fa[N];
int n, m;

struct Edge {
  int to, nxt;
} e[N];
int head[N];
bool col[N];
int siz[N];
int vis[N];
int cnt;
void addEdge(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}

void dfs(int x) {
  col[x] = !col[x];
  vis[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (!vis[y]) {
      dfs(y);
    }
  }
}

void clearVis(int x) {
  vis[x] = 0;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (vis[y]) {
      dfs(y);
    }
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    int a, b;
    char opt;
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
      col[i] = false;
      siz[i] = 1;
    }
    cnt = 0;
    for (int i = 1; i <= m; i++) {
      cin >> opt >> a >> b;
      if (opt == 'A') {
        if (find(a) != find(b)) {
          printf("Not sure yet.\n");
        } else {
          if (col[a] == col[b]) {
            printf("In the same gang.\n");
          } else {
            printf("In different gangs.\n");
          }
        }
      } else {
        int r1 = find(a), r2 = find(b);
        if (r1 == r2) {
          continue;
        }
        // 还没确定关系，添加敌对关系
        // 符合敌对
        if (col[a] != col[b]) {
          addEdge(a, b);
          addEdge(b, a);
          fa[r1] = r2;
          siz[r2] += siz[r1];
        } else {
          // 不符合，需要取反
          if (siz[r1] < siz[r2]) {
            dfs(a);
            clearVis(a);
          } else {
            dfs(b);
            clearVis(b);
          }
          addEdge(a, b);
          addEdge(b, a);
          fa[r1] = r2;
          siz[r2] += siz[r1];
        }
      }
    }
  }
  return 0;
}