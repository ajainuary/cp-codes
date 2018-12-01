#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	cin>>n;
	vector <bool> h(n+1,false);
	vector <int> p(n+1);
	for (int i = 1; i <= n; ++i)
		cin>>p[i];
	for (int i = 1; i <= n; ++i)
	{
		int j = i;
		while(h[j] != true)
		{
			h[j] = true;
			j = p[j];
		}
		cout << j << ' ';
		for (int k = 0; k < n+1; ++k)
		{
				h[k] = false;
		}
	}
	return 0;
}