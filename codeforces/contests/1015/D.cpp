#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	long long int n,k,s;
	cin>>n>>k>>s;
	vector <int> h(k);
	int i = 0;
	h[0] = 1;
	while(i <= k && s >= n-1 && s-n+1 > k-(i+1))
	{
		s-=n-1;
		if(h[i] == 1)
			h[i+1] = n-1;
		else
			h[i+1] = 1;
		i++;
	}
	if(i > k)
	{
		cout << "NO\n";
		return 0;
	}
	else
	{
		cout << "YES\n";
	}
	if(s-n+1 < k-(i+1))
	{
		long long int d = s / (k-1);
	long long int e = s % (k-1);
	}
	if(h[i] == 1)
	{
		h[i+1] = h[i] + s;
	}
	else
	{
		h[i+1] = h[i] - s;
	}
	++i;
	for (int j = 1; j < i; ++j)
	{
		
	}
	return 0;
}