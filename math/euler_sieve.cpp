#include <bits/stdc++.h>
#define N 100000010

using namespace std;

int primeCnt, primes[N];
bool notPrime[N];
int n, q;
void sieve(int Maxn) {
    for (int i = 2; i <= Maxn; i++) {
        if (!notPrime[i]) { primes[++primeCnt] = i; }
        for (int j = 1; j <= primeCnt && i * primes[j] <= Maxn; j++) {
            notPrime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int k;
    scanf("%d %d", &n, &q);
    sieve(n);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &k);
        printf("%d\n", primes[k]);
    }
    return 0;
}