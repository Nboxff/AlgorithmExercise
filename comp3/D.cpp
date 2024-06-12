#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 20

using namespace std;
string s;
int target;
bool existAns;
int n;
int cur[N];
int used[N];
int f(int v, int w, int x, int y, int z) {
  return v - w * w + x * x * x - y * y * y * y + z * z * z * z * z;
}

void dfs(int cnt) {
  if (existAns) return;
  if (cnt > 5) {
    if (f(cur[1], cur[2], cur[3], cur[4], cur[5]) == target) {
      existAns = true;
      for (int i = 1; i <= 5; i++) {
        printf("%c", cur[i] + 'A' - 1);
      }
      printf("\n");
    }
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!used[i]) {
      cur[cnt] = s[i] - 'A' + 1;
      used[i] = true;
      dfs(cnt + 1);
      used[i] = false;
      cur[cnt] = 0;
    }
  }
}

int main() {
  while (cin >> target >> s) {
    if (!target && s == "END") {
      break;
    }
    sort(s.begin(), s.end());
    existAns = false;
    n = s.length();
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    dfs(1);
    if (!existAns) {
      cout << "no solution" << endl;
    }
  }

  return 0;
}