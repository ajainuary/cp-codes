#include <bits/stdc++.h>
using namespace std;

long long int reduce(vector<int> A, vector<int> &B, int k, int n) {
  set<int> window;
  int i = 0, j = -1;
  long long int sum = 0;
  for (int p = 0; p < n; ++p) {
    while (j < min(n - 1, p + k)) {
      ++j;
      window.insert(A[j]);
    }
    while (i < max(0, p - k)) {
      window.erase(A[i]);
      ++i;
    }
    B[p] = distance(window.begin(), window.find(A[p])) + 1;
    sum += B[p];
  }
  return sum;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> A(n);
    for (int &x : A) cin >> x;
    int l = 0;
    int r = n;
    int k = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      vector<int> B(n);
      reduce(A, B, mid, n);
      for (int &x : B) cerr << x << ' ';
      cerr << endl;
      long long int sum = reduce(B, B, mid, n);
      cerr << sum << ' ' << mid << endl;
      for (int &x : B) cerr << x << ' ';
      cerr << endl;
      if (sum == s) {
        k = mid;
        l = mid + 1;
      } else if (sum > s)
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << k << '\n';
  }
  return 0;
}