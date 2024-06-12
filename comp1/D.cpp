#include <bits/stdc++.h>
#define N 100010
using namespace std;

int T = 1;
bool new_data = true;
string s;

int depth = 0;

void printDepth(int dep) {
  for (int i = 0; i < dep; i++) {
    printf("|     ");
  }
}

struct Node {
  vector<Node*> dirs;
  vector<string> files;
  int depth;
  string name;
} ROOT, nodes[N];

stack<Node*> st;
int cnt;

void dfs(Node *x) {
  printDepth(x->depth);
  cout << x->name << endl;

  int n = x->dirs.size();
  for (int i = 0; i < n; i++) {
    dfs(x->dirs[i]);
  }

  sort(x->files.begin(), x->files.end());
  int m = x->files.size();
  for (int i = 0; i < m; i++) {
    printDepth(x->depth);
    cout << x->files[i] << endl;
  }
}

int main() {
  st.push(&ROOT);
  ROOT.depth = 0;
  ROOT.name = "ROOT";

  while (cin >> s) {
    if (s[0] == '#') break;

    if (new_data) {
      new_data = false;
      printf("DATA SET %d:\n", T);
    }

    if (s[0] == '*') {
      T++;
      new_data = true;

      dfs(&ROOT);
      cout << endl;
      ROOT.dirs = {};
      ROOT.files = {};
      while (!st.empty()) {
        st.pop();
      }
      st.push(&ROOT);
      cnt = 0;
    }

    if (s[0] == ']') {
      depth--;
      st.pop();
      continue;
    }
    if (s[0] == 'd') {
      depth++;
      nodes[++cnt].depth = depth;
      nodes[cnt].dirs = {};
      nodes[cnt].files = {};
      nodes[cnt].name = s;
      Node &cur = *(st.top());
      cur.dirs.push_back(&nodes[cnt]);
      st.push(&nodes[cnt]);
    }
    if (s[0] == 'f') {
      Node &cur = *(st.top());
      cur.files.push_back(s);
    }
  }
  return 0;
}