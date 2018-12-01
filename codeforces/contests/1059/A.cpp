#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,L,a;
	cin >> n >> L >> a;
	long long int breaks = 0;
	int cl = 0;
	for (int i = 0,t,l; i < n; ++i)
	{
		cin >> t >> l;
		breaks += (t - cl) / a;
		cl = t+l;
	}
	breaks += (L-cl) / a;
	cout << breaks << '\n';
	return 0;
}