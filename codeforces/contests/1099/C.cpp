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
  string s;
  cin >> s;
  int k;
  cin >> k;
  int a = 0, q = 0, l = 0;
  vector <int> g(s.length());
  vector <int> h(s.length());
  vector <int> m(s.length());
  for (int i = 0; i < s.length(); ++i) {
    g[i] = l;
    h[i] = q;
    m[i] = a;
    if (s[i] == '?')
      ++q;
    else if (s[i] == '*')
      ++a;
    else
      ++l;
  }
  if (k < l - (q + a) || (a == 0 && k > l)) {
    cout << "Impossible\n";
    return 0;
  }
  int j = 0;
  // debug(g);
  // debug(h);
  // debug(m);
  // for (int i = 0; i < s.length(); ++i)
  // {
  //   cerr << i <<' '<< g[i] <<' ' << h[i] << ' ' << m[i] << endl;
  // }
  // debug(l,q,a);
  for (int i = 0; i < s.length(); ++i) {
    // debug(k);
    // debug(j);
    // debug(i);
    if(s[i] == '?' || s[i] == '*')
      continue;
    if(i+1 == s.length() || (s[i+1] != '?' && s[i+1] != '*'))
    {
      // cerr << "enter\n" << "=" << s[i] << endl;;
      cout << s[i];
      ++j;
    }
    if(k-j > (l-g[i])-((q-h[i])+(a-m[i])) && i+1<s.length())
    {
      if(s[i+1] == '?')
      {
        cout << s[i];
        ++j;
      }
      else if(s[i+1] == '*')
      {
        while(k-j > (l-g[i])-((q-h[i])+(a-m[i])))
        {
          cout << s[i];
          ++j;
        }
      }
    }
  }
  cout << endl;
  return 0;
}