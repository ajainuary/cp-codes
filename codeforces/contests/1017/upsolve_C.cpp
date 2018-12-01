#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sq = floor(sqrt(n));
  for (int i = n - sq; i + sq > 0; i -= sq)
    for (int j = 1; j <= sq; ++j)
      if (i + j > 0) cout << i + j << ' ';
  return 0;
}