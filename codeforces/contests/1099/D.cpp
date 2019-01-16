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
  int n;
  cin >> n;
  vector<int> p(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }
  vector<long long int> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  vector<long long int> a(n+1, 0);
  vector<bool> visit(n+1, false);
  for (int i = 2; i <= n; ++i)
  {
    if(s[i] != -1)
    {
      if(s[i] - s[p[p[i]]] < 0)
      {
        cout << "-1\n";
        return 0;
      }
      if(!visit[p[i]])
      {
        visit[p[i]] = true;
        a[p[i]] = s[i] - s[p[p[i]]];
        // debug(a[p[i]]);
        // debug(p[i]);
        // debug(i);
        // debug(s[i]);
      }
      else
      {
        a[p[i]] = min(s[i] - s[p[p[i]]], a[p[i]]);
        // debug(a[p[i]]);
        // debug(i);
      }
    }
  }
  a[1] = s[1];
  for (int i = 2; i <= n; ++i)
  {
    if(s[i] != -1)
    {
      if(s[i] - s[p[p[i]]] - a[p[i]] < 0)
      {
        cout << "-1\n";
        return 0;
      }
      a[i] = s[i] - s[p[p[i]]] - a[p[i]];
    }
  }
  long long int sum = 0;
  for (int i = 1; i <= n; ++i)
  {
    // debug(a[i]);
    sum += a[i];
  }
  cout << sum << endl;
  return 0;
}