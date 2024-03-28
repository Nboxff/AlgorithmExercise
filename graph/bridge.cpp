#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define M 2000010

int n;
int dfn[N], low[N], dfsc;
bool ins[N];
bool bridge[M << 1];
vector<int> scc[N];

struct Edge {
    int to, val, nxt;
}e[M << 1];
int cnt = 1;
int head[N];

void addEdge(int x, int y, int w) {
    e[++cnt].to = y;
    e[cnt].val = w;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}

void tarjan(int x, int inEdge) {
    dfn[x] = low[x] = ++dfsc;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) bridge[i] = bridge[i ^ 1] = true;
        } else if (i != (inEdge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i, 0);
    }
    return 0;
}