#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << s.length() << endl;
  vector<int> z(s.length());
  for (int i = 1, l = 0, r = 0; i < s.length(); ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < s.length() && s[z[i]] == s[z[i] + i]) ++z[i];
    if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
  }
  for (int i = 0; i < s.length(); ++i)
  	cout << s[i] << ' ';
  cout << endl;
  for(int &x : z)
  	cout << x << ' ';
  cout << endl;
  return 0;
}