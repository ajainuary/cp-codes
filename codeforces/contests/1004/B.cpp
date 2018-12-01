#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,m;
	cin>>n>>m;
	for(int i = 0,x,y; i < m; ++i)
	{
		cin>>x>>y;
	}
	for(int i = 0; i < n; ++i)
	{
		cout<< i % 2;
	}
	cout << endl;
	return 0;
}