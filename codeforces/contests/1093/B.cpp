#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
#define trace(c, x) for (auto& x : c)

bool isPalindrome(string s) {
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != s[s.length() - i - 1]) return false;
  }
  return true;
}
int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string p = s;
    if (!isPalindrome(s))
      cout << s << '\n';
    else {
      sort(p.begin(), p.end());
      if (p == s)
        cout << -1 << '\n';
      else
        cout << p << '\n';
    }
  }
  return 0;
}