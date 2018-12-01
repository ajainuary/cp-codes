#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	long long int n;
	cin >> n;
	long long int max = INT_MIN;
	for (long long int i = 0,x,y; i < n; ++i)
	{
		cin >> x >> y;
		long long int dist = x + y;
		if(dist > max)
			max = dist;
	}
	cout << max << '\n';
	return 0;
}