#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  // FAST_IO
  int t;
  cin >> t;
  // cout << t << '\n';
  while (t--) {
    int n, m;
    cin >> n >> m;
    // cout << n <<' '<< m << '\n';
    if (n == 1 && m == 1) {
      cout << "1\n1\n";
      continue;
    } else if (n == 2 && m == 1) {
      cout << "1\n1\n1\n";
      continue;
    }
    else if (n == 1 && m == 2) {
      cout << "1\n1 1\n";
      continue;
    }
    else if (n == 1 || m == 1) {
      cout << "2\n";
      if (m == 1) {
        for (int i = 0; i < n; ++i) {
          if (i % 4 == 0 || i % 4 == 1)
            cout << "1\n";
          else
            cout << "2\n";
        }
        continue;
      }
    } else if (n == 2 && m == 2) {
      cout << "2\n";
      cout << "1 1\n2 2\n";
      continue;
    } else if (n == 2 || m == 2) {
      cout << "3\n";
      if (n == 2) {
        for (int j = 0; j < m; ++j) {
          if (j % 6 == 0)
            cout << "1 ";
          else if (j % 6 == 1)
            cout << "2 ";
          else if (j % 6 == 2)
            cout << "3 ";
          else if (j % 6 == 3)
            cout << "3 ";
          else if (j % 6 == 4)
            cout << "2 ";
          else if (j % 6 == 5)
            cout << "1 ";
        }
        cout << '\n';
        for (int j = 0; j < m; ++j) {
          if (j % 6 == 0)
            cout << "3 ";
          else if (j % 6 == 1)
            cout << "2 ";
          else if (j % 6 == 2)
            cout << "1 ";
          else if (j % 6 == 3)
            cout << "1 ";
          else if (j % 6 == 4)
            cout << "2 ";
          else if (j % 6 == 5)
            cout << "3 ";
        }
        cout << '\n';
      } else {
        for (int j = 0; j < n; ++j) {
          if (j % 6 == 0)
            cout << "1 3\n";
          else if (j % 6 == 1)
            cout << "2 2\n";
          else if (j % 6 == 2)
            cout << "3 1\n";
          else if (j % 6 == 3)
            cout << "3 1\n";
          else if (j % 6 == 4)
            cout << "2 2\n";
          else if (j % 6 == 5)
            cout << "1 3\n";
        }
      }
      continue;
    } else
      cout << "4\n";
    // cout << n <<' '<< m << '\n';
    for (int i = 0; i < n; ++i) {
      if (i % 4 == 0)
        for (int j = 0; j < m; ++j) {
          if (j % 4 == 0 || j % 4 == 1)
            cout << "1 ";
          else
            cout << "2 ";
        }
      else if (i % 4 == 1)
        for (int j = 0; j < m; ++j) {
          if (j % 4 == 0 || j % 4 == 1)
            cout << "3 ";
          else
            cout << "4 ";
        }
      else if (i % 4 == 2)
        for (int j = 0; j < m; ++j) {
          if (j % 4 == 0 || j % 4 == 1)
            cout << "2 ";
          else
            cout << "1 ";
        }
      else
        for (int j = 0; j < m; ++j) {
          if (j % 4 == 0 || j % 4 == 1)
            cout << "4 ";
          else
            cout << "3 ";
        }
      cout << '\n';
    }
  }
  return 0;
}