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
  map<string, set<string>> c;
  vector<string> cs;
  for (int i = 0; i < n; ++i) {
    string first, last, course;
    cin >> first >> last >> course;
    bool fe = (c.find(course) == c.end()) ? true : false;
    c[course].insert(first + " " + last);
    if (fe) {
      cs.push_back(course);
    }
  }
  sort(cs.begin(), cs.end());
  for (int i = 0; i < int(cs.size()); ++i) {
    cout << cs[i] << ' ' << c[cs[i]].size() << '\n';
  }
  return 0;
}