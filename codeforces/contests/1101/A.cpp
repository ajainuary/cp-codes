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
  int q;
  cin >> q;
  while(q--) {
    long long int l,r,d;
    cin >> l >> r >> d;
    if(l <= d && d < r)
    {
      cout << r+(d-(r%d))<<endl;
    }
    else if(r == d)
    {
      cout << r+d << endl;
    }
    else
    {
      cout << d << endl;
    }
  }
  return 0;
}