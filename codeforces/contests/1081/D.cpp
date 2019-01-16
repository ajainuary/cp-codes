#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define trace(c,x) for(auto &x:c)
array <pair<int, int>, 100005> spl;
void DFS(int v, vector <vector <pair<int, int>>> &G, vector <bool> &isSpecial)
{
	if(spl[v].second != 0)
		return;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	for(auto &x : G[v])
	{
		DFS(x.second, G, isSpecial);
		if(isSpecial[x.second])
			Q.push({x.second, x.first});
		Q.push({spl[x.second].second, max(x.first, spl[x.second].first)});
	}
	while(!Q.empty())
	{
		auto x = Q.top();
		if(x.first != spl[v].second && x.second > spl[v].first)
			spl[v].second = x.first;
		Q.pop();
	}
	return;
}

int main() {
	FAST_IO
	int n,m,k;
	cin >> n >> m >> k;
	vector <bool> isSpecial(n, false);
	for (int i = 0,x; i < k; ++i)
	{
		cin >> x;
		isSpecial[x] = true;
	}
	vector <vector <pair<int, int>>> G(n+2);
	for (int i = 0,u,v,w; i < m; ++i)
	{
		cin >> u >> v >> w;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
	DFS(1, G, isSpecial);
	for (int i = 1; i <= n; ++i)
	{
		if(isSpecial[i])
			cout << spl[i].second << ' ';
	}
	cout << endl;
	return 0;
}