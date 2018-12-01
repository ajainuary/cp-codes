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
	vector <bool> t(1000, false);
	for (int i = 0,l,r; i < n; ++i)
	{
		cin>>l>>r;
		for (int j = l; j <= r; ++j)
		{
			t[j] = true;
		}
	}
	int k = 0;
	for (int i = 1; i <= m; ++i)
	{
		if(!t[i])
			++k;
	}
	cout << k << endl;
	for (int i = 1; i <= m; ++i)
	{
		if(!t[i])
			cout << i << ' ';
	}
	return 0;
}