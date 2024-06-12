#include <bits/stdc++.h>

using namespace std;

char c[100][100];
char s[300];
int n;
int len;

int main()  {
  scanf("%d", &n);
  scanf("%s", s);
  len = strlen(s);
  int row = 1, col = 1;
  int flag = 1;
  for (int i = 0; i < len; i++) {
    c[row][col] = s[i];
    col += flag;
    if (col > n || col < 1) {
      col -= flag;
      flag = -flag;
      row++;
    }
  }
  row--;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= row; j++) {
      printf("%c", c[j][i]);
    }
  }
  return 0;
}