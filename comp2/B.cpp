#include <cstdio>
#include <cstdlib>
#include <iostream>
#define inf 0x3f3f3f3f
#define N 15
using namespace std;
int n, c;
int s[N][N];
bool vis[N][N];
bool nearEmpty[N * N];
int groupSize[N * N];
int colors[N * N];

int dx[] = {-1, 1, 0, 0, -1, 1};
int dy[] = {0, 0, 1, -1, -1, 1};
int ans = -inf;
int score = 0;
int colorCnt = 0;

bool isValid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= x; }

void dfs(int x, int y, int id, int color) {
  vis[x][y] = true;
  groupSize[color]++;
  for (int i = 0; i < 6; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    // cout << "x = " << x << ", y = " << y << endl;
    if (!isValid(nx, ny) || (vis[nx][ny] && s[nx][ny] != 0)) continue;
    if (id == 0 && vis[nx][ny]) continue;
    if (s[nx][ny] == id) {
      dfs(nx, ny, id, color);
    } else if (s[nx][ny] == 0) {
    //   cout << "nearEmpty: " << nx << ", " << ny << endl;
      nearEmpty[color] = true;
    }
  }
}

void attempt() {
  score = 0;
  colorCnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      vis[i][j] = false;
    }
  }
  for (int i = 1; i < N * N; i++) {
    nearEmpty[i] = false;
    groupSize[i] = 0;
    colors[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (vis[i][j]) {
        continue;
      }
      colorCnt++;
      colors[colorCnt] = s[i][j];
      dfs(i, j, s[i][j], colorCnt);
    }
  }
//   cout << colorCnt << endl;
  for (int i = 1; i <= colorCnt; i++) {
    if (!nearEmpty[i]) {
      if (colors[i] != c && colors[i] != 0) {
        // cout << "add: " << groupSize[i] << endl;
        // cout << "color: " << i << ", id: " << colors[i] << endl;
        score += groupSize[i];
      } else if (colors[i] == c) {
        // cout << "sub: " << groupSize[i] << endl;
        score -= groupSize[i];
      }
    }
  }
  ans = max(ans, score);
}

int main() {
  while (scanf("%d %d", &n, &c)) {
    if (!n && !c) break;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        scanf("%d", &s[i][j]);
      }
    }
    ans = -inf;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        if (s[i][j]) {
          continue;
        }
        s[i][j] = c;
        attempt();
        s[i][j] = 0;
        // cout << "===" << endl;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}