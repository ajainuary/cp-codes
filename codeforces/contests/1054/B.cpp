#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	cin >> n;
	vector <int> a(n);
	for(int &x : a) cin >> x;
	for (int i = 0,maxest=-1; i < n; ++i)
	{
		if(i != 0)
			maxest = max(maxest, a[i-1]);
		if(a[i] > maxest+1)
		{
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}