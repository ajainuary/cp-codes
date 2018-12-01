#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,k;
	cin>>n>>k;
	vector <long double> a(n);
	for(auto &x : a)
		cin>>x;
	vector <long double> max(n+1, INT_MIN);
	for(int l = k; l < n+1; ++l)
	{
		int i = 0;
		int j = 0;
		long double sum = 0;
		for(;j < l; ++j)
			sum += a[j];
		if(sum > max[l])
			max[l] = sum;
		
		while(j < n)
		{
			sum -= a[i];
			sum += a[j];
			++i;
			++j;
			if(sum > max[l])
				max[l] = sum;
		}
	}
	long double maxx = INT_MIN;
	for(int i = 1; i <= n; ++i)
	{
		long double tmp = max[i] / i;
		if(tmp > maxx)
			maxx = tmp;
	}
	cout.precision(20);
	cout << maxx << endl;
	return 0;
}