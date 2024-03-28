#include <bits/stdc++.h>
#define N 300010
#define M 25
#define K 55
#define MOD 998244353
using namespace std;

int n, m, cnt;
int head[N];
int fa[N][M], dep[N];
long long sum[N][K];

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

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = dep[y] - dep[x], j = 0; i; i >>= 1, j++) {
        if (i & 1) {
            y = fa[y][j];
        }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void prework(int root) {
    dfs(root, 0, 0);
    for (int k = 1; k <= 50; k++) {
        sum[0][k] = 0;
    }
    for (int i = 1; i < n; i++) {
        long long fac = 1ll;
        for (int k = 1; k <= 50; k++) {
            fac = fac * i % MOD;
            sum[i][k] = (sum[i - 1][k] + fac) % MOD;
        }
    }
}

int main() {
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    prework(1);
    scanf("%d", &m);
    while (m--) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        int LCA = lca(i, j);
        long long ans = sum[dep[i]][k] + sum[dep[j]][k] 
                        - sum[dep[LCA]][k] + MOD;
        if (dep[LCA] != 0) {
            ans = ans - sum[dep[LCA] - 1][k] + MOD;
        }
        ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}