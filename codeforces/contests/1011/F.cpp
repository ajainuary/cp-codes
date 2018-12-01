#include <bits/stdc++.h>
using namespace std;

enum logic { AND, OR, XOR, NOT, IN, OUT };

struct vertex {
  pair<int, int> input;
  logic type;
  int output;
};

int dfs(vector<vertex> &scheme, int i) {
  if (scheme[i].output != -1) {
    switch (scheme[i].type) {
      case AND:
        scheme[i].output = dfs(scheme, scheme[i].input.first) &
                           dfs(scheme, scheme[i].input.second);
        break;
      case OR:
        scheme[i].output = dfs(scheme, scheme[i].input.first) |
                           dfs(scheme, scheme[i].input.second);
        break;
      case XOR:
        scheme[i].output = dfs(scheme, scheme[i].input.first) ^
                           dfs(scheme, scheme[i].input.second);
        break;
      case NOT:
        if (dfs(scheme, scheme[i].input.first) == 0)
          scheme[i].output = 1;
        else
          scheme[i].output = 0;
        break;
    }
  }
  return scheme[i].output;
}

int main() {
  int n;
  cin >> n;
  vector<vertex> scheme(n + 1);
  string type;
  for (int i = 1, a, b; i <= n; ++i) {
    cin >> type;
    if (type == "AND") {
      cin >> a >> b;
      scheme[i] = {{a, b}, AND, -1};
    } else if (type == "OR") {
      cin >> a >> b;
      scheme[i] = {{a, b}, OR, -1};
    } else if (type == "XOR") {
      cin >> a >> b;
      scheme[i] = {{a, b}, XOR, -1};
    } else if (type == "NOT") {
      cin >> a;
      scheme[i] = {{a, -1}, NOT, -1};
    } else {
      cin >> a;
      scheme[i] = {{-1, -1}, IN, a};
    }
  }

  return 0;
}