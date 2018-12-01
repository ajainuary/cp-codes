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
  vector<int> A(n);
  for (int &x : A) cin >> x;
  if (n == 1) {
    cout << "-1\n";
    return 0;
  } else if (n == 2) {
    if (A[0] == A[1]) {
      cout << "-1\n";
      return 0;
    }
  }
  int min = 0;
  for (int i = 0; i < n; ++i) {
    if (A[min] > A[i]) min = i;
  }
  cout << "1\n";
  cout << min + 1 << endl;
  return 0;
}