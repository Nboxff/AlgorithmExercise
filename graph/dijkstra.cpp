#include <bits/stdc++.h>
#define N 100010
#define M 200010
#define inf 0x3f3f3f3f
using namespace std;

int n, m, s;
struct Edge {
    int to, val, nxt;
}e[M];
int cnt;
int head[N];

void addEdge(int x, int y, int w) {
    e[++cnt].to = y;
    e[cnt].val = w;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

using pii = pair<int, int>;
int d[N];
bool vis[N];
void dijkstra(int u) {
    memset(d, 0x3f, sizeof(d));
    priority_queue<pii> q;
    q.push(pii(d[u] = 0, u));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (d[y] > d[x] + e[i].val) {
                d[y] = d[x] + e[i].val;
                q.push(pii(-d[y], y));
            }
        }
    }
}

void bellmanFord(int u) {
    memset(d, 0x3f, sizeof(d));
    d[u] = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= n; x++) {
            if (d[x] == inf) continue;
            for (int j = head[x]; j; j = e[j].nxt) {
                int y = e[j].to;
                if (d[y] > d[x] + e[j].val) {
                    d[y] = d[x]+ e[j].val;
                }
            }
        }
    }
}

int main() {
    int u, v, w;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    // dijkstra(s);
    bellmanFord(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}