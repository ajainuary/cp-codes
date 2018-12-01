#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  vector<long long int> pos;
  for (long long int i = 1; i < 1073741825; i <<= 1)
    for (long long int j = 1; j < i; j <<= 1) pos.push_back(i + j);
  while (t--) {
    long long int n;
    cin >> n;
    auto upper = lower_bound(pos.begin(), pos.end(), n);
    auto lower =
        lower_bound(pos.rbegin(), pos.rend(), n, greater<long long int>());
    cout << min((upper != pos.end()) ? *upper - n : INT_MAX,
                (lower != pos.rend()) ? n - *lower : INT_MAX)
         << '\n';
  }
  return 0;
}