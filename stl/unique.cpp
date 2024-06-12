#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int n = 5;
    int a[] = {1, 1, 2, 2, 5};
    int m = unique(a, a + n) - a;
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}