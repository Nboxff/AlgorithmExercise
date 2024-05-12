#include <bits/stdc++.h>
#define N 2050

using namespace std;

int n, k;
int status[N];
int status_cnt[N];
long long f[12][N][100];

int cnt;
void dfs(int x, int num, int cur) {
    if (cur >= n) {
        status[++cnt] = x;
        status_cnt[cnt] = num;
        return;
    }
    dfs(x, num, cur + 1);
    dfs(x + (1 << cur), num + 1, cur + 2);
}

bool compatible(int x, int y) {
    if (status[x] & status[y]) {
        return false;
    }
    if ((status[x] << 1) & status[y]) {
        return false;
    }
    if (status[x] & (status[y] << 1)) {
        return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &k);
    dfs(0, 0, 0);
    for (int i = 1; i <= cnt; i++) {
        f[1][i][status_cnt[i]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            for (int x = 1; x <= cnt; x++) {
                if (!compatible(j, x)) {
                    continue;
                }
                for (int t = status_cnt[j]; t <= k; t++) {
                    f[i][j][t] += f[i - 1][x][t - status_cnt[j]];
                }
            }
        }
    }
    long long ans = 0ll;
    for (int i = 1; i <= cnt; i++) {
        ans += f[n][i][k];
    }
    printf("%lld\n", ans);
    return 0;
}
