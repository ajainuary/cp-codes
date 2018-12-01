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
	long long int l=1,r=n-1;
	long long int mid;
	while(l!=r)
	{
	 mid = (l+r)>>1;
	 if(s == mid * k)
	 	break;
		if(s-mid*(k-1) > mid)
			l = mid+1;
		else if(s - mid*(k-1) <= 0)
			r=mid-1;
		else
			l = mid+1;
	}
	mid = (l+r)>>1;
	if(s-mid*(k-1) > n-1 || s - mid*(k-1) < 0)
	{
		cout << "NO\n";
		return 0;
	}
	else
		cout << "YES\n";
	vector <int> h(k+1);
	int i = 0;
	h[0] = 1;
	while(i <= k && s >= mid)
	{
		s-=mid;
		if(h[i] == 1)
			h[i+1] = mid+1;
		else
			h[i+1] = 1;
		i++;
	}
	if(s > 0)
	{
		if(h[i] == 1)
	{
		h[i+1] = h[i] + s;
	}
	else
	{
		h[i+1] = h[i] - s;
	}
	++i;
	}
	for (int j = 1; j <= i; ++j)
	{
		cout << h[j] << ' ';
	}
	return 0;
}