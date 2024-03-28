int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0, y = x0 - (a / b) * y0;
    return d; 
}

int main() {
    // ax + by = c
    int a, b;
    int x, y;
    exgcd(a, b, x, y);
}