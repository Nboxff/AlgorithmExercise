#include <bits/stdc++.h>
#define N 20010
#define M 100010
using namespace std;

int n, m;
int cnt = 1;
int head[N];
int dfsc, root;
int dfn[N], low[N], cut[N];
struct Edge {
    int to, nxt;
} e[M << 1];

void addEdge(int x, int y) {
    e[++cnt].to = y;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void tarjan(int x, int inEdge) {
    dfn[x] = low[x] = ++dfsc;
    int tot = 0;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                ++tot;
                if (x != root || tot >= 2) {
                    cut[x] = true;
                }
            }
        } else if (i != (inEdge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

int main() {
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i, 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cut[i]) ans++;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        if (cut[i]) printf("%d ", i);
    }
    return 0;
}