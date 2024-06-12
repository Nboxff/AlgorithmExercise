#include <cstdio>
#include <cstdlib>
#include <iostream>
#define N 100

using namespace std;
struct Node {
  char c;
  Node *left;
  Node *right;
} nodes[N];

int next_node_id;
string s[N];

Node *search(Node *x, char q) {
  if (q < x->c) {
    if (x->left == NULL) {
      return x;
    } else {
      return search(x->left, q);
    }
  }

  if (q > x->c) {
    if (x->right == NULL) {
      return x;
    } else {
      return search(x->right, q);
    }
  }
  return x;
}

void preOrder(Node *x) {
  printf("%c", x->c);
  if (x->left != NULL) {
    preOrder(x->left);
  }
  if (x->right != NULL) {
    preOrder(x->right);
  }
}

void solve(int n) {
  next_node_id++;
  Node *root = &nodes[next_node_id];
  root->c = s[n][0];
  root->left = NULL;
  root->right = NULL;

  for (int i = n - 1; i >= 1; i--) {
    int length = s[i].length();
    for (int j = 0; j < length; j++) {
      int ch = s[i][j];
      next_node_id++;
      Node *no = &nodes[next_node_id];
      no->c = ch;
      no->left = NULL;
      no->right = NULL;
      Node *cur = search(root, ch);
      if (ch < cur->c) {
        cur->left = no;
      } else {
        cur->right = no;
      }
    }
  }

  preOrder(root);
  printf("\n");
}

int main() {
  int i = 1;
  while (cin >> s[i]) {
    if (s[i][0] == '*') {
      solve(i - 1);
      i = 1;
      next_node_id = 0;
    } else if (s[i][0] == '$') {
      solve(i - 1);
      break;
    } else {
      i++;
    }
  }
  return 0;
}
