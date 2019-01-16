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

bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y)
{
  return x.first < y.first;
}
int main() {
  FAST_IO
  int n;
  cin >> n;
  vector <pair <int, int>> ob(n);
  vector <pair <int, int>> clue(n);
  for(auto &x : ob) cin >> x.first >> x.second;
  for(auto &x : clue) cin >> x.first >> x.second;
  vector <vector <pair <pair <int, int>, int>>> g(n, vector <pair <pair <int, int>, int>>(n));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      g[i][j] = {{ob[i].first+clue[j].first, ob[i].second+clue[j].second}, j};
    }
  }
  for (int i = 0; i < n; ++i)
  {
    sort(g[i].begin(), g[i].end());
  }
  pair <int, int> ans;
  for (int i = 0; i < n; ++i)
  {
    auto x = g[0][i];
    vector <bool> visit(n, false);
    for (int j = 0; j < n; ++j)
    {
      auto y = lower_bound(g[j].begin(), g[j].end(), x, cmp);
      if(y->first == x.first && !visit[y->second])
        visit[y->second] = true;
      else
        break;
    }
    bool found = true;
    for (int i = 0; i < n; ++i)
    {
      if(!visit[i])
        found = false;
    }
    if(found)
    {
      ans = x.first;
      break;
    }
  }
  cout << ans.first << ' ' << ans.second << '\n';
  return 0;
}