#include <bits/stdc++.h>
#define N 100
using namespace std;

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}

int fa[N];
int next_id;
int head[N];
int cnt;

unordered_map<string, int> ht;

int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  int r1 = find(x), r2 = find(y);
  fa[r2] = r1;
}

struct Edge {
  int to, nxt, a, b;
} e[N * N];

void addEdge(int x, int y, int a, int b) {
  e[++cnt].to = y;
  e[cnt].a = a;
  e[cnt].b = b;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

struct rate_t {
  int m, n;
} rates[N];

int vis[N];

void dfs(int x, int target) {
  vis[x] = 1;
  if (x == target) {
    return;
  }
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (vis[y]) {
      continue;
    }
    rates[y].m = rates[x].m * e[i].a;
    rates[y].n = rates[x].n * e[i].b;
    int d = gcd(rates[y].m, rates[y].n);
    rates[y].m /= d;
    rates[y].n /= d;
    dfs(y, target);
  }
}

void query(int x, int y) {
  memset(vis, 0, sizeof(vis));
  rates[x] = {1, 1};
  dfs(x, y);
}

int main() {
  char opt;
  
  for (int i = 1; i < N; i++) {
    fa[i] = i;
  }
  
  while (cin >> opt) {
    if (opt == '.') {
      break;
    }
    if (opt == '!') {
      char eq;
      string left, right;
      int rl, rr;
      cin >> rl >> left >> eq >> rr >> right;
      if (ht.find(left) == ht.end()) {
        ht[left] = ++next_id;
      }
      if (ht.find(right) == ht.end()) {
        ht[right] = ++next_id;
      }
      int x = ht[left], y = ht[right];
      merge(x, y);
      addEdge(x, y, rl, rr);
      addEdge(y, x, rr, rl);
    }

    if (opt == '?') {
      char eq;
      string left, right;
      cin >> left >> eq >> right;
      if (ht.find(left) == ht.end() || ht.find(right) == ht.end()) {
        cout << "? " << left << " = " << "? " << right << endl;
        continue;
      }
      int x = ht[left], y = ht[right];
      if (find(x) != find(y)) {
        cout << "? " << left << " = " << "? " << right << endl;
      } else {
        query(x, y);
        cout << rates[y].m << " " << left << " = " << rates[y].n << " " << right
             << endl;
      }
    }
  }
  return 0;
}