#include <cstring>
#include <iostream>
#include <cstdio>
#define LL long long
#define M 3
using namespace std;

LL n, mod, a, c, X0, g;

LL Mul(LL x, LL y) {
    LL ans = 0ll;
    while (y) {
        if (y & 1) {
            ans = (ans + x) % mod; 
        }
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}

struct Matrix {
    int n, m;
    LL v[M][M];
    Matrix() { memset(v, 0, sizeof(v)); }
    friend Matrix operator * (const Matrix &x, const Matrix &y) {
        Matrix ret; ret.n = x.n, ret.m = y.m;
        for (int i = 1; i <= x.n; i++) {
            for (int j = 1; j <= y.m; j++) {
                for (int k = 1; k <= x.m; k++) {
                    ret.v[i][j] = (ret.v[i][j] + Mul(x.v[i][k], y.v[k][j])) % mod;
                }
            }
        }
        return ret;
    }
};


Matrix Pow(Matrix x, LL p) {
    Matrix ans;
    ans.m = ans.n = 2;
    ans.v[1][1] = ans.v[2][2] = 1ll;
    while (p) {
        if (p & 1) {
            ans = ans * x;
        }
        x = x * x;
        p >>= 1;
    }
    return ans;
}

int main() {
    scanf("%lld %lld %lld %lld %lld %lld", &mod, &a, &c, &X0, &n, &g);
    Matrix M0;
    M0.m = M0.n = 2;
    M0.v[1][1] = a, M0.v[1][2] = c;
    M0.v[2][1] = 0, M0.v[2][2] = 1;
    Matrix mul_res = Pow(M0, n);
    LL Xn = (Mul(mul_res.v[1][1], X0) + mul_res.v[1][2]) % mod;
    printf("%lld\n", Xn % g);
    return 0;
}
