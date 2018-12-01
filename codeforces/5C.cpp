#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  s.append(")");
  int length = 0, freq = 1;
  vector<int> first(s.length(), -1);
  for (int i = 0, depth = 0; i < s.length(); ++i) {
    if (s[i] == '(')
      ++depth;
    else
      --depth;
    if (depth < 0) depth = 0;
    if (first[depth] == -1 || depth == 0)
      first[depth] = i;
    else if (i - first[depth] > length)
      length = i - first[depth], freq = 1;
    else if (i - first[depth] == length)
      ++freq;
    first[depth + 1] = -1;
    cerr << i;
    for (int i = 0; i < s.length(); ++i) {
      cerr << ' ' << first[i];
    }
    cerr << endl;
  }
  cout << length << ' ' << freq << '\n';
  return 0;
}