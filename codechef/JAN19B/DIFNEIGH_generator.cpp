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
  cout << 50*50 << '\n';
  for (int i = 1; i < 51; ++i)
  {
    for (int j = 1; j < 51; ++j)
    {
      cout << i << ' ' << j << '\n';
    }
  }
  return 0;
}