#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int sqrt_n;

bool block_divider(pair<pair<int, int>, int> &l, pair<pair<int, int>, int> &r) {
  auto left = l.first.first / sqrt_n;
  auto right = r.first.first / sqrt_n;
  if (left == right) return l.first.second < r.first.second;
  return left < right;
}

int main()
{
	FAST_IO
	int n,m,q;
	cin>>n>>m>>q;
	sqrt_n = floor(sqrt(n));
	string s;
	cin>>s;
	string t;
	cin>>t;
	if(m > n)
	{
		for (int i = 0; i < q; ++i)
		{
			cout << 0 << endl;
		}
		return 0;
	}
	vector <pair<pair<int, int>, int>> queries(q);
	vector <int> o(n,0);
	for (int i = 0; i < n; ++i)
	{
		if(s.substr(i,m) == t)
		{
			// dbg(i)
			o[i] = 1;
			o[i+m-1] = -1;
		}
	}
	for (int i = 0; i < q; ++i)
	{
		queries[i].second = i;
		cin>>queries[i].first.first>>queries[i].first.second;
		--queries[i].first.first;
    --queries[i].first.second;
	}
  sort(queries.begin(), queries.end(), block_divider);
	int answer = 0;
  int i = queries[0].first.first;
  int j = i-1;
  vector <int> ans(q);
  for (auto &q : queries) {
  	dbg(q.first.first)
  	dbg(q.first.second)
    while (q.first.first < i) {
      --i;
      if(o[i] == 1 && q.first.second - i >= m-1)
      	++answer;
    }
    while (q.first.first > i) {
      if(o[i] == 1)
      	--answer;
      ++i;
    }
    while (q.first.second > j) {
      ++j;
          	dbg(j)
    	dbg(o[j])
      if(o[j] == -1 && j - q.first.first >= m-1)
      	++answer;
    }
    while (q.first.second < j) {
      if(o[j] == -1)
      	--answer;
      --j;
    }
    ans[q.second] = answer;
  }
  for(int &x : ans)
  	cout << x << '\n';
	return 0;
}