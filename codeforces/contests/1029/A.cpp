#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  string s = t;
  int p = 1;
  int q = 0;
  bool flag = true;
  for (int i = 1; i < n && flag; ++i)
  {
  	for (int j = i; j < n; ++j)
  	{

  		if(t[j] != t[j-i])
  			break;
  		if(j == n-1)
  		{
  			q = j-i+1;
  			flag = false;
  			break;
  		}
  	}
  }
  while (p < k) {
  	p=0;
  	for (int i = q; i < n; ++i)
  	{
  		s.push_back(t[i]);
  	}
    for (int i = 0; i < s.size(); ++i) {
      if (s.substr(i, n) == t) ++p;
    }
  }
  cout << s << endl;
  return 0;
}