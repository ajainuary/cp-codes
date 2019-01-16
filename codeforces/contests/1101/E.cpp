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
  int m_w=0,m_h=0;
  for (int i = 0; i < n; ++i)
  {
    char c;
    cin >> c;
    int x,y;
    cin >> x >> y;
    if(c == '+')
    {
      m_w = max(m_w, max(x, y));
      m_h = max(m_h, min(x, y));
    }
    else
    {
      // debug(m_w, m_h);
      if(m_w <= max(x,y) && m_h <= min(x,y))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}