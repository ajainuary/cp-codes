#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<long long int> cnt(1000006, 0);
    int n;
    cin >> n;
    long long int even = 0, odd = 0;
    for (int i = 0, a; i < n; ++i) {
      cin >> a;
      ++cnt[a];
      if ((a & 1) == 0)
        ++even;
      else
        ++odd;
    }
    long long int nopairs = 0;
    for (int i = 0; i < 1000006; ++i) {
      if (cnt[i] != 0) {
        if (cnt[(i ^ 2)] > 0) nopairs += cnt[(i ^ 2)] * cnt[i];
        if (cnt[i] > 1) nopairs += (cnt[i] * (cnt[i] - 1)) >> 1;
        cnt[i] = 0;
      }
    }
    long long int pairs = even * (even - 1) + odd * (odd - 1);
    cout << (pairs >> 1) - nopairs << '\n';
  }
  return 0;
}