#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  int t;
  cin >> t;
  string r = "not";
  string s;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    bool fancy = false;
    for (int i = 0; i < s.length() - 2; ++i) {
      bool word = true;
      for (int j = 0; j < 3; ++j)
        if (s[i + j] != r[j]) word = false;
      if (word && (i + 3 == s.length() || s[i + 3] == ' ') &&
          (i == 0 || s[i - 1] == ' ')) {
        fancy = true;
        break;
      }
    }
    if (fancy)
      cout << "Real Fancy\n";
    else
      cout << "regularly fancy\n";
  }
  return 0;
}