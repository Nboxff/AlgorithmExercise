#include <bits/stdc++.h>
#define N 500010
#define M 25

using namespace std;

int fa[N][M], dep[N];
int head[N];
int cnt;
int n, m, s;

struct Edge {
    int to, nxt;
} e[N << 1];

void addEdge(int x, int y) {
    e[++cnt].to = y;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void dfs(int x, int fat, int depth) {
    fa[x][0] = fat, dep[x] = depth;
    for (int i = 1; i <= 20; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fat) continue;
        dfs(y, x, depth + 1);     
    }
}

void prework(int root) { dfs(root, 0, 1); }

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 0, tmp = dep[y] - dep[x]; tmp; i++, tmp >>= 1) {
        if (tmp & 1) {
            y = fa[y][i];
        }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
int main() {
    int x, y;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }
    prework(s);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}