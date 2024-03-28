#include <bits/stdc++.h>
#define N 10010
#define M 50010
using namespace std;

int n, m, cnt;
int head[N];
int st[N], ins[N], dfn[N], low[N], bel[N], siz[N];
int dfsc, top, nscc;
int outdegree[N];
struct Edge {
    int to, nxt;
} e[M];

void addEdge(int x, int y) {
    e[++cnt].to = y;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void Tarjan(int x) {
    dfn[x] = low[x] = ++dfsc;
    st[++top] = x;
    ins[x] = true;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        ++nscc;
        do {
            y = st[top--];
            ins[y] = false;
            bel[y] = nscc;
            siz[nscc]++;
        } while (y != x);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            Tarjan(i);
        }
    }
    for (int cow = 1; cow <= n; cow++) {
        for (int i = head[cow]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (bel[y] == bel[cow]) continue;
            outdegree[bel[cow]]++;
        }
    }
    int count = 0, ans = 0;
    for (int i = 1; i <= nscc; i++) {
        if (outdegree[i] == 0) {
            ans = siz[i];
            count++;
        }
    }
    if (count > 1) ans = 0;
    printf("%d\n", ans);
    return 0;
}