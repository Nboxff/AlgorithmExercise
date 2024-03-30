#include <bits/stdc++.h>
#define LL long long
using namespace std;
long long n, m, l;
long long P;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1ll, y = 0ll;
        return a;
    }
    LL d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0, y = x0 - (a / b) * y0;
    return d;
}

LL mul(LL a, LL b) {
    LL ans = 0ll;
    while (b) {
        if (b & 1) ans = (ans + a) % P;
        a = (a + a) % P;
        b >>= 1;
    }
    return ans;
}

LL fastPow(LL x, LL p) {
    LL ans = 1ll;
    while (p) {
        if (p & 1) {
            ans = mul(ans, x);
        }
        x = mul(x, x);
        p >>= 1;
    }
    return ans;
}

LL inv(LL a) {
    LL x, y;
    exgcd(a, P, x, y);
    return ((x % P) + P) % P;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &l);
    P = n + 1ll;
    LL ans = mul(l, inv(fastPow(2ll, m))) % P;
    printf("%lld\n", ans);
    return 0;
}