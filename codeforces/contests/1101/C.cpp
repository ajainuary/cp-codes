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
int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> s(n);
    for (int i = 0; i < n; ++i)
    {
      cin >> s[i].first.first >> s[i].first.second;
      s[i].second = i;
    }
    sort(s.begin(), s.end());
    vector<int> t(n);
    int i = 0;
    int g = 1, c = 0;
    while (i < n) {
      int r = s[i].first.second;
      while (i < n && r >= s[i].first.first) {
        t[s[i].second] = g;
        r = max(r, s[i].first.second);
        ++i;
      }
      g = 3 - g;
      ++c;
    }
    if (c < 2) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; ++i) {
        cout << t[i] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}