#include <bits/stdc++.h>
using namespace std;
array <vector <int>, 5003> G;
vector <bool> visited(5003, false);
vector <int> dsu(5003, -1);
void dfs(int v, int parent)
{
	if(!visited[v])
	{
		// cerr << v << ' ' << parent << endl;
		visited[v] = true;
		if(dsu[v] < 0)
			dsu[v] = parent;
		for(int &x : G[v])
			dfs(x, v);
	}
	return;
}
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for (int i = 0,u,v; i < m; ++i)
	{
		cin>>u>>v;
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
	{
		dfs(i, -1);
	}
	int road=0;
	for (int i = 1; i <= n; ++i)
	{
		// cerr << i << ' ' << dsu[i] << endl;
		if(dsu[i] < 0)
			++road;
	}
	cout << road - 1 << endl;
	return 0;
}