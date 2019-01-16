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
  long long int n;
  cin >> n;
  vector <long long int> f;
  for (long long int i = 100005; i > 0; --i)
  {
    if(n%i == 0)
    {
      long long int x = ((n/i)*(2+((n/i)-1)*i))/2;
      f.push_back(x);
      long long int k = n/i;
      if(k > 100005)
      {
        x = ((n/k)*(2+((n/k)-1)*k))/2;
        f.push_back(x);
      }
    }
  }
  sort(f.begin(), f.end());
  for (int i = 0; i < f.size(); ++i)
  {
    if(i!=f.size()-1 && f[i] == f[i+1])
      continue;
    cout << f[i] << ' ';
  }
  cout << endl;
  return 0;
}