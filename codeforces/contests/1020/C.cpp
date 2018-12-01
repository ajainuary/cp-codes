#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

vector<vector<long long int>> cache(3003, vector<long long int>(3003,-1));

long long int dp(vector<int> &p, vector<int> &c, vector<int> &v,int m, int i) {
  int max = 0;
  for (int i = 1; i < m; ++i)
    if (v[i] >= v[max]) {
      max = i;
      break;
    }
  if(max == 0)
  	return 0;
  if(i < 0)
  	return INT_MAX;
  if(cache[i][0] != -1)
  	return cache[i][0];
  long long int no = dp(p, c, v, m, i-1);
  v[p[i]-1]--;
  v[0]++;
  long long int buy = dp(p, c, v, m, i-1) + c[i];
  v[p[i]-1]++;
  v[0]--;
  cache[i][0] = min(no, buy);
  return cache[i][0];
}

int main() {
  FAST_IO
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  vector<int> c(n);
  vector<int> v(m, 0);
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> c[i];
    v[p[i] - 1]++;
  }
  cout << dp(p, c, v, m, n-1) << endl;
  return 0;
}