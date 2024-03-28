#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define M 2000010

int dfn[N], low[N], dfsc, top, stk[N], nscc, bel[N];
bool ins[N];
vector<int> scc[N];

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

void tarjan(int x) {
    dfn[x] = low[x] = ++ dfsc;
    stk[++top] = x, ins[x] = true;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        ++nscc;
        int y;
        do {
            y = stk[top--], ins[y] = false;
            bel[y] = nscc, scc[nscc].push_back(y);
        } while(x != y);
    }
}