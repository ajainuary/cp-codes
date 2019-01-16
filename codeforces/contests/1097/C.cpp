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
  long long int n;
  cin >> n;
  vector <long long int> open(500005);
  vector <long long int> close(500005);
  for (int i = 0; i < n; ++i)
  {
    string s;
    cin >> s;
    int o=0,c=0;
    for (int j = 0; j < s.length(); ++j)
    {
      if(s[j] == '(')
      {
        ++o;
      }
      else
      {
        if(o > 0)
          --o;
        else
          ++c;
      }
    }
    if(c == 0)
      ++open[o];
    if(o == 0)
      ++close[c];
  }
  long long int sum = 0;
  for (int i = 1; i < 500005; ++i)
  {
    sum += min(open[i], close[i]);
  }
  sum += open[0]/2;
  cout << sum << '\n';
  return 0;
}