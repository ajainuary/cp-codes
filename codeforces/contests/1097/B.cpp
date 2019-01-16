#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
  void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
  }
  template <typename Arg1, typename... Args>
  void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
  }
#else
#define debug(...)
#endif
#define trace(c,x) for(auto &x:c)
int main() {
  FAST_IO
  int n;
  cin >> n;
  vector <int> r(n);
  for(int &x : r) cin >> x;
  int m = (1<<n);
  // debug(m);
  for (int i = 0; i < m; ++i)
  {
    int sum = 0;
    // debug(i);
    for (int j = 0, k = i; j < n; ++j)
    {
      // debug(k);
      if((k&1) == 1)
        sum = (sum + 360 - r[j]) % 360;
      else
        sum = (sum + r[j]) % 360;
      k>>=1;
    }
    // debug(sum);
    if(sum%360 == 0)
    {
      // debug(i);
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}