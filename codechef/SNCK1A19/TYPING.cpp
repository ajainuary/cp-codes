#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I, A, B) for (long long i = I; i < A; i += B)
#define rep(I, A, B) for (long long j = I; j <= A; j += B)
#define repp(I, A, B) for (long long j = I; j >= A; j -= B)
#define str(A) for (long long k = 0; A[k] != '\0'; k++)
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
vector<int> adj[100001];
bool visit[100001];
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, i;
  cin >> n;
  rep(1, n, 1) {
  	map<string, int> m;
    int p;
    cin >> p;
    string s;
    ll val = 0;
    FOR(0, p, 1) {
      cin >> s;
      char cur;
      if (m[s] == 0) {
        ll ans = 0;
        str(s) {
          if (k == 0)
            ans += 2;
          else {
            if ((cur == 'f' && s[k] == 'd') || (cur == 'd' && s[k] == 'f') ||
                (cur == 'j' && s[k] == 'k') || (cur == 'k' && s[k] == 'j') ||
                cur == s[k])
              ans += 4;
            else
              ans += 2;
          }
          cur = s[k];
        }
        // cout<<ans<<endl;
        m[s] = ans;
        val += ans;
      } else
        val += m[s] / 2;
    }
    cout << val << endl;
  }
  return 0;
}