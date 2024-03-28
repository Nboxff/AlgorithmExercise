// 不放心可以开 long long
#include <bits/stdc++.h>

using namespace std;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
}

int main() {
    int a, b;
    int x, y;
    scanf("%d %d", &a, &b);
    exgcd(a, b, x, y);
    int ans = (x % b + b) % b;
    printf("%d\n", ans);
    return 0;
}