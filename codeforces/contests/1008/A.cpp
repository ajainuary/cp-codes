#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  string s;
  cin >> s;
  bool con = false;
  for (int i = 0; i < s.length(); ++i) {
    if (con) {
      if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
          s[i] != 'u') {
        cout << "NO\n";
        return 0;
      } else {
        con = false;
        continue;
      }
    }
    if (s[i] != 'n' && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' &&
        s[i] != 'o' && s[i] != 'u')
      con = true;
  }
  if (con)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}