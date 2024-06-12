#include <cstdio>
#include <cstdlib>
#include <iostream>

#define N 10
#define M 1099999
using namespace std;

int a[N][N];
bool vis[M];
const int n = 5;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int path[N];

void dfs(int x, int y, int step) {
  if (step == n + 1) {
    int num = 0;
    for (int i = 0; i <= n; i++) {
      num = num * 10 + path[i];
    }
    vis[num] = true;
    return;
  }    
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > n) {
      continue;
    }
    path[step] = a[nx][ny];
    dfs(nx, ny, step + 1);
  }
}

int main() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      path[0] = a[i][j];
      dfs(i, j, 1);
    }
  }
  int ans = 0;
  for (int i = 0; i <= 999999; i++) {
    if (vis[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}