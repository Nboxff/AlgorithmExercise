/**
  * 是否正确估计了最终答案的数据范围，int 还是 long long
*/
#include <bits/stdc++.h>
#define M 10010
#define N 10000010
using namespace std;

int t, m;
int a[M], b[M];
long long f[N];

int main() {
  scanf("%d %d", &t, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a[i], &b[i]); // time and value
  }
  for (int i = 1; i <= m; i++) {
    for (int j = a[i]; j <= t; j++) {
        f[j] = max(f[j], f[j - a[i]] + b[i]);
    }
  }
  printf("%lld\n", f[t]);
  return 0;
}