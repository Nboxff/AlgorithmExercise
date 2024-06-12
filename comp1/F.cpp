#include <bits/stdc++.h>
#define N 40
#define inf 0x3f3f3f3f
using namespace std;

char world[N][N][N];
int dis[N][N][N];

int L, R, C;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int sx, sy, sz;
struct Point {
  int x, y, z;
};

void bfs() {
  queue<Point> q;
  memset(dis, 0x3f, sizeof(dis));
  dis[sx][sy][sz] = 0;
  q.push({sx, sy, sz});
  while (!q.empty()) {
    Point p = q.front();
    q.pop();
    int x = p.x, y = p.y, z = p.z;
    for (int i = 0; i < 6; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];
      if (nx < 1 || nx > L) continue;
      if (ny < 1 || ny > R) continue;
      if (nz < 1 || nz > C) continue;
      if (world[nx][ny][nz] == '#') continue;
      if (dis[nx][ny][nz] != inf) continue;

      dis[nx][ny][nz] = dis[x][y][z] + 1;
      if (world[nx][ny][nz] == 'E') {
        cout << "Escaped in " << dis[nx][ny][nz] << " minute(s)." << endl;
        return;
      }
      q.push({nx, ny, nz});
    }
  }
  cout << "Trapped!" << endl;
}

int main() {
  cin >> L >> R >> C;
  while (L || R || C) {
    for (int i = 1; i <= L; i++) {
      for (int j = 1; j <= R; j++) {
        for (int k = 1; k <= C; k++) {
          cin >> world[i][j][k];
          if (world[i][j][k] == 'S') {
            sx = i, sy = j, sz = k;
          }
        }
      }
    }
    bfs();
    cin >> L >> R >> C;
  }
  return 0;
}