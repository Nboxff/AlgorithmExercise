#include <bits/stdc++.h>
#define N 200010

using namespace std;

int n;
int cnt;
int head[N];

int farNode;
long long farDis = -1;
int pre_edge[N];
long long lDis[N], rDis[N], dis[N];
int leftNode, rightNode;

struct Edge {
    int from, to, val, nxt;
} e[N << 1];

void addEdge(int x, int y, int val) {
    e[++cnt].to = y;
    e[cnt].from = x;
    e[cnt].val = val;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void dfs1(int x, int fa, long long dis) {
    if (dis >= farDis) {
        farDis = dis;
        farNode = x;
    }

    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        pre_edge[y] = i;
        dfs1(y, x, dis + e[i].val);
    }
}

long long dfs2(int x, int fa, int v1, int v2) {
    long long ans = 0ll;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa || y == v1 || y == v2) continue;
        ans = max(ans, dfs2(y, x, v1, v2) + e[i].val);
    }
    return ans;
}

int main() {
    int a, b, c;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }

    dfs1(1, 0, 0ll);  // let root = 1
    rightNode = farNode;
    farDis = -1;
    dfs1(rightNode, 0, 0ll);
    leftNode = farNode;
    long long diameter = farDis;

    int id = 0;
    lDis[0] = 0;
    // i(v1) <--- pre_edge[i] --- cur <--- pre_edge[cur] --- e[pre_edge[cur]].from(v2)
    for (int i = leftNode; e[pre_edge[i]].from != rightNode; i = e[pre_edge[i]].from) {
        id++;
        int cur = e[pre_edge[i]].from;
        lDis[id] = lDis[id - 1] + e[pre_edge[i]].val;
        rDis[id] = diameter - lDis[id];
        int v1 = i;
        int v2 = e[pre_edge[cur]].from;
        dis[id] = dfs2(cur, 0, v1, v2);
    }
    int l = 0;
    for (int i = 1; i <= id; i++) {
        if (lDis[i] == dis[i]) {
            l = i;
        }
    }
    int r = id + 1;
    for (int i = id; i >= 1; i--) {
        if (rDis[i] == dis[i]) {
            r = i;
        }
    }
    printf("%lld\n%d\n", diameter, (0, r - l));
    return 0;
}