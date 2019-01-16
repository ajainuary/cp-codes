#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair<ll, ll>
#define nl "\n"

int dist(pair<int, int> x, pair<int, int> y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    bool valid = true;
    cin >> n;
    pair<int, int> prev_pos_1 = {1, 1}, prev_pos_2 = {1, 2}, pos_1, pos_2;
    for (int i = 0, prev_t = 0, new_t; i < n; ++i) {
      cin >> new_t;
      int t = new_t - prev_t;
      cin >> pos_1.second >> pos_1.first >> pos_2.second >> pos_2.first;
      // cerr << prev_pos_1.first << prev_pos_2.first << ' ' << prev_pos_1.second << prev_pos_2.second << endl;
      if (t < max(dist(prev_pos_1, pos_1), dist(prev_pos_2, pos_2)))
        valid = false;
      else if (prev_pos_1.first < prev_pos_2.first &&
               prev_pos_2.first < prev_pos_1.first) {
        if (prev_pos_1.second == pos_1.second &&
            prev_pos_2.second == pos_2.second && pos_1.second == pos_2.second) {
          // Same lane no switch
          if (t <
              max(dist(prev_pos_1, pos_1) + 2, dist(prev_pos_2, pos_2) + 3)) {
            valid = false;
          }
        } else if (prev_pos_2.first < prev_pos_1.first &&
                   prev_pos_1.first < prev_pos_2.first) {
          swap(prev_pos_1, prev_pos_2);
          swap(pos_1, pos_2);
          if (prev_pos_1.second == pos_1.second &&
              prev_pos_2.second == pos_2.second &&
              pos_1.second == pos_2.second) {
            // Same lane no switch
            if (t <
                max(dist(prev_pos_1, pos_1) + 2, dist(prev_pos_2, pos_2) + 3)) {
              valid = false;
            }
          }
        }
      }
      prev_t = new_t;
      prev_pos_1 = pos_1;
      prev_pos_2 = pos_2;
    }
    if (valid)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}