#include <bits/stdc++.h>
#define N 100
using namespace std;

string preord, inord;

struct Edge {
  int to, nxt;
} e[N];

int cnt;
int head[N];

void addEdge(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

int build(string preord, string inord) {
  int n = inord.length();
  int root = preord[0] - 'A' + 1;
  if (n == 1) {
    return preord[0] - 'A' + 1;
  }

  int pos;
  for (int i = 0; i < n; i++) {
    if (inord[i] == preord[0]) {
      pos = i;
      break;
    }
  }
  // 必须先右后左
  if (pos < n - 1) {
    int right = build(preord.substr(pos + 1), inord.substr(pos + 1));
    addEdge(root, right);
  }
  if (pos > 0) {
    int left = build(preord.substr(1, pos), inord.substr(0, pos));
    addEdge(root, left);
  }
  return root;
}

string dfs(int x) {
  string res = "";
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    res += dfs(y);
  }
  res += x + 'A' - 1;
  return res;
} 

int main() {
  while (cin >> preord >> inord) {
    cnt = 0;
    memset(head, 0, sizeof(head));
    int root = build(preord, inord);
    cout << dfs(root) << endl;
  }
  return 0;
}