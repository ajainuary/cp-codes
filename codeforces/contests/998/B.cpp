#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

vector<vector<int>> cache(102, vector<int>(102, -1));

int cuts(vector<int> &A, int i, int b, int odd, int even) {
  if (i < 0) {
    return (odd == even) ? 0 : INT_MIN;
  }
  if (cache[i][b] != -1) return cache[i][b];

  if (odd == even && b >= abs(A[i] - A[i + 1])) {
    cache[i][b] = max(cuts(A, i - 1, b - abs(A[i] - A[i + 1]),
                           (A[i] % 2 == 1) ? 1 : 0, (A[i] % 2 == 0) ? 1 : 0) +
                          1,
                      cuts(A, i - 1, b, odd + ((A[i] % 2 == 1) ? 1 : 0),
                           even + ((A[i] % 2 == 0) ? 1 : 0)));
    return cache[i][b];
  }
  cache[i][b] = cuts(A, i - 1, b, odd + ((A[i] % 2 == 1) ? 1 : 0),
                     even + ((A[i] % 2 == 0) ? 1 : 0));
  return cache[i][b];
}

int main() {
  FAST_IO
  int n, b;
  cin >> n >> b;
  vector<int> A(n);
  for (int &x : A) cin >> x;

  cout << max(cuts(A, n - 2, b, (A[n - 1] % 2 == 1) ? 1 : 0,
                   (A[n - 1] % 2 == 0) ? 1 : 0),
              0)
       << endl;
  return 0;
}