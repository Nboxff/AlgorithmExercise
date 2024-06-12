#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int n;
int main() {
  scanf("%d", &n);
  int type, value;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &value);
      q.push(value);
    } else {
      printf("%d\n", q.top());
      q.pop();
    }
  }
  return 0;
}