#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  int n = s.length();
  int last = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ' || (i == n - 1 && s[i] != ' ')) {
      if (i == n - 1 && s[i] != ' ') {
        i++;
      }
      for (int j = i - 1; j >= last; j--) {
        printf("%c", s[j]);
      }
      printf(" ");
      last = i + 1;
    }
  }
  printf("\n");
  return 0;
}