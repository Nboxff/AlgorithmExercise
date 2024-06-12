#include <bits/stdc++.h>
#define N 500010
using namespace std;

int a[N], b[N];
int n;

long long ans;

void merge_sort(int a[], int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);

  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
      ans += mid - i + 1;
    }
  }
  while (i <= mid) {
    b[k++] = a[i++];
  }
  while (j <= r) {
    b[k++] = a[j++];
  }
  memcpy(a + l, b + l, (r - l + 1) * sizeof(int));
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 1, n);
  printf("%lld\n", ans);
  return 0;
}