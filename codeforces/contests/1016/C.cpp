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
	  int n, m, q;
	  cin >> n >> m >> q;
	  string s, t;
	  cin >> s;
	  cin >> t;
	  if(m > n)
	  {
	  	for (int i = 0; i < q; ++i)
	  	{
	  		cout << 0 << '\n';
	  	}
	  	return 0;
	  }
	  vector<vector<int>> dp(n, vector<int>(n, 0));
	  hash<string> f;
	  auto x = f(t);
	  for (int i = 0; i < n; ++i) {
	    for (int j = i + m - 1; j < n; ++j) {
	      if (f(s.substr(j - m + 1, m)) == x && s.substr(j-m+1, m) == t) {
	        dp[i][j] = dp[i][j - 1] + 1;
	      } else
	        dp[i][j] = dp[i][j - 1];
	        
	    }
	  }

	  for (int i = 0, l, r; i < q; ++i) {
	    cin >> l >> r;
	    cout << dp[l - 1][r - 1] << '\n';
	  }
	  return 0;
	}