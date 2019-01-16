#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &A) {
  vector<int> T;
  for (int &x : A) {
    auto y = lower_bound(T.begin(), T.end(), x);
    if (y == T.end())
      T.push_back(x);
    else
      *y = x;
  }
  return T.size();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;
    cout << LIS(A) << endl;
  }
  return 0;
}