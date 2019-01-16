#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
	FAST_IO
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <vector <int>> G(n+1);
		for (int i = 1, u, v; i < n; ++i)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
	}
	return 0;
}