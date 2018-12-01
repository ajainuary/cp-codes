#include <bits/stdc++.h>
using namespace std;

vector <int> cache(100005,-1);

int max_dist(vector <pair<int, int>> &dist, vector <pair<int, int>>::iterator i, int k)
{
	if(i == dist.end()-1)
		return 0;

	if(cache[i->second] != -1)
		return cache[i->second];

	int next = (i+1)->first - i->first;
	cache[i->second] = (next > k) ? 0 : max_dist(dist, i+1, k) + next;
	return cache[i->second];
}

int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	vector <int> X(n);
	vector <pair<int, int>> dist(n);
	for (int i = 0,d; i < n; ++i)
	{
		cin>>d;
		X[i] = d;
		dist[i] = make_pair(d, i);
	}
	sort(dist.begin(), dist.end());
	for (int i = 0,a,b; i < p; ++i)
	{
		cin>>a>>b;
		--a,--b;
		int s = (X[a] < X[b]) ? a : b;
		int e = (X[a] < X[b]) ? b : a;
		auto s_index = lower_bound(dist.begin(), dist.end(), make_pair(X[s], s));
		if(max_dist(dist, s_index, k) < X[e] - X[s])
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	return 0;
}