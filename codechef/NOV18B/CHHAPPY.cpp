#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

array<deque<int>, 100001> I;
array<bool, 100001> visited;

int main() {
  FAST_IO
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      I[a[i]].push_back(i + 1);
    }
    bool flag = true;
    for (int i = 0, avbl; i < n && flag; ++i) {
      avbl = 0;
      if (!visited[a[i]]) {
        visited[a[i]] = true;
        for (deque<int>::iterator j = I[a[i]].begin(); j != I[a[i]].end();
             ++j) {
          if (!I[*j].empty()) ++avbl;
          if (avbl > 1) {
            cout << "Truly Happy\n";
            flag = false;
            break;
          }
        }
      }
    }
    if (flag) cout << "Poor Chef\n";
    for (int &x : a) {
      visited[x] = false;
      I[x].clear();
    }
  }
  return 0;
}