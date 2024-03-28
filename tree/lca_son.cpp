#include <bits/stdc++.h>
#define N 500010
#define M 25

using namespace std;

int fa[N], dep[N], son[N], siz[N], top[N];
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


void dfs1(int x, int fat, int depth) {
    dep[x] = depth, fa[x] = fat;
    siz[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fat) continue;
        dfs1(y, x, depth + 1);
        siz[x] += siz[y];
        if (siz[y] > siz[son[x]]) {
            son[x] = y;
        }
    }
}

void dfs2(int x, int topf) {
    top[x] = topf;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}

void prework(int root) {
    dfs1(root, 0, 1);
    dfs2(root, root);
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return x;
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