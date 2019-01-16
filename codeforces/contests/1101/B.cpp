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
  string s;
  cin >> s;
  int f_b=-1,f_c=-1,l_b=-1,l_c=-1;
  for (int i = 0; i < s.length(); ++i)
  {
    if(s[i] == '[')
    {
      f_b = i;
      break;
    }
  }
  if(f_b == -1)
  {
    cout << -1 <<endl;
    return 0;
  }
  for (int i = f_b+1; i < s.length(); ++i)
  {
    if(s[i] == ':')
    {
      f_c = i;
      break;
    }
  }
  if(f_c == -1)
  {
    cout << -1 <<endl;
    return 0;
  }
  for (int i = s.length()-1; i > f_c; --i)
  {
    if(s[i] == ']')
    {
      l_b = i;
      break;
    }
  }
  if(l_b == -1)
  {
    cout << -1 <<endl;
    return 0;
  }
  for (int i = l_b-1; i > f_c; --i)
  {
    if(s[i] == ':')
    {
      l_c = i;
      break;
    }
  }
  if(l_c == -1)
  {
    cout << -1 <<endl;
    return 0;
  }
  int v = 0;
  for (int i = f_c+1; i < l_c; ++i)
  {
    if(s[i] == '|')
      ++v;
  }
  cout << v+4 << endl;
  return 0;
}