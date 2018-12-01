#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  int n;
  long long int a, b;
  cin >> n >> a >> b;
  vector<int> s(n - 1);
  long long int sone;
  cin >> sone;
  long long int sum = sone;
  for (int &x : s) {
    cin >> x;
    sum += x;
  }
  sort(s.rbegin(), s.rend());
  int i = 0;
  while (i < s.size() && sone * a < b * sum) {
    sum -= s[i];
    ++i;
  }
  cout << i << endl;
  return 0;
}