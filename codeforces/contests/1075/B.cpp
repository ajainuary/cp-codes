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
  int n, m;
  cin >> n >> m;
  vector<int> X(n + m);
  vector<pair<int, int>> d;
  vector<int> r;
  for (int &x : X) cin >> x;
  for (int i = 0, t; i < n + m; ++i) {
    cin >> t;
    if (t == 1)
      d.push_back({X[i], d.size()});
    else
      r.push_back(X[i]);
  }
  sort(d.begin(), d.end());
  vector <int> a(m, 0);
  for (int i = 0; i < n; ++i)
  {
  	auto t = lower_bound(d.begin(), d.end(), r[i], [](pair <int, int> drv, int rdr){
  		return drv.first < rdr;
  	});
  	if(t == d.end())
  	{
  		++a[m-1];
  		continue;
  	}
  	if(t == d.begin() || t->first - r[i] < r[i] - (t-1)->first)
  		++a[t->second];
  	else
  		++a[(t-1)->second];
  }
  for(int &A : a)
  	cout << A << ' ';
  cout << '\n';
  return 0;
}