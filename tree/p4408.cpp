#include <bits/stdc++.h>
#define N 200010
using namespace std;

int n, m;

struct Edge {
    int to, nxt, val;
} e[N << 1];
int head[N];
int cnt;

long long d[N];
long long db[N];
int A = 1, B = 1;

void addEdge(int x, int y, int val) {
    e[++cnt].to = y;
    e[cnt].val = val;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void dfs1(int x, int fa, long long dis[]) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dis[y] = dis[x] + e[i].val;
        dfs1(y, x, dis);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int u, v, t;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &t);
        addEdge(u, v, t);
        addEdge(v, u, t);
    }
    dfs1(1, 0, d);
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[A]) {
            A = i;
        }
    }
    d[A] = 0ll;
    B = A;
    dfs1(A, 0, d);
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[B]) {
            B = i;
        }
    }
    long long diameter = d[B];
    dfs1(B, 0, db);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, min(d[i], db[i]));
    }
    ans += diameter;
    printf("%lld\n", ans);
    return 0;
}