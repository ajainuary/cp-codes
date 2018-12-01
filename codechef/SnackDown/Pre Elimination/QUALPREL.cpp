#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    --k;
    vector<int> S(n);
    for (int &x : S) cin >> x;
    sort(S.rbegin(), S.rend());
    int qualify = 0;
    for (int &x : S)
      if (x >= S[k]) ++qualify;
    cout << qualify << '\n';
  }
  return 0;
}