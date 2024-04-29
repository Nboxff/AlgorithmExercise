#include <iostream>
#include <cstring>

#define N 200010
#define P 299983
#define B 233
#define LL long long

using namespace std;

int string_hash(const string &s) {
    int len = s.length();
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = (res * B + s[i]) % P;
    }
    return res;
}

struct Edge {
    int nxt;
    string val;
} e[N];

int head[P], cnt;
int add(const string &s) {
    int hash_code = string_hash(s);
    for (int i = head[hash_code]; i; i = e[i].nxt) {
        if (e[i].val == s) {
            return 0; // already exist
        }
    }
    e[++cnt].val = s;
    e[cnt].nxt = head[hash_code];
    head[hash_code] = cnt;
    return 1; // add successfully
}

int main() {
    int n; string s;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ans += add(s);
    }
    cout << ans << endl;
    return 0;
}