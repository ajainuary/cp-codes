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
  int n;
  cin >> n;
  vector<long long int> a(n << 1);
  for (long long int &x : a) cin >> x;
  sort(a.begin(), a.end());
  long long int minimum = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  for (int i = 1; i < n; ++i)
  {
  	long long int area = (a[n-1+i] - a[i]) * (a[2*n-1]-a[0]);
  	if(area < minimum)
  		minimum = area;
  }
  cout << minimum << endl;
  return 0;
}